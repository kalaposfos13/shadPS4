// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "common/singleton.h"
#include "core/game_hooks/LightHook.h"
#include "core/game_hooks/dc_hooks.h"
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

constexpr auto DC_QueryHeapInfo = 0x00968a30;
static HookInformation _QueryHeapInfo_hook = {};

void SHAD_NO_INLINE PS4_SYSV_ABI HOOK_DebugLog(void* a1) {

    LOG_INFO(Core_Hooking, "test for hooking");
}

u64 SHAD_NO_INLINE PS4_SYSV_ABI HOOK_QueryHeapInfo(u8* searched_array_struct, char* name) {
    LOG_INFO(Core_Hooking, "struct ptr: {}, searched name: {}, flags: {}",
             fmt::ptr(searched_array_struct), name, *(searched_array_struct + 4));
    if (strcmp(name, "editor") == 0 || strcmp(name, "extraEditorMemForGameHeap") == 0 ||
        strcmp(name, "DebugHeap") == 0) {
        int a = 0;
    }
    HeapMetadata* searched_array = *(HeapMetadata**)(searched_array_struct + 0x820);
    u32 array_size = *(u32*)(searched_array_struct + 0x818);

    // prints out the list of heap struct data
    for (int i = 0; i < array_size; i++) {
        HeapMetadata heap_info = searched_array[i];
        fmt::println("------ Heap {} data ------", i);
        fmt::println("Name: {}", (char*)heap_info.name);
        fmt::println("Base size: {:#x}", heap_info.base_size);
        for (int i = 2; i < 7; i++) {
            // fmt::println("Part {}: {:#x}", i, heap_info[i]);
        }
        constexpr const char* noname = "null";
        if (heap_info.parent_heap_name) {
            fmt::println("Parent heap: {}", (char*)heap_info.parent_heap_name);
        } else {
            fmt::println("Parent heap: {}", "null");
        }
        fmt::println("Part 8: {:#x}", heap_info.unk2);
    }

    u64 index = (u64)array_size;
    HeapMetadata* element_ptr = searched_array;
    u64 binary_search_local;
    while (binary_search_local = index, 0 < (long)binary_search_local) {
        index = (long)binary_search_local / 2;
        // LOG_INFO(Core_Hooking, "Comparing \"{}\" to {}", (char*)element_ptr[index * 9], name);
        s32 iVar2 = strcmp(element_ptr[index].name, name);
        if (iVar2 < 0) {
            element_ptr = element_ptr + index * 9 + 9;
            index = (binary_search_local - 1) - index;
        }
    }
    u64 ret = 0;
    if (element_ptr != searched_array + (ulong)array_size * 9) {
        // LOG_INFO(Core_Hooking, "Search stopped at {}", (char*)*element_ptr);
        if (strcmp(name, "DebugHeap") == 0) {
            LOG_INFO(Core_Hooking, "Spoofing size");
            element_ptr->base_size = 0x30000000;
        } else if (strcmp(name, "editor") == 0 || strcmp(name, "extraEditorMemForGameHeap") == 0) {
            LOG_INFO(Core_Hooking, "Spoofing size");
            element_ptr->base_size = 0x1000000;
        }
        LOG_INFO(Core_Hooking, "Name: {}", element_ptr->name);
        LOG_INFO(Core_Hooking, "Base size: {:#x}", element_ptr->base_size);
        for (int i = 2; i < 7; i++) {
            // LOG_INFO(Core_Hooking, "Part {}: {:#x}", i, element_ptr[i]);
        }
        if (element_ptr->parent_heap_name) {
            LOG_INFO(Core_Hooking, "Parent heap: {}", element_ptr->parent_heap_name);
        } else {
            LOG_INFO(Core_Hooking, "Parent heap: {}", "null");
        }
        LOG_INFO(Core_Hooking, "Part 8: {:#x}", element_ptr->unk2);
        if (strcmp(name, element_ptr->name) == 0) {
            ret = element_ptr->base_size;
            u8 flags = *(searched_array_struct + 4);
            if ((flags & 1) != 0) {
                ret += element_ptr->size_mod_1;
            }
            if ((flags & 2) != 0) {
                ret += element_ptr->size_mod_2;
            }
            if ((flags & 4) != 0) {
                ret += element_ptr->size_mod_3;
            }
            if ((flags & 8) != 0) {
                ret += element_ptr->size_mod_4;
            }
        }
    }
    // LOG_INFO(Core_Hooking, "Predicted return: {:#x}", ret);

    auto orig = (u64 PS4_SYSV_ABI (*)(u8*, char*))_QueryHeapInfo_hook.Trampoline;
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
    _QueryHeapInfo_hook = CreateHook(
        reinterpret_cast<void*>(EBOOT_MODULE_BASE - GHIDRA_OFFSET_ADJUSTMENT + DC_QueryHeapInfo),
        (void*)&HOOK_QueryHeapInfo);
    EnableHook(&_QueryHeapInfo_hook);

    initted = true;
}

} // namespace DCHooks