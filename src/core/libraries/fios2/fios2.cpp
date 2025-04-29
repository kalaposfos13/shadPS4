// SPDX-FileCopyrightText: Copyright 2025 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include <mutex>
#include "common/logging/log.h"
#include "core/libraries/error_codes.h"
#include "core/libraries/fios2/fios2.h"
#include "core/libraries/fios2/fios2_error.h"
#include "core/libraries/kernel/file_system.h"
#include "core/libraries/libs.h"

namespace Libraries::Fios2 {

OrbisFiosOp op_count = 0;
std::unordered_map<OrbisFiosOp, s32> op_return_codes_map{};
std::unordered_map<OrbisFiosOp, OrbisFiosSize> op_io_return_codes_map{};

u8 PS4_SYSV_ABI sceFiosArchiveGetDecompressorThreadCount() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return 1;
}

OrbisFiosOp PS4_SYSV_ABI sceFiosArchiveGetMountBufferSize(const OrbisFiosOpAttr* pAttr,
                                                          const char* pArchivePath,
                                                          const OrbisFiosOpenParams* pOpenParams) {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    // code
    OrbisFiosOp op = ++op_count;
    op_return_codes_map.emplace(op, ORBIS_OK);
    return op;
}

s32 PS4_SYSV_ABI sceFiosArchiveGetMountBufferSizeSync(const OrbisFiosOpAttr* pAttr,
                                                      const char* pArchivePath,
                                                      const OrbisFiosOpenParams* pOpenParams) {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    OrbisFiosOp op = sceFiosArchiveGetMountBufferSize(pAttr, pArchivePath, pOpenParams);
    return sceFiosOpSyncWait(op);
}

OrbisFiosOp PS4_SYSV_ABI sceFiosArchiveMount(const OrbisFiosOpAttr* pAttr, OrbisFiosFH* pOutFH,
                                             const char* pArchivePath, const char* pMountPoint,
                                             OrbisFiosBuffer mountBuffer,
                                             const OrbisFiosOpenParams* pOpenParams) {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    OrbisFiosOp op = ++op_count;
    op_return_codes_map.emplace(op, ORBIS_OK);
    return op;
}

s32 PS4_SYSV_ABI sceFiosArchiveMountSync(const OrbisFiosOpAttr* pAttr, OrbisFiosFH* pOutFH,
                                         const char* pArchivePath, const char* pMountPoint,
                                         OrbisFiosBuffer mountBuffer,
                                         const OrbisFiosOpenParams* pOpenParams) {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    OrbisFiosOp op =
        sceFiosArchiveMount(pAttr, pOutFH, pArchivePath, pMountPoint, mountBuffer, pOpenParams);
    return sceFiosOpSyncWait(op);
}

OrbisFiosOp PS4_SYSV_ABI sceFiosArchiveMountWithOrder() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosArchiveMountWithOrderSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosArchiveMountWithOrder();
}

s32 PS4_SYSV_ABI sceFiosArchiveSetDecompressorThreadCount() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosArchiveUnmount() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosArchiveUnmountSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosCacheContainsFileRangeSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosCacheContainsFileSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosCacheFlushFileRangeSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosCacheFlushFileSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosCacheFlushSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosCachePrefetchFH() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosCachePrefetchFHRange() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosCachePrefetchFHRangeSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosCachePrefetchFHRange();
}

s32 PS4_SYSV_ABI sceFiosCachePrefetchFHSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosCachePrefetchFile() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosCachePrefetchFileRange() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosCachePrefetchFileRangeSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosCachePrefetchFileRange();
}

s32 PS4_SYSV_ABI sceFiosCachePrefetchFileSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosCachePrefetchFile();
}

s32 PS4_SYSV_ABI sceFiosCancelAllOps() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosClearTimeStamps() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosCloseAllFiles() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDateFromComponents() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDateGetCurrent() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDateToComponents() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDeallocatePassthruFH() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDebugDumpDate() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDebugDumpDH() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDebugDumpError() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDebugDumpFH() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDebugDumpOp() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDelete() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDeleteSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosDelete();
}

s32 PS4_SYSV_ABI sceFiosDHClose() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDHCloseSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosDHClose();
}

s32 PS4_SYSV_ABI sceFiosDHGetPath() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDHOpen() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDHOpenSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosDHOpen();
}

s32 PS4_SYSV_ABI sceFiosDHRead() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDHReadSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosDHRead();
}

s32 PS4_SYSV_ABI sceFiosDirectoryCreate() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDirectoryCreateSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosDirectoryCreate();
}

s32 PS4_SYSV_ABI sceFiosDirectoryCreateWithMode() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDirectoryCreateWithModeSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosDirectoryCreateWithMode();
}

s32 PS4_SYSV_ABI sceFiosDirectoryDelete() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDirectoryDeleteSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosDirectoryDelete();
}

