// SPDX-FileCopyrightText: Copyright 2025 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#pragma clang optimize off

#include <cstring>
#include "common/arch.h"
#include "common/types.h"
#ifdef _WIN32
#include <malloc.h>
#endif

#if defined(ARCH_X86_64) || defined(__arm64__) || defined(__aarch64__)
extern "C" void* PS4_SYSV_ABI _runOnAnotherStack(void* arg, void* (*func)(void*),
                                                 void* stackb) asm("_runOnAnotherStack");
#else
void* PS4_SYSV_ABI _runOnAnotherStack(void* arg, void* func, void* stackb) {
    UNREACHABLE_MSG("_runOnAnotherStack not implemented on target architecture.");
}
#endif

namespace Libraries::Kernel {
struct Pthread;
extern thread_local Pthread* g_curthread;
}; // namespace Libraries::Kernel

namespace Xbyak {
class CodeGenerator;
}

namespace Libraries::Fiber {
struct OrbisFiberContext;
}

namespace Core {

union DtvEntry {
    std::size_t counter;
    u8* pointer;
};

struct Tcb {
    Tcb* tcb_self;
    DtvEntry* tcb_dtv;
    void* tcb_thread;
    void* tcb_spare[2];
    u64 tcb_canary;
    ::Libraries::Fiber::OrbisFiberContext* tcb_fiber;
};

void* GetHLEStack();
bool IsOnHLEStack();

#ifdef _WIN32
/// Gets the thread local storage key for the TCB block.
u32 GetTcbKey();
#endif

/// Sets the data pointer to the TCB block.
void SetTcbBase(void* image_address);

/// Retrieves Tcb structure for the calling thread.
Tcb* GetTcbBase();

/// Makes sure TLS is initialized for the thread before entering guest.
void InitializeTLS();

void SetTcbBaseForHLE(Libraries::Kernel::Pthread* thr);

template <auto f>
struct HostCallWrapperImpl;

template <typename T>
struct HLEResult {
    T result;
};
template <>
struct HLEResult<void> {};

template <class ReturnType, class... Args, PS4_SYSV_ABI ReturnType (*func)(Args...)>
struct HostCallWrapperImpl<func> {
    static ReturnType PS4_SYSV_ABI wrap(Args... args) {
        // Check if we're already on the HLE stack
        if (IsOnHLEStack()) {
            // Already on HLE stack, just call directly
            return func(args...);
        }

        struct Context {
            HLEResult<ReturnType> result;
            std::tuple<Args...> args;
            Libraries::Kernel::Pthread* curthread;
        };
        std::unique_ptr<Context> ctxp = std::make_unique<Context>();
        Context& ctx = *ctxp;

        ctx.args = {args...};
        ctx.curthread = Libraries::Kernel::g_curthread;

        auto hle_calling_func = [](void* p) -> void* {
            auto& c = *static_cast<Context*>(p);

            Libraries::Kernel::g_curthread = c.curthread;
            SetTcbBaseForHLE(c.curthread);

            if constexpr (std::is_void_v<ReturnType>) {
                std::apply(func, c.args);
            } else {
                c.result.result = std::apply(func, c.args);
            }
            c.curthread = Libraries::Kernel::g_curthread;
            return nullptr;
        };

        _runOnAnotherStack(&ctx, hle_calling_func, GetHLEStack());

        InitializeTLS();

        if constexpr (!std::is_void_v<ReturnType>) {
            return ctx.result.result;
        }
    }
};

#define HOST_CALL(func) (Core::HostCallWrapperImpl<func>::wrap)
#pragma clang optimize on

} // namespace Core
