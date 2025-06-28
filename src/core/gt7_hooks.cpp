// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later


#include "core/gt7_hooks.h"
#include "core/linker.h"
#include "core/LightHook.h"
#include "common/singleton.h"
// #include "common/version.h"

#include <map>

namespace GT7Hooks {

static u64 EBOOT_MODULE_BASE;
static bool initted = false;

constexpr auto GT7_PDI_PDISTD_logger_LoggerOutputNull_print = 0x5C07258;
constexpr auto GT7_PDI_PrintTarget_vtable = 0x5C00260;
constexpr auto GT7_PDI_vsprintf = 0x3A4E740;

void PS4_SYSV_ABI GT7Logger(void* logger, void* a2, char* path, int lineNumber, int type, int a6,
                            char* format, char* vaList) {
    u8 buffer[1024];
    PrintTarget target = {.vtable = EBOOT_MODULE_BASE + GT7_PDI_PrintTarget_vtable,
                          .buffer = buffer,
                          .bufferSize = 1024};

    auto func =
        (int PS4_SYSV_ABI (*)(PrintTarget*, char*, void*))(EBOOT_MODULE_BASE + GT7_PDI_vsprintf);
    int ret = func(&target, format, vaList);

    LOG_INFO(Core_Linker, "{}", std::string_view(reinterpret_cast<char*>(buffer), ret));
}


void Initialize(Core::Module* mainModule) {

    if (initted)
        return;

    EBOOT_MODULE_BASE = mainModule->GetBaseAddress();

    u64* printFuncAddr = reinterpret_cast<u64*>(EBOOT_MODULE_BASE + GT7_PDI_PDISTD_logger_LoggerOutputNull_print);
    *printFuncAddr = reinterpret_cast<u64>(&GT7Logger);

    initted = true;
}
} // namespace GTHooks