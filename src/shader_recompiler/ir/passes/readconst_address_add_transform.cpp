// SPDX-FileCopyrightText: Copyright 2026 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "shader_recompiler/ir/ir_emitter.h"
#include "shader_recompiler/ir/program.h"

namespace Shader::Optimization {

void ReadConstAddressAddTransform(IR::Program& program) {
    // This handles the following pattern by combining the addition with the offset
    // %82 = IAdd32 %65, #28816
    // %83 = ULessThan32 %82, %65
    // %84 = SelectU32 %83, #1, #0
    // %85 = IAdd32 %66, %84
    // %86 = CompositeConstructU32x2 %82, %85
    // %87 = ReadConst (flags=0x0)  %86, #0
    for (auto& block : program.blocks) {
        for (auto& inst : block->Instructions()) {
            if (inst.GetOpcode() == IR::Opcode::ReadConst) {
                IR::Inst* addr = inst.Arg(0).InstRecursive();
                IR::Inst* hi = addr->Arg(1).TryInstRecursive();
                IR::Inst* lo = addr->Arg(0).TryInstRecursive();
                if (!hi || !lo) {
                    continue;
                }

                if (lo->GetOpcode() != IR::Opcode::IAdd32 ||
                    hi->GetOpcode() != IR::Opcode::IAdd32) {
                    continue;
                }

                IR::Value add_offset = lo->Arg(0);
                if (!add_offset.IsImmediate()) {
                    continue;
                }

                IR::Inst* sel = hi->Arg(1).TryInstRecursive();
                if (!sel || sel->GetOpcode() != IR::Opcode::SelectU32) {
                    continue;
                }

                IR::Value sel_true = sel->Arg(1);
                IR::Value sel_false = sel->Arg(2);
                if (!sel_true.IsImmediate() || !sel_false.IsImmediate() || sel_true.U32() != 1 ||
                    sel_false.U32() != 0) {
                    continue;
                }

                addr->SetArg(0, lo->Arg(0));
                addr->SetArg(1, hi->Arg(0));
                for (auto [user, operand] : addr->Uses()) {
                    ASSERT(user->GetOpcode() == IR::Opcode::ReadConst && operand == 0);
                    IR::IREmitter ir{*block, IR::Block::InstructionList::s_iterator_to(inst)};
                    IR::Value offset = user->Arg(1);
                    if (offset.IsImmediate()) {
                        user->SetArg(1, ir.Imm32(offset.U32() + (add_offset.U32() >> 2u)));
                    } else {
                        auto shift = ir.ShiftRightLogical(IR::U32(add_offset), ir.Imm32(2u));
                        auto add = ir.IAdd(IR::U32(offset), IR::U32(shift));
                        user->SetArg(1, add);
                    }
                }
            }
        }
    }
}

} // namespace Shader::Optimization