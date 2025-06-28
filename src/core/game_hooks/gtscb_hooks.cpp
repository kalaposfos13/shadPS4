// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later


#include "core/game_hooks/gtscb_hooks.h"
#include "core/linker.h"
#include "core/game_hooks/LightHook.h"
#include "common/singleton.h"
// #include "common/version.h"
#include "core/file_format/psf.h"

#include <map>

namespace GTSCBHooks {

static bool initted = false;
static u64 EBOOT_MODULE_BASE;

constexpr auto GTSCB_prln = 0xB42420;
static HookInformation _prlnHook = {};

void SHAD_NO_INLINE PS4_SYSV_ABI HOOK_prln(void* a1) {

    LOG_INFO(Core_Linker, "{}", "a");
}

void Initialize(Core::Module* mainModule) {

    if (initted)
        return;

    EBOOT_MODULE_BASE = mainModule->GetBaseAddress();

    _prlnHook = CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE + GTSCB_prln), (void*)&HOOK_prln); EnableHook(&_prlnHook);

    initted = true;
}

} // namespace GTSCBHooks