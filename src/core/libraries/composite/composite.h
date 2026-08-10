// SPDX-FileCopyrightText: Copyright 2024-2026 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "common/types.h"

namespace Core::Loader {
class SymbolsResolver;
}

namespace Libraries::Composite {

s32 PS4_SYSV_ABI sceCompositorAllocateIndex();
s32 PS4_SYSV_ABI sceCompositorCheckCrash();
s32 PS4_SYSV_ABI sceCompositorCommandGpuPerfBegin();
s32 PS4_SYSV_ABI sceCompositorCommandGpuPerfEnd();
s32 PS4_SYSV_ABI sceCompositorCreateIndirectRenderTarget();
s32 PS4_SYSV_ABI sceCompositorDeleteIndirectRenderTarget();
s32 PS4_SYSV_ABI sceCompositorFlush();
s32 PS4_SYSV_ABI sceCompositorFlushWithRepeat();
s32 PS4_SYSV_ABI sceCompositorGetAnotherProcessSystemAddress();
s32 PS4_SYSV_ABI sceCompositorGetAnotherProcessSystemSize();
s32 PS4_SYSV_ABI sceCompositorGetAnotherProcessVideoAddress();
s32 PS4_SYSV_ABI sceCompositorGetAnotherProcessVideoSize();
s32 PS4_SYSV_ABI sceCompositorGetCanvasHandle();
s32 PS4_SYSV_ABI sceCompositorGetClientList();
s32 PS4_SYSV_ABI sceCompositorGetDmemOffset();
s32 PS4_SYSV_ABI sceCompositorGetDummyAddress();
s32 PS4_SYSV_ABI sceCompositorGetDummySize();
s32 PS4_SYSV_ABI sceCompositorGetRemainedCommandNum();
s32 PS4_SYSV_ABI sceCompositorGetRenderTargetResolution();
s32 PS4_SYSV_ABI sceCompositorGetSystemAddress();
s32 PS4_SYSV_ABI sceCompositorGetSystemSize();
s32 PS4_SYSV_ABI sceCompositorGetVideoAddress();
s32 PS4_SYSV_ABI sceCompositorGetVideoSize();
s32 PS4_SYSV_ABI sceCompositorHandleProcessEvents();
s32 PS4_SYSV_ABI sceCompositorInit();
s32 PS4_SYSV_ABI sceCompositorInitWithProcessOrder();
s32 PS4_SYSV_ABI sceCompositorInsertThreadTraceMarker();
s32 PS4_SYSV_ABI sceCompositorIsDebugCaptureEnabled();
s32 PS4_SYSV_ABI sceCompositorIsReady4K();
s32 PS4_SYSV_ABI sceCompositorLockCommandBuffer();
s32 PS4_SYSV_ABI sceCompositorMakeCanvasHandle();
s32 PS4_SYSV_ABI sceCompositorMapAnotherProcess();
s32 PS4_SYSV_ABI sceCompositorQuit();
s32 PS4_SYSV_ABI sceCompositorReleaseCommandBuffer();
s32 PS4_SYSV_ABI sceCompositorReleaseIndex();
s32 PS4_SYSV_ABI sceCompositorReleaseLocalStall();
s32 PS4_SYSV_ABI sceCompositorReserveCommandBuffer();
s32 PS4_SYSV_ABI sceCompositorResetZoomCommand();
s32 PS4_SYSV_ABI sceCompositorSetCompositeCanvasCommandInC();
s32 PS4_SYSV_ABI sceCompositorSetCursorImageAddress();
s32 PS4_SYSV_ABI sceCompositorSetDebugPositionCommand();
s32 PS4_SYSV_ABI sceCompositorSetEndOfFrameCommand();
s32 PS4_SYSV_ABI sceCompositorSetEventCommand();
s32 PS4_SYSV_ABI sceCompositorSetFlipCommand();
s32 PS4_SYSV_ABI sceCompositorSetGameSufaceControlCommand();
s32 PS4_SYSV_ABI sceCompositorSetGnmContextCommand();
s32 PS4_SYSV_ABI sceCompositorSetIndirectCanvasCommand();
s32 PS4_SYSV_ABI sceCompositorSetIndirectCompositionCommand();
s32 PS4_SYSV_ABI sceCompositorSetIndirectRenderTargetConfigCommand();
s32 PS4_SYSV_ABI sceCompositorSetInvisibleCanvasCommand();
s32 PS4_SYSV_ABI sceCompositorSetKeepDisplayBufferCommand();
s32 PS4_SYSV_ABI sceCompositorSetLocalStallCommand();
s32 PS4_SYSV_ABI sceCompositorSetMemoryCommand();
s32 PS4_SYSV_ABI sceCompositorSetMorpheusState();
s32 PS4_SYSV_ABI sceCompositorSetPatchCommand();
s32 PS4_SYSV_ABI sceCompositorSetPostEventCommand();
s32 PS4_SYSV_ABI sceCompositorSetRepeatCommand();
s32 PS4_SYSV_ABI sceCompositorSetResolutionCommand();
s32 PS4_SYSV_ABI sceCompositorSetSeparateContextCommand();
s32 PS4_SYSV_ABI sceCompositorSetSystemConfigWithMask();
s32 PS4_SYSV_ABI sceCompositorSetVideoOutMode();
s32 PS4_SYSV_ABI sceCompositorSetZoomCommand();
s32 PS4_SYSV_ABI sceCompositorSystemConfig();
s32 PS4_SYSV_ABI sceCompositorWaitEndOfRendering();
s32 PS4_SYSV_ABI sceCompositorWaitEvent();
s32 PS4_SYSV_ABI sceCompositorWaitPostEvent();
s32 PS4_SYSV_ABI sceCompsoitorGetGpuClock();
s32 PS4_SYSV_ABI sceCompsoitorGetProcessRenderingTime();
s32 PS4_SYSV_ABI sceCompsoitorGetRenderingTime();
s32 PS4_SYSV_ABI Func_2A9B92DC221C724C();
s32 PS4_SYSV_ABI Func_5D9CF2417E13E6DB();
s32 PS4_SYSV_ABI Func_A5E7CB11092CC77E();

void RegisterLib(Core::Loader::SymbolsResolver* sym);
} // namespace Libraries::Composite