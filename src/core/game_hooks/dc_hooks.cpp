// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later


#include "core/game_hooks/gtscb_hooks.h"
#include "core/linker.h"
#include "core/game_hooks/LightHook.h"
#include "common/singleton.h"
// #include "common/version.h"
#include "core/file_format/psf.h"

#include <map>

namespace DCHooks {

static bool initted = false;
static u64 EBOOT_MODULE_BASE;
constexpr u64 GHIDRA_OFFSET_ADJUSTMENT = 0x00400000;

constexpr auto DC_DebugLog = 0x0126f1f0;
static HookInformation _DebugLog_hook = {};

void SHAD_NO_INLINE PS4_SYSV_ABI HOOK_DebugLog(void* a1) {

    LOG_INFO(Core_Linker, "{}", "test for hooking");
}

void Initialize(Core::Module* mainModule) {

    if (initted)
        return;

    EBOOT_MODULE_BASE = mainModule->GetBaseAddress();

    _DebugLog_hook = CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE - GHIDRA_OFFSET_ADJUSTMENT + DC_DebugLog), (void*)&HOOK_DebugLog); EnableHook(&_DebugLog_hook);

    initted = true;
}

} // namespace DCHooks