bool PS4_SYSV_ABI sceFiosDirectoryExists() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

bool PS4_SYSV_ABI sceFiosDirectoryExistsSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosDirectoryExists();
}

s32 PS4_SYSV_ABI sceFiosDLLInitialize() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosDLLTerminate() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

OrbisFiosOp PS4_SYSV_ABI sceFiosExists(const OrbisFiosOpAttr* pAttr, const char* pPath) {
    LOG_WARNING(Lib_Fios2, "(DUMMY) called pAttr: {} path: {}", (void*)pAttr, pPath);

    Kernel::OrbisKernelStat st;
    bool exists = (Kernel::posix_stat(pPath, &st) == ORBIS_OK);
    OrbisFiosOp op = ++op_count;
    op_return_codes_map.emplace(op, exists ? 1 : 0); // 1 = true, 0 = false
    return op;
}

bool PS4_SYSV_ABI sceFiosExistsSync(const OrbisFiosOpAttr* pAttr, const char* pPath) {
    OrbisFiosOp op = sceFiosExists(pAttr, pPath);
    return static_cast<bool>(sceFiosOpSyncWait(op));
}

s32 PS4_SYSV_ABI sceFiosFHClose() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHCloseSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFHClose();
}

s32 PS4_SYSV_ABI sceFiosFHGetOpenParams() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHGetPath() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHGetSize() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

OrbisFiosOp PS4_SYSV_ABI sceFiosFHOpen(const OrbisFiosOpAttr* pAttr, OrbisFiosFH* pOutFH,
                                       const char* pPath, const OrbisFiosOpenParams* pOpenParams) {
    LOG_WARNING(Lib_Fios2, "(DUMMY) called");

    s32 open_flags = pOpenParams ? pOpenParams->openFlags : 0;
    s32 fd = Kernel::sceKernelOpen(pPath, open_flags, 0);
    if (fd < 0) {
        OrbisFiosOp op = ++op_count;
        op_return_codes_map.emplace(op, fd);
        return op;
    }

    *pOutFH = static_cast<OrbisFiosFH>(fd);
    OrbisFiosOp op = ++op_count;
    op_return_codes_map.emplace(op, ORBIS_OK);
    return op;
}

s32 PS4_SYSV_ABI sceFiosFHOpenSync(const OrbisFiosOpAttr* pAttr, OrbisFiosFH* pOutFH,
                                   const char* pPath, const OrbisFiosOpenParams* pOpenParams) {
    OrbisFiosOp op = sceFiosFHOpen(pAttr, pOutFH, pPath, pOpenParams);
    return sceFiosOpSyncWait(op);
}

OrbisFiosOp PS4_SYSV_ABI sceFiosFHOpenWithMode(const OrbisFiosOpAttr* pAttr, OrbisFiosFH* pOutFH,
                                               const char* pPath,
                                               const OrbisFiosOpenParams* pOpenParams,
                                               s32 nativeMode) {
    LOG_WARNING(Lib_Fios2, "(DUMMY) called");
    return sceFiosFHOpen(pAttr, pOutFH, pPath, pOpenParams);
}

s32 PS4_SYSV_ABI sceFiosFHOpenWithModeSync(const OrbisFiosOpAttr* pAttr, OrbisFiosFH* pOutFH,
                                           const char* pPath,
                                           const OrbisFiosOpenParams* pOpenParams, s32 nativeMode) {
    LOG_WARNING(Lib_Fios2, "(DUMMY) called");
    OrbisFiosOp op = sceFiosFHOpenWithMode(pAttr, pOutFH, pPath, pOpenParams, nativeMode);
    return sceFiosOpSyncWaitForIO(op);
}

OrbisFiosOp PS4_SYSV_ABI sceFiosFHPread(const OrbisFiosOpAttr* pAttr, OrbisFiosFH fh, void* pBuf,
                                        OrbisFiosSize length, OrbisFiosOffset offset) {
    LOG_WARNING(Lib_Fios2, "(DUMMY) called");
    OrbisFiosSize ret = Kernel::sceKernelPread(fh, pBuf, length, offset);
    OrbisFiosOp op = ++op_count;
    op_io_return_codes_map.emplace(op, ret);
    return op;
}

s32 PS4_SYSV_ABI sceFiosFHPreadSync(const OrbisFiosOpAttr* pAttr, OrbisFiosFH fh, void* pBuf,
                                    OrbisFiosSize length, OrbisFiosOffset offset) {
    LOG_WARNING(Lib_Fios2, "(DUMMY) called");
    OrbisFiosOp op = sceFiosFHPread(pAttr, fh, pBuf, length, offset);
    return sceFiosOpSyncWaitForIO(op);
}

s32 PS4_SYSV_ABI sceFiosFHPreadv() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHPreadvSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFHPreadv();
}

