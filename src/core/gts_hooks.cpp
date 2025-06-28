// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later


#include "core/gts_hooks.h"
#include "core/linker.h"
#include "core/LightHook.h"
#include "common/singleton.h"
// #include "common/version.h"
#include "core/file_format/psf.h"

#include <map>

namespace GTSHooks {

static u64 EBOOT_MODULE_BASE;
static bool initted = false;

constexpr auto GTS_PDI_PDISTD_logger_LoggerOutputNull_print = 0x264F1B8;
constexpr auto GTS_PDI_PrintTarget_vtable = 0x263D188;
constexpr auto GTS_PDI_vsprintf = 0xB810B0;
constexpr auto GTS_prln = 0xDD4A90;
constexpr auto GTS_release_prln = 0xDD45E0;
constexpr auto GTS_FileDeviceGTFS_openFile = 0xB6FBF0;
constexpr auto GTS_AdhocCrashHandler = 0x1A4940;
constexpr auto GTS_hThread_exec0 = 0xD77560;
constexpr auto GTS_hSymbol_getOrAdd = 0xDA9BD0;
constexpr auto GTS_hObject_call = 0xD37DA0;
constexpr auto GTS_hFunctionObject_call = 0xD0C520;
constexpr auto GTS_hMethodObject_call = 0xD1E280;

static HookInformation _prlnHook = {};
static HookInformation _releasePrlnHook = {};
static HookInformation _gtfsOpenFileHook = {};
static HookInformation _adhocCrashHandlerHook = {};
static HookInformation _hThread_exec0Hook = {};
static HookInformation _hSymbol_getOrAddHook = {};
static HookInformation _hObject_callHook = {};
static HookInformation _hFunctionObject_callHook = {};
static HookInformation _hMethodObject_callHook = {};


static void PS4_SYSV_ABI GTSLogger(void* logger, char* fileName, int lineNumber, int type, int unk,
                                   char* format, void* args) {
    u8 buffer[1024];
    PrintTarget target = {.vtable = EBOOT_MODULE_BASE + GTS_PDI_PrintTarget_vtable,
                          .buffer = buffer,
                          .bufferSize = 1024};

    auto func = (int PS4_SYSV_ABI (*)(PrintTarget*, char*, void*))(EBOOT_MODULE_BASE + GTS_PDI_vsprintf);
    int ret = func(&target, format, args);

    LOG_INFO(Core_Linker, "{}", std::string_view(reinterpret_cast<char*>(buffer), ret));
}
void SHAD_NO_INLINE PS4_SYSV_ABI HOOK_prln(void* a1, int argCount, hObject** objects) {
    char* outStr = {};
    objects[0]->vt->rc_class(&outStr, objects[0]);

    LOG_INFO(Core_Linker, "{}", outStr);
}

u64 SHAD_NO_INLINE PS4_SYSV_ABI HOOK_GTS_FileDeviceGTFS_openFile(void* this_, char* fileName, void* PDIEXT__SimpleFileObject) {
    LOG_INFO(Core_Linker, "{}", fileName);
    auto orig = (u64 PS4_SYSV_ABI(*)(void*, char*, void*))_gtfsOpenFileHook.Trampoline;
    return orig(this_, fileName, PDIEXT__SimpleFileObject);
}

u64 SHAD_NO_INLINE PS4_SYSV_ABI HOOK_AdhocCrashHandler(char* message) {
    LOG_INFO(Core_Linker, "{}", message);
    auto orig = (u64 PS4_SYSV_ABI(*)(char*))_adhocCrashHandlerHook.Trampoline;
    return orig(message);
}

u64 SHAD_NO_INLINE PS4_SYSV_ABI HOOK_hThread_exec0(hThread* thread) {
    auto orig = (u64 PS4_SYSV_ABI(*)(hThread*))_hThread_exec0Hook.Trampoline;
    auto res_state = orig(thread);

    if (thread->source_file_name) {
        LOG_INFO(Core_Linker, "hThread::exec0: {}:{} (state: {})", thread->source_file_name,
                 thread->field_0x2C, res_state);
    }

    return res_state;
}

u64 SHAD_NO_INLINE PS4_SYSV_ABI HOOK_hSymbol_getOrAdd(void* list, char** name) {
    auto orig = (u64 PS4_SYSV_ABI(*)(void*, char**))_hSymbol_getOrAddHook.Trampoline;
    auto ret = orig(list, name);

    if (((int*)name)[3] != 0) {
        std::string str(*name);

    }

    return ret;
}

// Hooks ALL call (hObject::call)
u64 SHAD_NO_INLINE PS4_SYSV_ABI HOOK_hObject_call(hObject* this_, hThread** thread, int numArgs, hObject** args) {

    hThread* threadObj = *thread;

    char* funcObjName = {};
    this_->vt->toString(&funcObjName, this_);
    LOG_INFO(Core_Linker, "ADHOC CALL {}:{} -> {}", threadObj->source_file_name, threadObj->source_line_number, funcObjName);

    auto orig =(u64 PS4_SYSV_ABI(*)(hObject*, hThread**, int, hObject**))_hObject_callHook.Trampoline;
    auto ret = orig(this_, thread, numArgs, args);

    return ret;
}

// Hook all function calls (hFunctionObject overrides hObject::call)
u64 SHAD_NO_INLINE PS4_SYSV_ABI HOOK_hFunctionObject_call(hObject* this_, hThread** thread, int numArgs, hObject** args) {

    hThread* threadObj = *thread;

    char* funcObjName = {};
    this_->vt->toString(&funcObjName, this_);
    LOG_INFO(Core_Linker, "ADHOC CALL {}:{} -> {}",
             threadObj->source_file_name ? threadObj->source_file_name : "no file",
             threadObj->source_line_number, funcObjName);

    auto orig = (u64 PS4_SYSV_ABI(*)(hObject*, hThread**, int, hObject**))_hFunctionObject_callHook.Trampoline;
    auto ret = orig(this_, thread, numArgs, args);

    return ret;
}

// Hook all method calls (hMethodObject overrides hObject::call)
u64 SHAD_NO_INLINE PS4_SYSV_ABI HOOK_hMethodObject_call(hObject* this_, hThread** thread,
                                                                int numArgs, hObject** args) {
    hThread* threadObj = *thread;

    char* funcObjName = {};
    this_->vt->toString(&funcObjName, this_);
    LOG_INFO(Core_Linker, "ADHOC CALL {}:{} -> {}",
             threadObj->source_file_name ? threadObj->source_file_name : "no file",
             threadObj->source_line_number, funcObjName);

    auto orig = (u64 PS4_SYSV_ABI(*)(hObject*, hThread**, int,
                                     hObject**))_hMethodObject_callHook.Trampoline;
    auto ret = orig(this_, thread, numArgs, args);

    return ret;
}

void Initialize(Core::Module* mainModule) {

    if (initted)
        return;

    EBOOT_MODULE_BASE = mainModule->GetBaseAddress();

    _prlnHook = CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE + GTS_prln), (void*)&HOOK_prln);                                                   EnableHook(&_prlnHook);
    _releasePrlnHook = CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE + GTS_release_prln), (void*)&HOOK_prln);                                    EnableHook(&_releasePrlnHook);
    //_gtfsOpenFileHook = CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE + GTS_FileDeviceGTFS_openFile), &HOOK_GTS_FileDeviceGTFS_openFile); EnableHook(&_gtfsOpenFileHook);

    // We hook this incase the adhoc crash handler crashes. This can happen early during boot 
    _adhocCrashHandlerHook = CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE + GTS_AdhocCrashHandler), (void*)&HOOK_AdhocCrashHandler);            EnableHook(&_adhocCrashHandlerHook);
    //_hThread_exec0Hook = CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE + GTS_hThread_exec0), &HOOK_hThread_exec0);            EnableHook(&_hThread_exec0Hook);
    //_hSymbol_getOrAddHook = CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE + GTS_hSymbol_getOrAdd), &HOOK_hSymbol_getOrAdd);            EnableHook(&_hSymbol_getOrAddHook);

    // Adhoc call loggers
    //_hObject_callHook = CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE + GTS_hObject_call), &HOOK_hObject_call);            EnableHook(&_hObject_callHook);
    //_hFunctionObject_callHook = CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE + GTS_hFunctionObject_call), &HOOK_hFunctionObject_call);            EnableHook(&_hFunctionObject_callHook);
    //_hMethodObject_callHook = CreateHook(reinterpret_cast<void*>(EBOOT_MODULE_BASE + GTS_hMethodObject_call), &HOOK_hMethodObject_call);            EnableHook(&_hMethodObject_callHook);

    u64* printFuncAddr = reinterpret_cast<u64*>(EBOOT_MODULE_BASE + GTS_PDI_PDISTD_logger_LoggerOutputNull_print);
    *printFuncAddr = reinterpret_cast<u64>(&GTSLogger);

    initted = true;
}

} // namespace GTSHooks