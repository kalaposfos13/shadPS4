// SPDX-FileCopyrightText: Copyright 2026 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#if defined(__x86_64__)
asm(".att_syntax prefix");
#endif

#if defined(__x86_64__)

asm(R"(
.global _runOnAnotherStack
.type _runOnAnotherStack, @function
_runOnAnotherStack:
  # Save everything we need
  pushq %rbp
  pushq %rbx
  pushq %r12
  pushq %r13
  pushq %r14
  pushq %r15
  
  movq %rsp, %r12  # Save old stack pointer
  
#ifdef _WIN32
  movq %gs:0x08, %r13
  movq %gs:0x10, %r14
  xorq %r15, %r15
  movq %r15, %gs:0x08
  movq %r15, %gs:0x10
#endif
  
  # Switch to new stack
  movq %rdx, %rsp
  
  # Align and make room for a proper frame
  andq $-16, %rsp
  subq $16, %rsp   # Make room for frame
  
  # Set up a frame that looks like a normal function call
  movq $0, 8(%rsp)     # No previous frame
  movq %rsp, %rbp      # Set frame pointer
  movq $0, 0(%rsp)     # Clear return address slot
  
  # Call the actual function
  callq *%rsi
  
  # Save return
  movq %rax, %rbx
  
  # Restore
  movq %r12, %rsp
  
#ifdef _WIN32
  movq %r13, %gs:0x08
  movq %r14, %gs:0x10
#endif
  
  movq %rbx, %rax
  
  popq %r15
  popq %r14
  popq %r13
  popq %r12
  popq %rbx
  popq %rbp
  ret
.size _runOnAnotherStack, .-_runOnAnotherStack
)");

#endif