s32 PS4_SYSV_ABI sceFiosFHPwrite() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHPwriteSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFHPwrite();
}

s32 PS4_SYSV_ABI sceFiosFHPwritev() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHPwritevSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFHPwritev();
}

OrbisFiosOp PS4_SYSV_ABI sceFiosFHRead(const OrbisFiosOpAttr* pAttr, OrbisFiosFH fh, void* pBuf,
                                       OrbisFiosSize length) {
    LOG_WARNING(Lib_Fios2, "(DUMMY) called");
    OrbisFiosSize ret = Kernel::sceKernelRead(fh, pBuf, length);
    OrbisFiosOp op = ++op_count;
    op_io_return_codes_map.emplace(op, ret);
    return op;
}

OrbisFiosSize PS4_SYSV_ABI sceFiosFHReadSync(const OrbisFiosOpAttr* pAttr, OrbisFiosFH fh,
                                             void* pBuf, OrbisFiosSize length) {
    OrbisFiosOp op = sceFiosFHRead(pAttr, fh, pBuf, length);
    return sceFiosOpSyncWaitForIO(op);
}

OrbisFiosOp PS4_SYSV_ABI sceFiosFHReadv(const OrbisFiosOpAttr* pAttr, OrbisFiosFH fh,
                                        const OrbisFiosBuffer iov[], int iovcnt) {
    LOG_WARNING(Lib_Fios2, "(DUMMY) called");

    std::vector<Kernel::SceKernelIovec> kernel_iov(iovcnt);
    for (int i = 0; i < iovcnt; ++i) {
        kernel_iov[i].iov_base = iov[i].pPtr;
        kernel_iov[i].iov_len = static_cast<std::size_t>(iov[i].length);
    }

    s64 ret = Kernel::sceKernelPreadv(fh, kernel_iov.data(), iovcnt, 0);

    OrbisFiosOp op = ++op_count;
    op_io_return_codes_map.emplace(op, ret);
    return op;
}

OrbisFiosSize PS4_SYSV_ABI sceFiosFHReadvSync(const OrbisFiosOpAttr* pAttr, OrbisFiosFH fh,
                                              const OrbisFiosBuffer iov[], int iovcnt) {
    OrbisFiosOp op = sceFiosFHReadv(pAttr, fh, iov, iovcnt);
    return sceFiosOpSyncWaitForIO(op);
}

s32 PS4_SYSV_ABI sceFiosFHSeek() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHStat() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHStatSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHSyncSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFHSync();
}

s32 PS4_SYSV_ABI sceFiosFHTell() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHToFileno() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHTruncate() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHTruncateSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFHTruncate();
}

s32 PS4_SYSV_ABI sceFiosFHWrite() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHWriteSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFHWrite();
}

s32 PS4_SYSV_ABI sceFiosFHWritev() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFHWritevSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFHWritev();
}

s32 PS4_SYSV_ABI sceFiosFileDelete() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFileDeleteSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFileDelete();
}

bool PS4_SYSV_ABI sceFiosFileExists() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

bool PS4_SYSV_ABI sceFiosFileExistsSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFileExists();
}

s32 PS4_SYSV_ABI sceFiosFileGetSize() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFileGetSizeSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFileGetSize();
}

s32 PS4_SYSV_ABI sceFiosFilenoToFH() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFileRead() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFileReadSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFileRead();
}

s32 PS4_SYSV_ABI sceFiosFileTruncate() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFileTruncateSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFileTruncate();
}

s32 PS4_SYSV_ABI sceFiosFileWrite() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosFileWriteSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosFileWrite();
}

s32 PS4_SYSV_ABI sceFiosGetAllDHs() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosGetAllFHs() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosGetAllOps() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosGetDefaultOpAttr() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosGetGlobalDefaultOpAttr() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosGetSuspendCount() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosGetThreadDefaultOpAttr() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosInitialize() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosIOFilterAdd() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosIOFilterCache() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosIOFilterGetInfo() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosIOFilterPsarcDearchiver() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosIOFilterRemove() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosIsIdle() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosIsInitialized() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosIsSuspended() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosIsValidHandle() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return 1;
}

s32 PS4_SYSV_ABI sceFiosOpCancel() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpDelete() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpGetActualCount() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpGetAttr() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpGetBuffer() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpGetError() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpGetOffset() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpGetPath() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpGetRequestCount() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpIsCancelled() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpIsDone() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpReschedule() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpRescheduleWithPriority() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpSetBuffer() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpSyncWait(OrbisFiosOp op) {
    LOG_DEBUG(Lib_Fios2, "called");
    auto it = op_return_codes_map.find(op);
    if (it == op_return_codes_map.end()) {
        return SCE_FIOS_ERROR_BAD_OP;
    }
    s32 ret = it->second;
    op_return_codes_map.erase(it);
    return ret;
}

