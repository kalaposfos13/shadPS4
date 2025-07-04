// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "common/singleton.h"
#include "core/game_hooks/LightHook.h"
#include "core/game_hooks/dc_hooks.h"
#include "core/linker.h"
// #include "common/version.h"
#include "core/file_format/psf.h"
#include "core/libraries/kernel/memory.h"

#include <map>

namespace DCHooks {

#define HOOK_FUNC SHAD_NO_INLINE PS4_SYSV_ABI

static bool initted = false;
static u64 EBOOT_MODULE_BASE;
constexpr u64 GHIDRA_OFFSET_ADJUSTMENT = 0x00400000;

constexpr auto DebugLog_offset = 0x0126f1f0;
static HookInformation DebugLog_hook = {};

constexpr auto StubAfterBootstrap_offset = 0x0127b300;
static HookInformation StubAfterBootstrap_hook = {};

constexpr auto QueryHeapInfo_offset = 0x00968a30;
static HookInformation QueryHeapInfo_hook = {};

constexpr auto CallSetupMemory_offset = 0x0055ac70;
static HookInformation CallSetupMemory_hook = {};

constexpr auto SetupMemory_offset = 0x00a7ae70;
static HookInformation SetupMemory_hook = {};

constexpr auto FuncAfterLibtbb_offset = 0x00a62e90;
static HookInformation FuncAfterLibtbb_hook = {};

constexpr auto LoadAndStartModule_offset = 0x00baf2c0;
static HookInformation LoadAndStartModule_hook = {};

constexpr auto SearchFlagInGlobalArgv_offset = 0x00557830;
static HookInformation SearchFlagInGlobalArgv_hook = {};

bool HOOK_SearchFlagInGlobalArgv(char* flag) {
    LOG_WARNING(Core_Hooking, "Checked flag: {}", flag);
    auto orig = (bool PS4_SYSV_ABI (*)(char*))SearchFlagInGlobalArgv_hook.Trampoline;
    bool ret = orig(flag);
    LOG_INFO(Core_Hooking, "return: {}", ret);
    if (ret == true) {
        LOG_INFO(Core_Hooking, "patch works");
    }
    return ret;
}

bool HOOK_FUNC HOOK_LoadAndStartModule(u64 param_1) {
    LOG_INFO(Core_Hooking, "Not loading tbb library");
    return true;
}

s32 HOOK_FUNC HOOK_FuncAfterLibtbb() {
    auto orig = (s32 PS4_SYSV_ABI (*)())FuncAfterLibtbb_hook.Trampoline;
    return orig();
}

void HOOK_FUNC HOOK_DebugLog(void* a1) {
    LOG_INFO(Core_Hooking, "test for hooking");
}

bool HOOK_FUNC HOOK_StubAfterBootstrap(u8* _this, char* argv0) {
    HeapMetadata* searched_array = (HeapMetadata*)(_this + 0xc0 + 0x820);
    u32 array_size = *(u32*)(_this + 0xc0 + 0x818);
    LOG_INFO(Core_Hooking, "Start of printing heap info, base: {}", fmt::ptr(searched_array));

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
    LOG_INFO(Core_Hooking, "End of hooking into stubbed function for inspecting parameters");
    return true;
}

u64 HOOK_FUNC HOOK_CallSetupMemory(u8* _this) {
    HeapMetadata* searched_array = *(HeapMetadata**)(_this + 0x820);
    u32 array_size = *(u32*)(_this + 0x818);
    LOG_INFO(Core_Hooking, "Start of printing heap info, base: {}", fmt::ptr(searched_array));

    // prints out the list of heap struct data
    char *debugheap_str = nullptr, *mainheap_str = nullptr;
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
        // break;
    }
    LOG_INFO(Core_Hooking, "End of hooking into stubbed function for inspecting parameters");
    auto orig = (u64 PS4_SYSV_ABI (*)(u8*))CallSetupMemory_hook.Trampoline;
    auto ret = orig(_this);
    for (int i = 0; i < array_size; i++) {
        HeapMetadata& heap_info = searched_array[i];
        if (heap_info.parent_heap_name && strcmp(heap_info.parent_heap_name, "MainHeap") == 0) {
            // heap_info.base_size = 0x30000000;
            mainheap_str = heap_info.parent_heap_name;
        } else if (strcmp(heap_info.name, "debug_heap") == 0) {
            heap_info.base_size = 0x100000;
        } else if (strcmp(heap_info.name, "debug_memory") == 0) {
            heap_info.base_size = 0x100000;
        } else if (strcmp(heap_info.name, "editor") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
        } else if (strcmp(heap_info.name, "extraEditorForMsg") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
        } else if (strcmp(heap_info.name, "extraEditorForPart") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
        } else if (strcmp(heap_info.name, "extraEditorMemForGameHeap") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
        } else if (strcmp(heap_info.name, "extraEditorMemForMultiProcessorHeap") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
        } else if (strcmp(heap_info.name, "extraHotSwapMemForResourceSys") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
        } else if (strcmp(heap_info.name, "extra_stl_for_editor") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
        } else if (strcmp(heap_info.name, "TotalMainMemory") == 0) {
            heap_info.base_size = 0x30000000;
        }
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
        // break;
    }
    return ret;
}

