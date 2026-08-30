// SPDX-FileCopyrightText: Copyright 2026 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "common/alignment.h"
#include "common/logging/log.h"
#include "core/libraries/composite/composite.h"
#include "core/libraries/error_codes.h"
#include "core/libraries/gnmdriver/gnmdriver.h"
#include "core/libraries/kernel/memory.h"
#include "core/libraries/libs.h"
#include "core/libraries/videoout/video_out.h"
#include "core/memory.h"
#include "video_core/amdgpu/liverpool.h"

extern std::unique_ptr<AmdGpu::Liverpool> liverpool;

namespace Libraries::Composite {

void* sce_compositor_system_address = nullptr;
size_t sce_compositor_system_size = 0;
void* sce_compositor_video_address = nullptr;
size_t sce_compositor_video_size = 0;

static s64 frame_id = 0;

s32 PS4_SYSV_ABI sceCompositorAllocateIndex() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return 1;
}

s32 PS4_SYSV_ABI sceCompositorCheckCrash() {
    // LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorCommandGpuPerfBegin() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorCommandGpuPerfEnd() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorCreateIndirectRenderTarget() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorDeleteIndirectRenderTarget() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorFlush() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    Libraries::VideoOut::sceVideoOutSubmitFlip(2, 0, 1, frame_id++);
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorFlushWithRepeat() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorGetAnotherProcessSystemAddress() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorGetAnotherProcessSystemSize() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorGetAnotherProcessVideoAddress() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorGetAnotherProcessVideoSize() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorGetCanvasHandle() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return 1;
}

s32 PS4_SYSV_ABI sceCompositorGetClientList() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorGetDmemOffset() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorGetDummyAddress() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorGetDummySize() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorGetRemainedCommandNum() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorGetRenderTargetResolution(s16* width, s16* height) {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    *width = 1920;
    *height = 1080;
    return ORBIS_OK;
}

void* PS4_SYSV_ABI sceCompositorGetSystemAddress() {
    LOG_ERROR(Lib_Composite, "called");
    return sce_compositor_system_address;
}

s32 PS4_SYSV_ABI sceCompositorGetSystemSize() {
    LOG_ERROR(Lib_Composite, "called");
    return sce_compositor_system_size;
}

void* PS4_SYSV_ABI sceCompositorGetVideoAddress() {
    LOG_ERROR(Lib_Composite, "called");
    return sce_compositor_video_address;
}

s32 PS4_SYSV_ABI sceCompositorGetVideoSize() {
    LOG_ERROR(Lib_Composite, "called");
    return sce_compositor_video_size;
}

s32 PS4_SYSV_ABI sceCompositorHandleProcessEvents() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

static Kernel::OrbisKernelEqueue composite_flip_queue;