OrbisFiosSize PS4_SYSV_ABI sceFiosOpSyncWaitForIO(OrbisFiosOp op) {
    LOG_DEBUG(Lib_Fios2, "called");
    auto it = op_io_return_codes_map.find(op);
    if (it == op_io_return_codes_map.end()) {
        return SCE_FIOS_ERROR_BAD_OP;
    }
    OrbisFiosSize ret = it->second;
    op_io_return_codes_map.erase(it);
    return ret;
}

s32 PS4_SYSV_ABI sceFiosOpWait() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOpWaitUntil() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOverlayAdd() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOverlayGetInfo() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOverlayGetList() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOverlayModify() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOverlayRemove() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosOverlayResolveSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosPathcmp() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosPathncmp() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosPathNormalize() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosPrintf() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosPrintTimeStamps() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosRename() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosRenameSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosRename();
}

s32 PS4_SYSV_ABI sceFiosResolve() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosResolveSync() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");

    return sceFiosResolve();
}

s32 PS4_SYSV_ABI sceFiosResume() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosSaveTimeStamp() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosSetGlobalDefaultOpAttr() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosSetThreadDefaultOpAttr() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosShutdownAndCancelOps() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosStat(const OrbisFiosOpAttr* pAttr, const char* pPath,
                             OrbisFiosStat* pOutStatus) {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    OrbisFiosOp op = ++op_count;
    op_return_codes_map.emplace(op, ORBIS_OK);
    return op;
}

s32 PS4_SYSV_ABI sceFiosStatSync(const OrbisFiosOpAttr* pAttr, const char* pPath,
                                 OrbisFiosStat* pOutStatus) {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called, pPath = {}", pPath);
    OrbisFiosOp op = sceFiosStat(pAttr, pPath, pOutStatus);
    return sceFiosOpSyncWait(op);
}

s32 PS4_SYSV_ABI sceFiosSuspend() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosTerminate() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosTimeGetCurrent() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosTimeIntervalFromNanoseconds() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosTimeIntervalToNanoseconds() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosTraceTimestamp() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosUpdateParameters() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI sceFiosVprintf() {
    LOG_ERROR(Lib_Fios2, "(STUBBED) called");
    return ORBIS_OK;
}