u64 HOOK_FUNC HOOK_SetupMemory(u64 p1, u64 p2, u64 p3, u64 p4, u64 p5) {
    /*
    sceKernelAllocateDirectMemory(0,sceKernelGetDirectMemorySize(),DebugHeapSize,0x200000,0,&DebugHeapDmemStart);
    sceKernelMapDirectMemory(&DebugHeapPtr,DebugHeapSize,0x33,0,DebugHeapDmemStart,0x200000);
    sceKernelSetVirtualRangeName(DebugHeapPtr,DebugHeapSize,"DebugHeap");

    plVar7 = (long *)FUN_00a78b60("DebugHeap",1,0);
    (**(code **)(*plVar7 + 0xa0))(plVar7,DebugHeapSize,DebugHeapPtr,0,1,1);
    */
    auto orig = (u64 PS4_SYSV_ABI (*)(u64, u64, u64, u64, u64))SetupMemory_hook.Trampoline;
    return orig(p1, p2, p3, p4, p5);
}

u64 HOOK_FUNC HOOK_QueryHeapInfo(u8* searched_array_struct, char* name) {
    LOG_INFO(Core_Hooking, "struct ptr: {}, searched name: {}, flags: {}",
             fmt::ptr(searched_array_struct), name, *(searched_array_struct + 4));
    if (strcmp(name, "game") == 0) {
        int a = 0;
    }
    HeapMetadata* searched_array = *(HeapMetadata**)(searched_array_struct + 0x820);
    u32 array_size = *(u32*)(searched_array_struct + 0x818);

    // prints out the list of heap struct data
    char *debugheap_str = nullptr, *mainheap_str = nullptr;
    HeapMetadata* game_heap = nullptr;
    for (int i = 0; i < array_size; i++) {
        HeapMetadata& heap_info = searched_array[i];
        if (heap_info.parent_heap_name && strcmp(heap_info.parent_heap_name, "MainHeap") == 0) {
            // heap_info.base_size = 0x30000000;
            mainheap_str = heap_info.parent_heap_name;
        } else if (strcmp(heap_info.name, "debug_heap") == 0) {
            heap_info.base_size = 0x100000;
        } else if (strcmp(heap_info.name, "debug_memory") == 0) {
            heap_info.base_size = 0x100000;
        } else if (strcmp(heap_info.name, "game") == 0) {
            game_heap = &heap_info;
        } else if (strcmp(heap_info.name, "editor") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
            LOG_INFO(Core_Hooking, "spoofing editor");
        } else if (strcmp(heap_info.name, "extraEditorForMsg") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
        } else if (strcmp(heap_info.name, "extraEditorForPart") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
        } else if (strcmp(heap_info.name, "extraEditorMemForGameHeap") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
        } else if (strcmp(heap_info.name, "extraEditorMemForMultiProcessorHeap") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
        } else if (strcmp(heap_info.name, "extraHotSwapMemForResourceSys") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
        } else if (strcmp(heap_info.name, "extra_stl_for_editor") == 0) {
            heap_info.base_size = 0x100000;
            heap_info.parent_heap_name = mainheap_str;
        } else if (strcmp(heap_info.name, "TotalMainMemory") == 0) {
            heap_info.base_size = 0x30000000;
        } else if (heap_info.parent_heap_name && strcmp(heap_info.parent_heap_name,"MainHeap") == 0) {
            mainheap_str = heap_info.parent_heap_name;
        }
    }
    if (game_heap && strcmp(name, "game") == 0)
        game_heap->parent_heap_name = mainheap_str;

    u64 ret = 0;

    // auto index = array_size;
    // HeapMetadata* element_ptr = searched_array;
    // u64 binary_search_local = index;
    // while (binary_search_local = index, 0 < (long)binary_search_local) {
    //     index = (long)binary_search_local / 2;
    //     // LOG_INFO(Core_Hooking, "Comparing \"{}\" to {}", (char*)element_ptr[index * 9], name);
    //     s32 iVar2 = strcmp(element_ptr[index].name, name);
    //     if (iVar2 < 0) {
    //         element_ptr = element_ptr + index * 9 + 9;
    //         index = (binary_search_local - 1) - index;
    //     }
    // }
    // if (element_ptr != searched_array + (ulong)array_size * 9) {
    //     // LOG_INFO(Core_Hooking, "Search stopped at {}", (char*)*element_ptr);
    //     if (strcmp(name, "DebugHeap") == 0) {
    //         LOG_INFO(Core_Hooking, "Spoofing size");
    //         element_ptr->base_size = 0x30000000;
    //     } else if (strcmp(name, "editor") == 0 || strcmp(name, "extraEditorMemForGameHeap") == 0)
    //     {
    //         LOG_INFO(Core_Hooking, "Spoofing size");
    //         element_ptr->base_size = 0x1000000;
    //     }
    //     LOG_INFO(Core_Hooking, "Name: {}", element_ptr->name);
    //     LOG_INFO(Core_Hooking, "Base size: {:#x}", element_ptr->base_size);
    //     for (int i = 2; i < 7; i++) {
    //         // LOG_INFO(Core_Hooking, "Part {}: {:#x}", i, element_ptr[i]);
    //     }
    //     if (element_ptr->parent_heap_name) {
    //         LOG_INFO(Core_Hooking, "Parent heap: {}", element_ptr->parent_heap_name);
    //     } else {
    //         LOG_INFO(Core_Hooking, "Parent heap: {}", "null");
    //     }
    //     LOG_INFO(Core_Hooking, "Part 8: {:#x}", element_ptr->unk2);
    //     if (strcmp(name, element_ptr->name) == 0) {
    //         ret = element_ptr->base_size;
    //         u8 flags = *(searched_array_struct + 4);
    //         if ((flags & 1) != 0) {
    //             ret += element_ptr->size_mod_1;
    //         }
    //         if ((flags & 2) != 0) {
    //             ret += element_ptr->size_mod_2;
    //         }
    //         if ((flags & 4) != 0) {
    //             ret += element_ptr->size_mod_3;
    //         }
    //         if ((flags & 8) != 0) {
    //             ret += element_ptr->size_mod_4;
    //         }
    //     }
    // }
    // LOG_INFO(Core_Hooking, "Predicted return: {:#x}", ret);

    auto orig = (u64 PS4_SYSV_ABI (*)(u8*, char*))QueryHeapInfo_hook.Trampoline;
    ret = orig(searched_array_struct, name);
    LOG_INFO(Core_Hooking, "Return: {:#x}", ret);
    return ret;
}