s32 PS4_SYSV_ABI sceCompositorInit() {
    LOG_ERROR(Lib_Composite, "called");
    sce_compositor_system_address = nullptr;
    sce_compositor_video_address = nullptr;
    Libraries::Kernel::sceKernelMapNamedSystemFlexibleMemory(
        &sce_compositor_system_address, 512_MB, 0, std::to_underlying(Core::MemoryMapFlags::System),
        "sceComposite HLE buffer 1");
    sce_compositor_system_size = 512_MB;
    Libraries::Kernel::sceKernelMapNamedSystemFlexibleMemory(
        &sce_compositor_video_address, 1_GB, 0, std::to_underlying(Core::MemoryMapFlags::System),
        "sceComposite HLE buffer 2");
    sce_compositor_video_size = 1_GB;

    constexpr u32 sce_composite_color_width = 1920;
    constexpr u32 sce_composite_color_height = 1080;
    constexpr u32 color_target_size =
        Common::AlignUp(sce_composite_color_width * sce_composite_color_height * 4, 16_KB);

    using namespace VideoOut;
    using namespace Kernel;

    BufferAttribute attrib = {};
    sceVideoOutSetBufferAttribute(&attrib, PixelFormat::A8R8G8B8Srgb, (u32)TilingMode::Linear, 0,
                                  sce_composite_color_width, sce_composite_color_height,
                                  sce_composite_color_width);

    void* addrs[1] = {
        (void*)((VAddr)sce_compositor_video_address +
                0x7fc000)}; // offset is a hack, got it by checking the difference between the
                            // image address seen in rdoc and the base address of this allocation
    s32 video_out_handle =
        sceVideoOutOpen(Libraries::UserService::ORBIS_USER_SERVICE_USER_ID_SYSTEM, 0, 0, nullptr);

    int rc = sceKernelCreateEqueue(&composite_flip_queue, "composite flip queue");
    sceVideoOutAddFlipEvent(composite_flip_queue, video_out_handle, 0);

    sceVideoOutRegisterBuffers(video_out_handle, 0, addrs, 1, &attrib);
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorInitWithProcessOrder() {
    LOG_ERROR(Lib_Composite, "called");
    sceCompositorInit();
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorInsertThreadTraceMarker() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorIsDebugCaptureEnabled() {
    // LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorIsReady4K() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorLockCommandBuffer() {
    // LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorMakeCanvasHandle() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorMapAnotherProcess() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorQuit() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorReleaseCommandBuffer() {
    // LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorReleaseIndex() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorReleaseLocalStall() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorReserveCommandBuffer() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorResetZoomCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetCompositeCanvasCommandInC() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetCursorImageAddress() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetDebugPositionCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetEndOfFrameCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetEventCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetFlipCommand() {
    LOG_ERROR(Lib_Composite, "called");
    Libraries::VideoOut::sceVideoOutSubmitFlip(2, 0, 1, frame_id++);
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetGameSufaceControlCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

u32* compositor_dcb_gpu_addr = nullptr;
u32 compositor_dcb_size = 0;
s32 PS4_SYSV_ABI sceCompositorSetGnmContextCommand(u32* dcb_gpu_addr, u32 dcb_size,
                                                   u32* ccb_gpu_addr, u32 ccb_size) {
    LOG_ERROR(Lib_Composite, "called");
    compositor_dcb_gpu_addr = dcb_gpu_addr;
    compositor_dcb_size = dcb_size;
    return Libraries::GnmDriver::sceGnmSubmitCommandBuffers(
        1, (const u32**)&compositor_dcb_gpu_addr, &compositor_dcb_size, nullptr, nullptr);
}

s32 PS4_SYSV_ABI sceCompositorSetIndirectCanvasCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetIndirectCompositionCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetIndirectRenderTargetConfigCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetInvisibleCanvasCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetKeepDisplayBufferCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetLocalStallCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetMemoryCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetMorpheusState() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetPatchCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetPostEventCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetRepeatCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetResolutionCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetSeparateContextCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetSystemConfigWithMask() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetVideoOutMode() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSetZoomCommand() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorSystemConfig() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorWaitEndOfRendering() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorWaitEvent() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompositorWaitPostEvent() {
    LOG_ERROR(Lib_Composite, "called");
    while (!liverpool->IsGpuIdle())
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompsoitorGetGpuClock(u64* gpu_clock) {
    LOG_ERROR(Lib_Composite, "called");
    *gpu_clock = std::chrono::system_clock::now().time_since_epoch().count();
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompsoitorGetProcessRenderingTime() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceCompsoitorGetRenderingTime() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Func_2A9B92DC221C724C() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Func_5D9CF2417E13E6DB() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Func_A5E7CB11092CC77E() {
    LOG_ERROR(Lib_Composite, "(STUBBED) called");
    return ORBIS_OK;
}

s32 sceApplicationSetCanvasHandle(s16 param_1, s32 param_2) {
    LOG_ERROR(/*Sys*/ Core, "(STUBBED) called");
    return ORBIS_OK;
}

void RegisterLib(Core::Loader::SymbolsResolver* sym) {

    LIB_FUNCTION("qTHiabfEukw", "libSceSysCore", 1, "libSceSysCore", sceApplicationSetCanvasHandle);

    LIB_FUNCTION("G4Q8KNkb5XE", "libSceComposite", 1, "libSceComposite",
                 sceCompositorAllocateIndex);
    LIB_FUNCTION("9M7HkbwUs-E", "libSceComposite", 1, "libSceComposite", sceCompositorCheckCrash);
    LIB_FUNCTION("6bz4VVSSFyg", "libSceComposite", 1, "libSceComposite",
                 sceCompositorCommandGpuPerfBegin);
    LIB_FUNCTION("fH2IStnGK4M", "libSceComposite", 1, "libSceComposite",
                 sceCompositorCommandGpuPerfEnd);
    LIB_FUNCTION("meXSAmyPBUE", "libSceComposite", 1, "libSceComposite",
                 sceCompositorCreateIndirectRenderTarget);
    LIB_FUNCTION("wCqghwW7vQw", "libSceComposite", 1, "libSceComposite",
                 sceCompositorDeleteIndirectRenderTarget);
    LIB_FUNCTION("qZNF03+ghLI", "libSceComposite", 1, "libSceComposite", sceCompositorFlush);
    LIB_FUNCTION("9bnaeOBBD1Q", "libSceComposite", 1, "libSceComposite",
                 sceCompositorFlushWithRepeat);
    LIB_FUNCTION("ayhAQXdGNqU", "libSceComposite", 1, "libSceComposite",
                 sceCompositorGetAnotherProcessSystemAddress);
    LIB_FUNCTION("8bAq9t5kF9k", "libSceComposite", 1, "libSceComposite",
                 sceCompositorGetAnotherProcessSystemSize);
    LIB_FUNCTION("s-6xbR71jQI", "libSceComposite", 1, "libSceComposite",
                 sceCompositorGetAnotherProcessVideoAddress);
    LIB_FUNCTION("gbjddWAc6-o", "libSceComposite", 1, "libSceComposite",
                 sceCompositorGetAnotherProcessVideoSize);
    LIB_FUNCTION("N7PrM+lPMW0", "libSceComposite", 1, "libSceComposite",
                 sceCompositorGetCanvasHandle);
    LIB_FUNCTION("9vHGtqLkmTQ", "libSceComposite", 1, "libSceComposite",
                 sceCompositorGetClientList);
    LIB_FUNCTION("MjH7MOV6LVk", "libSceComposite", 1, "libSceComposite",
                 sceCompositorGetDmemOffset);
    LIB_FUNCTION("fcDt18r-ibY", "libSceComposite", 1, "libSceComposite",
                 sceCompositorGetDummyAddress);
    LIB_FUNCTION("F9gmz-sU-Z4", "libSceComposite", 1, "libSceComposite", sceCompositorGetDummySize);
    LIB_FUNCTION("2xhRHbvhwfU", "libSceComposite", 1, "libSceComposite",
                 sceCompositorGetRemainedCommandNum);
    LIB_FUNCTION("twGXom56jw0", "libSceComposite", 1, "libSceComposite",
                 sceCompositorGetRenderTargetResolution);
    LIB_FUNCTION("T6CVkdCDO7o", "libSceComposite", 1, "libSceComposite",
                 sceCompositorGetSystemAddress);
    LIB_FUNCTION("N6ID0KNnzY8", "libSceComposite", 1, "libSceComposite",
                 sceCompositorGetSystemSize);
    LIB_FUNCTION("bxt+muwit0w", "libSceComposite", 1, "libSceComposite",
                 sceCompositorGetVideoAddress);
    LIB_FUNCTION("FTQCTDU0b4g", "libSceComposite", 1, "libSceComposite", sceCompositorGetVideoSize);
    LIB_FUNCTION("f9X0imA90fI", "libSceComposite", 1, "libSceComposite",
                 sceCompositorHandleProcessEvents);
    LIB_FUNCTION("xIkcEpdMxrw", "libSceComposite", 1, "libSceComposite", sceCompositorInit);
    LIB_FUNCTION("IUlpGnuoR1c", "libSceComposite", 1, "libSceComposite",
                 sceCompositorInitWithProcessOrder);
    LIB_FUNCTION("-wIAG588mvg", "libSceComposite", 1, "libSceComposite",
                 sceCompositorInsertThreadTraceMarker);
    LIB_FUNCTION("q+Qw1ESxCj8", "libSceComposite", 1, "libSceComposite",
                 sceCompositorIsDebugCaptureEnabled);
    LIB_FUNCTION("RSEX1eS1tCI", "libSceComposite", 1, "libSceComposite", sceCompositorIsReady4K);
    LIB_FUNCTION("GgOrwi+9vcA", "libSceComposite", 1, "libSceComposite",
                 sceCompositorLockCommandBuffer);
    LIB_FUNCTION("4PTzGjEmkXI", "libSceComposite", 1, "libSceComposite",
                 sceCompositorMakeCanvasHandle);
    LIB_FUNCTION("mKEAx7QnPeg", "libSceComposite", 1, "libSceComposite",
                 sceCompositorMapAnotherProcess);
    LIB_FUNCTION("y5IJdPxdBrE", "libSceComposite", 1, "libSceComposite", sceCompositorQuit);
    LIB_FUNCTION("1OXbuWLRxqI", "libSceComposite", 1, "libSceComposite",
                 sceCompositorReleaseCommandBuffer);
    LIB_FUNCTION("ZwsBB3s8qMk", "libSceComposite", 1, "libSceComposite", sceCompositorReleaseIndex);
    LIB_FUNCTION("9zmcX1uKDGg", "libSceComposite", 1, "libSceComposite",
                 sceCompositorReleaseLocalStall);
    LIB_FUNCTION("7NxubT1-VV4", "libSceComposite", 1, "libSceComposite",
                 sceCompositorReserveCommandBuffer);
    LIB_FUNCTION("1PX0NFNL1BQ", "libSceComposite", 1, "libSceComposite",
                 sceCompositorResetZoomCommand);
    LIB_FUNCTION("gVoOE32ATg0", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetCompositeCanvasCommandInC);
    LIB_FUNCTION("OSqOny+kPrA", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetCursorImageAddress);
    LIB_FUNCTION("dHK+qu5D2HM", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetDebugPositionCommand);
    LIB_FUNCTION("m4cofzsxUWY", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetEndOfFrameCommand);
    LIB_FUNCTION("5fbNa7tkGoI", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetEventCommand);
    LIB_FUNCTION("1oTrw-ivVpA", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetFlipCommand);
    LIB_FUNCTION("n2XkxixrY2k", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetGameSufaceControlCommand);
    LIB_FUNCTION("DhtKelVAIaA", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetGnmContextCommand);
    LIB_FUNCTION("-zpfGY1n49E", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetIndirectCanvasCommand);
    LIB_FUNCTION("M6wp6+JUSRI", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetIndirectCompositionCommand);
    LIB_FUNCTION("kZ7Xre07w70", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetIndirectRenderTargetConfigCommand);
    LIB_FUNCTION("9sdvKfLR+mY", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetInvisibleCanvasCommand);
    LIB_FUNCTION("dIA+v-Lh1+o", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetKeepDisplayBufferCommand);
    LIB_FUNCTION("yW5gfrDFAoc", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetLocalStallCommand);
    LIB_FUNCTION("kn5tI0VFTVY", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetMemoryCommand);
    LIB_FUNCTION("H4EXZ9L3p2M", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetMorpheusState);
    LIB_FUNCTION("YzI2BOoDw+I", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetPatchCommand);
    LIB_FUNCTION("3Q85e5cS3e0", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetPostEventCommand);
    LIB_FUNCTION("fEQcEYs1yuU", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetRepeatCommand);
    LIB_FUNCTION("eLU8pDi9KN0", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetResolutionCommand);
    LIB_FUNCTION("5Z0YF3QKlhk", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetSeparateContextCommand);
    LIB_FUNCTION("dN3ooEQkn90", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetSystemConfigWithMask);
    LIB_FUNCTION("r0QtEP0p4Gs", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetVideoOutMode);
    LIB_FUNCTION("aroIog+umzo", "libSceComposite", 1, "libSceComposite",
                 sceCompositorSetZoomCommand);
    LIB_FUNCTION("WkdkfQun1gc", "libSceComposite", 1, "libSceComposite", sceCompositorSystemConfig);
    LIB_FUNCTION("R00q9P3BKAc", "libSceComposite", 1, "libSceComposite",
                 sceCompositorWaitEndOfRendering);
    LIB_FUNCTION("0wFl-CwJ37Y", "libSceComposite", 1, "libSceComposite", sceCompositorWaitEvent);
    LIB_FUNCTION("deKovf3qViA", "libSceComposite", 1, "libSceComposite",
                 sceCompositorWaitPostEvent);
    LIB_FUNCTION("4yWqjTZtvs4", "libSceComposite", 1, "libSceComposite", sceCompsoitorGetGpuClock);
    LIB_FUNCTION("EcTHemmz6n4", "libSceComposite", 1, "libSceComposite",
                 sceCompsoitorGetProcessRenderingTime);
    LIB_FUNCTION("rIH7UTXfho4", "libSceComposite", 1, "libSceComposite",
                 sceCompsoitorGetRenderingTime);
    LIB_FUNCTION("KpuS3CIcckw", "libSceComposite", 1, "libSceComposite", Func_2A9B92DC221C724C);
    LIB_FUNCTION("XZzyQX4T5ts", "libSceComposite", 1, "libSceComposite", Func_5D9CF2417E13E6DB);
    LIB_FUNCTION("pefLEQksx34", "libSceComposite", 1, "libSceComposite", Func_A5E7CB11092CC77E);
};

} // namespace Libraries::Composite