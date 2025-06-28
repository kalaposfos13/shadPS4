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

constexpr auto DC_fun = 0x12345;
static HookInformation _fun_hook = {};

void SHAD_NO_INLINE PS4_SYSV_ABI HOOK_fun(void* a1) {

    LOG_INFO(Core_Linker, "{}", "a");
}

void Initialize(Core::Module* mainModule) {

    if (initted)
        return;

    EBOOT_MODULE_BASE = mainModule->GetBaseAddress();

    _fun_hook = CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE + DC_fun), (void*)&HOOK_fun); EnableHook(&_fun_hook);

    initted = true;
}

} // namespace DCHooks