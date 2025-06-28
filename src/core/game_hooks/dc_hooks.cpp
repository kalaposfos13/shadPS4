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

u64 SHAD_NO_INLINE PS4_SYSV_ABI HOOK_QueryHeapSize(u8* searched_array_struct, char* name) {
    LOG_INFO(Core_Hooking, "struct ptr: {}, searched name: {}, flags: {}",
             fmt::ptr(searched_array_struct), name, *(searched_array_struct + 4));
    if (strcmp(name, "editor") == 0 || strcmp(name, "extraEditorMemForGameHeap") == 0 ||
        strcmp(name, "DebugHeap") == 0) {
        int a = 0;
    }
    u64* searched_array = *(u64**)(searched_array_struct + 0x820);
    u32 array_size = *(u32*)(searched_array_struct + 0x818);

    // prints out the list of heap struct data
    // for (int i = 0; i < array_size; i++) {
    //     u64* heap_info = searched_array + (i * 9);
    //     LOG_INFO(Core_Hooking, "------ Heap {} data ------", i);
    //     LOG_INFO(Core_Hooking, "Name: {}", (char*)heap_info[0]);
    //     LOG_INFO(Core_Hooking, "Base size: {:#x}", heap_info[1]);
    //     for (int i = 2; i < 9; i++) {
    //         LOG_INFO(Core_Hooking, "Part {}: {:#x}", i, heap_info[i]);
    //     }
    // }

    u64 index = (u64)array_size;
    u64* element_ptr = searched_array;
    u64 binary_search_local;
    while (binary_search_local = index, 0 < (long)binary_search_local) {
        index = (long)binary_search_local / 2;
        // LOG_INFO(Core_Hooking, "Comparing \"{}\" to {}", (char*)element_ptr[index * 9], name);
        s32 iVar2 = strcmp((char*)element_ptr[index * 9], name);
        if (iVar2 < 0) {
            element_ptr = element_ptr + index * 9 + 9;
            index = (binary_search_local - 1) - index;
        }
    }
    u64 ret = 0;
    if (element_ptr != searched_array + (ulong)array_size * 9) {
        // LOG_INFO(Core_Hooking, "Search stopped at {}", (char*)*element_ptr);
        LOG_INFO(Core_Hooking, "Heap struct name: {}", (char*)element_ptr[0]);
        LOG_INFO(Core_Hooking, "Heap struct base size: {:#x}", element_ptr[1]);
        for (int i = 2; i < 9; i++) {
            LOG_INFO(Core_Hooking, "Heap struct part {}: {:#x}", i, element_ptr[i]);
        }
        if (strcmp(name, (char*)*element_ptr) == 0) {
            ret = element_ptr[1];
            u8 flags = *(searched_array_struct + 4);
            if ((flags & 1) != 0) {
                ret = ret + element_ptr[2];
            }
            if ((flags & 2) != 0) {
                ret = ret + element_ptr[3];
            }
            if ((flags & 4) != 0) {
                ret = ret + element_ptr[4];
            }
            if ((flags & 8) != 0) {
                ret = ret + element_ptr[5];
            }
        }
    }
    // LOG_INFO(Core_Hooking, "Predicted return: {:#x}", ret);

    auto orig =
        (u64 PS4_SYSV_ABI (*)(u8*, char*))_SearchAndDoSomethingToMemoryByName_hook.Trampoline;
    ret = orig(searched_array_struct, name);
    LOG_INFO(Core_Hooking, "Return: {:#x}", ret);
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
                   (void*)&HOOK_QueryHeapSize);
    EnableHook(&_SearchAndDoSomethingToMemoryByName_hook);

    initted = true;
}

} // namespace DCHooks