void InitHook(HookInformation& hook, u64 offset, void* func) {
    hook = CreateHook(
        reinterpret_cast<void*>(EBOOT_MODULE_BASE - GHIDRA_OFFSET_ADJUSTMENT + offset), func);
    EnableHook(&hook);
}

void Initialize(Core::Module* mainModule) {

    if (initted)
        return;

    EBOOT_MODULE_BASE = mainModule->GetBaseAddress();

    // InitHook(DebugLog_hook, DebugLog_offset, (void*)&HOOK_DebugLog);
    InitHook(QueryHeapInfo_hook, QueryHeapInfo_offset, (void*)&HOOK_QueryHeapInfo);
    // InitHook(StubAfterBootstrap_hook, StubAfterBootstrap_offset,
    // (void*)&HOOK_StubAfterBootstrap);
    InitHook(CallSetupMemory_hook, CallSetupMemory_offset, (void*)&HOOK_CallSetupMemory);
    InitHook(SetupMemory_hook, SetupMemory_offset, (void*)&HOOK_SetupMemory);
    // InitHook(FuncAfterLibtbb_hook, FuncAfterLibtbb_offset, (void*)&HOOK_FuncAfterLibtbb);
    // InitHook(LoadAndStartModule_hook, LoadAndStartModule_offset,
    // (void*)&HOOK_LoadAndStartModule);
    // InitHook(SearchFlagInGlobalArgv_hook, SearchFlagInGlobalArgv_offset,
    //          (void*)&HOOK_SearchFlagInGlobalArgv);

    initted = true;
}

} // namespace DCHooks