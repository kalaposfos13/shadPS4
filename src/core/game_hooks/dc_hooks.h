// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "core/linker.h"
#include "core/game_hooks/LightHook.h"
#include "common/types.h"

namespace DCHooks {

struct HeapMetadata {
    char* name;
    u64 base_size;
    u64 size_mod_1;
    u64 size_mod_2;
    u64 size_mod_3;
    u64 size_mod_4;
    u64 unk1;
    char* parent_heap_name;
    u64 unk2;
};

void Initialize(Core::Module* module);

} // namespace DCBHooks