void RegisterlibSceFios2(Core::Loader::SymbolsResolver* sym) {
    const char* f = "libSceFios2";

    // return;

    // common
    LIB_FUNCTION("LHqFYb+U52E", f, 1, f, 1, 1, sceFiosExists);
    LIB_FUNCTION("2ZaHWy3IhKQ", f, 1, f, 1, 1, sceFiosExistsSync);
    LIB_FUNCTION("nomcox0J32k", f, 1, f, 1, 1, sceFiosDelete);
    LIB_FUNCTION("KsVTc04kN9k", f, 1, f, 1, 1, sceFiosDeleteSync);
    LIB_FUNCTION("VQ8e5t8vtYg", f, 1, f, 1, 1, sceFiosFileDelete);
    LIB_FUNCTION("bDupEgbQ6Fk", f, 1, f, 1, 1, sceFiosFileDeleteSync);
    LIB_FUNCTION("OY8v8WDzn3s", f, 1, f, 1, 1, sceFiosFileExists);
    LIB_FUNCTION("NwOHMRM2Ppw", f, 1, f, 1, 1, sceFiosFileExistsSync);
    LIB_FUNCTION("6jTNxzXckKU", f, 1, f, 1, 1, sceFiosFileGetSize);
    LIB_FUNCTION("zF8-CRvRXnM", f, 1, f, 1, 1, sceFiosFileGetSizeSync);
    LIB_FUNCTION("oRgsgfJY3Mc", f, 1, f, 1, 1, sceFiosFilenoToFH);
    LIB_FUNCTION("YlKCkfJL+Y8", f, 1, f, 1, 1, sceFiosFileRead);
    LIB_FUNCTION("kVMxSiYD6tc", f, 1, f, 1, 1, sceFiosFileReadSync);
    LIB_FUNCTION("9oCCIMp7zLo", f, 1, f, 1, 1, sceFiosFileTruncate);
    LIB_FUNCTION("gRA2pp3a1-k", f, 1, f, 1, 1, sceFiosFileTruncateSync);
    LIB_FUNCTION("q8CfetImdIY", f, 1, f, 1, 1, sceFiosFileWrite);
    LIB_FUNCTION("wj-U+mMbyAM", f, 1, f, 1, 1, sceFiosFileWriteSync);
    LIB_FUNCTION("-ULUBK21QgE", f, 1, f, 1, 1, sceFiosDirectoryCreate);
    LIB_FUNCTION("nWuza0ZdfqA", f, 1, f, 1, 1, sceFiosDirectoryCreateSync);
    LIB_FUNCTION("C5J+ANTy0qI", f, 1, f, 1, 1, sceFiosDirectoryCreateWithMode);
    LIB_FUNCTION("U6Qhv-QWXTc", f, 1, f, 1, 1, sceFiosDirectoryCreateWithModeSync);
    LIB_FUNCTION("rTjM9QpSyOM", f, 1, f, 1, 1, sceFiosDirectoryDelete);
    LIB_FUNCTION("n5TUlwdhGSA", f, 1, f, 1, 1, sceFiosDirectoryDeleteSync);
    LIB_FUNCTION("vtHd00f0O50", f, 1, f, 1, 1, sceFiosDirectoryExists);
    LIB_FUNCTION("OOuvHKTu4Oc", f, 1, f, 1, 1, sceFiosDirectoryExistsSync);
    LIB_FUNCTION("VoXRcLMOH7w", f, 1, f, 1, 1, sceFiosPathcmp);
    LIB_FUNCTION("zePYFs8UtNw", f, 1, f, 1, 1, sceFiosPathncmp);
    LIB_FUNCTION("M8m6+Xnz9Ds", f, 1, f, 1, 1, sceFiosPathNormalize);
    LIB_FUNCTION("uYx2ZEq998s", f, 1, f, 1, 1, sceFiosRename);
    LIB_FUNCTION("G-39lsdSgXo", f, 1, f, 1, 1, sceFiosRenameSync);
    LIB_FUNCTION("hqP0nzTTxdo", f, 1, f, 1, 1, sceFiosResolve);
    LIB_FUNCTION("oiK6kLAtAIE", f, 1, f, 1, 1, sceFiosResolveSync);
    LIB_FUNCTION("QKsI9N7K1zE", f, 1, f, 1, 1, sceFiosStat);
    LIB_FUNCTION("jayvY07C5dk", f, 1, f, 1, 1, sceFiosStatSync);

    // fiosDH (directory handle)
    LIB_FUNCTION("oT68xenFqSY", f, 1, f, 1, 1, sceFiosDHClose);
    LIB_FUNCTION("0-p4O8FINmU", f, 1, f, 1, 1, sceFiosDHCloseSync);
    LIB_FUNCTION("K7SHCEr+PkQ", f, 1, f, 1, 1, sceFiosDHGetPath);
    LIB_FUNCTION("uCkgJOrYUL4", f, 1, f, 1, 1, sceFiosDHOpen);
    LIB_FUNCTION("GGqucL9F+YI", f, 1, f, 1, 1, sceFiosDHOpenSync);
    LIB_FUNCTION("kG+A6NNwDow", f, 1, f, 1, 1, sceFiosDHRead);
    LIB_FUNCTION("odjOGg8harg", f, 1, f, 1, 1, sceFiosDHReadSync);
    LIB_FUNCTION("lHKLprulT24", f, 1, f, 1, 1, sceFiosGetAllDHs);

    // fiosFH (file handle)
    LIB_FUNCTION("+mfO27a-bEY", f, 1, f, 1, 1, sceFiosDeallocatePassthruFH);
    LIB_FUNCTION("5sYNBNK+W3g", f, 1, f, 1, 1, sceFiosFHClose);
    LIB_FUNCTION("AOujSGqU+ms", f, 1, f, 1, 1, sceFiosFHCloseSync);
    LIB_FUNCTION("lP9bRJMj0GU", f, 1, f, 1, 1, sceFiosFHGetOpenParams);
    LIB_FUNCTION("Mif6IzBa0hc", f, 1, f, 1, 1, sceFiosFHGetPath);
    LIB_FUNCTION("FdjoqFQOlt0", f, 1, f, 1, 1, sceFiosFHGetSize);
    LIB_FUNCTION("er6TkQFUvp0", f, 1, f, 1, 1, sceFiosFHOpen);
    LIB_FUNCTION("b44anV2D7K0", f, 1, f, 1, 1, sceFiosFHOpenSync);
    LIB_FUNCTION("jjzbvzquenM", f, 1, f, 1, 1, sceFiosFHOpenWithMode);
    LIB_FUNCTION("w13Ojm7ON9o", f, 1, f, 1, 1, sceFiosFHOpenWithModeSync);
    LIB_FUNCTION("rR8wq7YFRZs", f, 1, f, 1, 1, sceFiosFHPread);
    LIB_FUNCTION("2m9+Opco-hk", f, 1, f, 1, 1, sceFiosFHPreadSync);
    LIB_FUNCTION("pl4pWsecyrY", f, 1, f, 1, 1, sceFiosFHPreadv);
    LIB_FUNCTION("OHl4kz+OCws", f, 1, f, 1, 1, sceFiosFHPreadvSync);
    LIB_FUNCTION("PbxGVfOvUQY", f, 1, f, 1, 1, sceFiosFHPwrite);
    LIB_FUNCTION("gMcfOtHW6zk", f, 1, f, 1, 1, sceFiosFHPwriteSync);
    LIB_FUNCTION("3UPU8hbpaW0", f, 1, f, 1, 1, sceFiosFHPwritev);
    LIB_FUNCTION("J6Ujb3RviBA", f, 1, f, 1, 1, sceFiosFHPwritevSync);
    LIB_FUNCTION("cg-VoPqZYss", f, 1, f, 1, 1, sceFiosFHRead);
    LIB_FUNCTION("Bn2ZF4ZjeuQ", f, 1, f, 1, 1, sceFiosFHReadSync);
    LIB_FUNCTION("Socc-lFocbc", f, 1, f, 1, 1, sceFiosFHReadv);
    LIB_FUNCTION("ltWdd+agvD0", f, 1, f, 1, 1, sceFiosFHReadvSync);
    LIB_FUNCTION("xReSebwKApA", f, 1, f, 1, 1, sceFiosFHSeek);
    LIB_FUNCTION("--2iRpRn5Bw", f, 1, f, 1, 1, sceFiosFHStat);
    LIB_FUNCTION("xP45eIntEis", f, 1, f, 1, 1, sceFiosFHStatSync);
    LIB_FUNCTION("dQnI6o2OEC8", f, 1, f, 1, 1, sceFiosFHSync);
    LIB_FUNCTION("EzzSJz6yuMc", f, 1, f, 1, 1, sceFiosFHSyncSync);
    LIB_FUNCTION("MrRFrdgpsx8", f, 1, f, 1, 1, sceFiosFHTell);
    LIB_FUNCTION("8dzXU5GxsjI", f, 1, f, 1, 1, sceFiosFHToFileno);
    LIB_FUNCTION("0--XhDM7E-Q", f, 1, f, 1, 1, sceFiosFHTruncate);
    LIB_FUNCTION("tWS4uYFTU0M", f, 1, f, 1, 1, sceFiosFHTruncateSync);
    LIB_FUNCTION("urUHkGGweA4", f, 1, f, 1, 1, sceFiosFHWrite);
    LIB_FUNCTION("Kl-TbrDU9YM", f, 1, f, 1, 1, sceFiosFHWriteSync);
    LIB_FUNCTION("2PKMNZuXcPQ", f, 1, f, 1, 1, sceFiosFHWritev);
    LIB_FUNCTION("t4vLDMxzzf0", f, 1, f, 1, 1, sceFiosFHWritevSync);
    LIB_FUNCTION("4Kgi9D47mC8", f, 1, f, 1, 1, sceFiosGetAllFHs);
    LIB_FUNCTION("8IGjwtnvYwI", f, 1, f, 1, 1, sceFiosIsValidHandle);

    // misc + init + shutdown
    LIB_FUNCTION("-q4M5WX0Jrs", f, 1, f, 1, 1, sceFiosCancelAllOps);
    LIB_FUNCTION("wb8H3F+T6Ew", f, 1, f, 1, 1, sceFiosClearTimeStamps);
    LIB_FUNCTION("aKxpgAMSJ04", f, 1, f, 1, 1, sceFiosCloseAllFiles);
    LIB_FUNCTION("l4OVTpJCyQI", f, 1, f, 1, 1, sceFiosUpdateParameters);
    LIB_FUNCTION("fJTrPsXNsBY", f, 1, f, 1, 1, sceFiosDebugDumpDate);
    LIB_FUNCTION("FyuoXPzv780", f, 1, f, 1, 1, sceFiosDebugDumpDH);
    LIB_FUNCTION("8BLW2WiSIuI", f, 1, f, 1, 1, sceFiosDebugDumpError);
    LIB_FUNCTION("Sj5lbc4Y0mI", f, 1, f, 1, 1, sceFiosDebugDumpFH);
    LIB_FUNCTION("4-yhZ7aj3VE", f, 1, f, 1, 1, sceFiosDebugDumpOp);
    LIB_FUNCTION("tMYHEVj4j+o", f, 1, f, 1, 1, sceFiosSuspend);
    LIB_FUNCTION("3HAgZPl1v+4", f, 1, f, 1, 1, sceFiosTerminate);
    LIB_FUNCTION("vKL406KPJRs", f, 1, f, 1, 1, sceFiosResume);
    LIB_FUNCTION("ZPm4ROwjxi4", f, 1, f, 1, 1, sceFiosShutdownAndCancelOps);
    LIB_FUNCTION("YkayyuR6HvI", f, 1, f, 1, 1, sceFiosIsIdle);
    LIB_FUNCTION("aKWnlLIobGA", f, 1, f, 1, 1, sceFiosIsInitialized);
    LIB_FUNCTION("F7whoytBofE", f, 1, f, 1, 1, sceFiosIsSuspended);
    LIB_FUNCTION("Lxgze5-E3uQ", f, 1, f, 1, 1, sceFiosGetSuspendCount);
    LIB_FUNCTION("wAKZ-det+yo", f, 1, f, 1, 1, sceFiosInitialize);

    // date + time
    LIB_FUNCTION("DCfnYVX6xBo", f, 1, f, 1, 1, sceFiosPrintTimeStamps);
    LIB_FUNCTION("NUkBGOZARi4", f, 1, f, 1, 1, sceFiosTimeGetCurrent);
    LIB_FUNCTION("F1dCP7qkqok", f, 1, f, 1, 1, sceFiosTimeIntervalFromNanoseconds);
    LIB_FUNCTION("vZNIcB3n+bg", f, 1, f, 1, 1, sceFiosTimeIntervalToNanoseconds);
    LIB_FUNCTION("m96WzIHunT8", f, 1, f, 1, 1, sceFiosTraceTimestamp);
    LIB_FUNCTION("92xCv12VJIA", f, 1, f, 1, 1, sceFiosSaveTimeStamp);
    LIB_FUNCTION("axVqO-tslwo", f, 1, f, 1, 1, sceFiosDateFromComponents);
    LIB_FUNCTION("tQ6zNr0O6GA", f, 1, f, 1, 1, sceFiosDateGetCurrent);
    LIB_FUNCTION("Rm+hiwvSnxw", f, 1, f, 1, 1, sceFiosDateToComponents);

    // io filter
    LIB_FUNCTION("lgITuBsRo2o", f, 1, f, 1, 1, sceFiosIOFilterAdd);
    LIB_FUNCTION("lAikj8EfcJg", f, 1, f, 1, 1, sceFiosIOFilterCache);
    LIB_FUNCTION("gHxxOQxKW3E", f, 1, f, 1, 1, sceFiosIOFilterGetInfo);
    LIB_FUNCTION("OIGbkgGOu6E", f, 1, f, 1, 1, sceFiosIOFilterPsarcDearchiver);
    LIB_FUNCTION("ahIXyuwF0-o", f, 1, f, 1, 1, sceFiosIOFilterRemove);

    // operations
    LIB_FUNCTION("FA7dUleeGik", f, 1, f, 1, 1, sceFiosOpCancel);
    LIB_FUNCTION("5cyEcilO-J0", f, 1, f, 1, 1, sceFiosOpDelete);
    LIB_FUNCTION("+FRvKknUj1I", f, 1, f, 1, 1, sceFiosOpGetActualCount);
    LIB_FUNCTION("U44GbnRZ0NA", f, 1, f, 1, 1, sceFiosOpGetAttr);
    LIB_FUNCTION("52bk-Ucb5s0", f, 1, f, 1, 1, sceFiosOpGetBuffer);
    LIB_FUNCTION("X+7rIfY97Ps", f, 1, f, 1, 1, sceFiosOpGetError);
    LIB_FUNCTION("J9ujmUpwWAc", f, 1, f, 1, 1, sceFiosOpGetOffset);
    LIB_FUNCTION("4fZAv0vbycQ", f, 1, f, 1, 1, sceFiosOpGetPath);
    LIB_FUNCTION("51jH2C+it2s", f, 1, f, 1, 1, sceFiosOpGetRequestCount);
    LIB_FUNCTION("+8vcurPhbEY", f, 1, f, 1, 1, sceFiosOpIsCancelled);
    LIB_FUNCTION("bfgo2Otmqz0", f, 1, f, 1, 1, sceFiosOpIsDone);
    LIB_FUNCTION("DX1JP95j3Gg", f, 1, f, 1, 1, sceFiosOpReschedule);
    LIB_FUNCTION("csVTpsP0RLk", f, 1, f, 1, 1, sceFiosOpRescheduleWithPriority);
    LIB_FUNCTION("bHFaiUhZCrQ", f, 1, f, 1, 1, sceFiosOpSetBuffer);
    LIB_FUNCTION("2wvqS7Odb6M", f, 1, f, 1, 1, sceFiosOpSyncWait);
    LIB_FUNCTION("nP-LabYxHbk", f, 1, f, 1, 1, sceFiosOpSyncWaitForIO);
    LIB_FUNCTION("SnoQQWnGK9I", f, 1, f, 1, 1, sceFiosOpWait);
    LIB_FUNCTION("ZSsFitZ4Kpk", f, 1, f, 1, 1, sceFiosOpWaitUntil);
    LIB_FUNCTION("VdN2hNRay+E", f, 1, f, 1, 1, sceFiosGetAllOps);
    LIB_FUNCTION("+AGLl-l-WVE", f, 1, f, 1, 1, sceFiosGetDefaultOpAttr);
    LIB_FUNCTION("xiTqbFc7w+w", f, 1, f, 1, 1, sceFiosGetGlobalDefaultOpAttr);
    LIB_FUNCTION("fZjp7AUc+DY", f, 1, f, 1, 1, sceFiosGetThreadDefaultOpAttr);
    LIB_FUNCTION("2JtEQrjeUR4", f, 1, f, 1, 1, sceFiosSetGlobalDefaultOpAttr);
    LIB_FUNCTION("4Ml2G-TSCho", f, 1, f, 1, 1, sceFiosSetThreadDefaultOpAttr);

    // cache
    LIB_FUNCTION("7CXAnIwFY3U", f, 1, f, 1, 1, sceFiosCacheContainsFileRangeSync);
    LIB_FUNCTION("H6wju6uvjmA", f, 1, f, 1, 1, sceFiosCacheContainsFileSync);
    LIB_FUNCTION("8e4TgQd155k", f, 1, f, 1, 1, sceFiosCacheFlushFileRangeSync);
    LIB_FUNCTION("R4YQI0YpbB0", f, 1, f, 1, 1, sceFiosCacheFlushFileSync);
    LIB_FUNCTION("NRe2Dtymlmk", f, 1, f, 1, 1, sceFiosCacheFlushSync);
    LIB_FUNCTION("iGpuaBFQroQ", f, 1, f, 1, 1, sceFiosCachePrefetchFH);
    LIB_FUNCTION("uT4EBfl284o", f, 1, f, 1, 1, sceFiosCachePrefetchFHRange);
    LIB_FUNCTION("tm3Hb4s0et8", f, 1, f, 1, 1, sceFiosCachePrefetchFHRangeSync);
    LIB_FUNCTION("zIx-FcuPXVM", f, 1, f, 1, 1, sceFiosCachePrefetchFHSync);
    LIB_FUNCTION("T8upMyvUPz0", f, 1, f, 1, 1, sceFiosCachePrefetchFile);
    LIB_FUNCTION("FYGZ0F5ZglA", f, 1, f, 1, 1, sceFiosCachePrefetchFileRange);
    LIB_FUNCTION("ZzE6WN+QBbE", f, 1, f, 1, 1, sceFiosCachePrefetchFileRangeSync);
    LIB_FUNCTION("bC0WTypscWg", f, 1, f, 1, 1, sceFiosCachePrefetchFileSync);

    // archive
    LIB_FUNCTION("GxAF6y9l98M", f, 1, f, 1, 1, sceFiosArchiveGetDecompressorThreadCount);
    LIB_FUNCTION("ERmiOK9VT0g", f, 1, f, 1, 1, sceFiosArchiveGetMountBufferSize);
    LIB_FUNCTION("UUriaXy7G90", f, 1, f, 1, 1, sceFiosArchiveGetMountBufferSizeSync);
    LIB_FUNCTION("pIU8u6VsLM8", f, 1, f, 1, 1, sceFiosArchiveMount);
    LIB_FUNCTION("xutLbQdqyb4", f, 1, f, 1, 1, sceFiosArchiveMountSync);
    LIB_FUNCTION("VKQ8pi4466g", f, 1, f, 1, 1, sceFiosArchiveMountWithOrder);
    LIB_FUNCTION("GEAzhWJM1mY", f, 1, f, 1, 1, sceFiosArchiveMountWithOrderSync);
    LIB_FUNCTION("Dfwp-U1OfRI", f, 1, f, 1, 1, sceFiosArchiveSetDecompressorThreadCount);
    LIB_FUNCTION("YfTBBU5nONQ", f, 1, f, 1, 1, sceFiosArchiveUnmount);
    LIB_FUNCTION("yy6C7k7FPZY", f, 1, f, 1, 1, sceFiosArchiveUnmountSync);

    // print
    LIB_FUNCTION("z0zd9JqbxYs", f, 1, f, 1, 1, sceFiosPrintf);
    LIB_FUNCTION("FOEUXzOE0ow", f, 1, f, 1, 1, sceFiosVprintf);

    // overlay
    LIB_FUNCTION("TXABsmiiqto", f, 1, f, 1, 1, sceFiosOverlayAdd);
    LIB_FUNCTION("lFVNuWYTTFs", f, 1, f, 1, 1, sceFiosOverlayGetInfo);
    LIB_FUNCTION("qcZZ8FqdT8c", f, 1, f, 1, 1, sceFiosOverlayGetList);
    LIB_FUNCTION("qD5Su6YGVWM", f, 1, f, 1, 1, sceFiosOverlayModify);
    LIB_FUNCTION("MuMnDaXBTm0", f, 1, f, 1, 1, sceFiosOverlayRemove);
    LIB_FUNCTION("8inAOixHSQw", f, 1, f, 1, 1, sceFiosOverlayResolveSync);

    // dll
    LIB_FUNCTION("PIw2ZEh6JyI", f, 1, f, 1, 1, sceFiosDLLInitialize);
    LIB_FUNCTION("kPvgi8x497Q", f, 1, f, 1, 1, sceFiosDLLTerminate);
};

} // namespace Libraries::Fios2