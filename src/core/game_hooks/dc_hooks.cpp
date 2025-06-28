// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "common/singleton.h"
#include "core/game_hooks/LightHook.h"
#include "core/game_hooks/gtscb_hooks.h"
#include "core/linker.h"
// #include "common/version.h"
#include "core/file_format/psf.h"

#include <map>

namespace DCHooks {

static bool initted = false;
static u64 EBOOT_MODULE_BASE;
constexpr u64 GHIDRA_OFFSET_ADJUSTMENT = 0x00400000;

constexpr auto DC_DebugLog = 0x0126f1f0;
static HookInformation _DebugLog_hook = {};

constexpr auto DC_SearchAndDoSomethingToMemoryByName = 0x00968a30;
static HookInformation _SearchAndDoSomethingToMemoryByName_hook = {};

void SHAD_NO_INLINE PS4_SYSV_ABI HOOK_DebugLog(void* a1) {

    LOG_INFO(Core_Hooking, "test for hooking");
}

u64 SHAD_NO_INLINE PS4_SYSV_ABI HOOK_SearchAndDoSomethingToMemoryByName(u8* searched_array_struct,
                                                                        char* name) {
    LOG_INFO(Core_Hooking, "struct ptr: {}, searched name: {}", fmt::ptr(searched_array_struct),
             name);
    u64* searched_array = *(u64**)(searched_array_struct + 0x820);
    u32 array_size = *(u32*)(searched_array_struct + 0x818);

    u64 index = (u64)array_size;
    u64* element_ptr = searched_array;
    // for (int i = 0; i < array_size; i++) {
    //     LOG_INFO(Core_Hooking, " Heap name {}: {}", i, (char*)searched_array[i * 9]);
    // }
    /* binary search? */
    // u64 uVar4;
    // while (uVar4 = index, 0 < (long)uVar4) {
    //     index = (long)uVar4 / 2;
    //     LOG_INFO(Core_Hooking, "Comparing \"{}\" to {}", (char*)element_ptr[index * 9], name);
    //     s32 iVar2 = strcmp((char*)element_ptr[index * 9], name);
    //     if (iVar2 < 0) {
    //         element_ptr = element_ptr + index * 9 + 9;
    //         index = (uVar4 - 1) - index;
    //     }
    // }

    auto orig =
        (u64 PS4_SYSV_ABI (*)(u8*, char*))_SearchAndDoSomethingToMemoryByName_hook.Trampoline;
    u64 ret = orig(searched_array_struct, name);
    LOG_INFO(Core_Hooking, "ret: {:#x}", ret);
    // if (strcmp(name, "editor") == 0 || strcmp(name, "extraEditorMemForGameHeap") == 0) {
    //     return ret == 0 ? 0x100000 : ret;
    // } else if (strcmp(name, "DebugHeap") == 0) {
    //     return 0x2000000;
    // }
    return ret;
}

void Initialize(Core::Module* mainModule) {

    if (initted)
        return;

    EBOOT_MODULE_BASE = mainModule->GetBaseAddress();

    // _DebugLog_hook = CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE -
    // GHIDRA_OFFSET_ADJUSTMENT + DC_DebugLog), (void*)&HOOK_DebugLog);
    // EnableHook(&_DebugLog_hook);
    _SearchAndDoSomethingToMemoryByName_hook =
        CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE - GHIDRA_OFFSET_ADJUSTMENT +
                                           DC_SearchAndDoSomethingToMemoryByName),
                   (void*)&HOOK_SearchAndDoSomethingToMemoryByName);
    EnableHook(&_SearchAndDoSomethingToMemoryByName_hook);

    initted = true;
}

} // namespace DCHooks