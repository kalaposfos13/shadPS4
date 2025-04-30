// SPDX-FileCopyrightText: Copyright 2025 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "common/types.h"

namespace Core::Loader {
class SymbolsResolver;
}

namespace Libraries::Fios2 {

constexpr u32 ORBIS_FIOS_PATH_MAX = 1024;

typedef s32 OrbisFiosHandle;
typedef OrbisFiosHandle OrbisFiosFH; // file handle
typedef OrbisFiosHandle OrbisFiosDH; // directory handle
typedef OrbisFiosHandle OrbisFiosOp;

typedef u8 OrbisFiosOpEvent;

typedef enum OrbisFiosOpEvents { Complete = 1, Delete = 2, Start = 3 } OrbisFiosOpEvents;
typedef enum OrbisFiosWhence { Set = 0, Current = 1, End = 2 } SceFiosWhence;

typedef s64 OrbisFiosSize;
typedef s64 OrbisFiosOffset;
typedef s64 OrbisFiosDate;
typedef s64 OrbisFiosTime;

typedef struct OrbisFiosStat {
    OrbisFiosOffset fileSize;
    OrbisFiosDate accessDate;
    OrbisFiosDate modificationDate;
    OrbisFiosDate creationDate;
    u32 statFlags;
    u32 reserved;
    s64 uid;
    s64 gid;
    s64 dev;
    s64 ino;
    s64 mode;
} OrbisFiosStat;

typedef struct OrbisFiosDirEntry {
    OrbisFiosOffset fileSize;
    uint32_t statFlags;
    uint16_t nameLength;
    uint16_t fullPathLength;
    uint16_t offsetToName;
    uint16_t reserved[3];
    char fullPath[ORBIS_FIOS_PATH_MAX];
} SceFiosDirEntry;

typedef struct OrbisFiosBuffer {
    void* pPtr;
    u64 length;
} OrbisFiosBuffer;

typedef struct OrbisFiosOpenParams {
    u32 openFlags : 16;
    u32 opFlags : 16;
    u32 reserved;
    OrbisFiosBuffer buffer;
} OrbisFiosOpenParams;

typedef int PS4_SYSV_ABI (*OrbisFiosOpCallback)(void* pContext, OrbisFiosOp op, OrbisFiosOpEvent event, int err);

typedef struct OrbisFiosOpAttr {
    OrbisFiosTime deadline;
    OrbisFiosOpCallback pCallback;
    void* pCallbackContext;
    int32_t priority : 8;
    uint32_t opflags : 24;
    uint32_t userTag;
    void* userPtr;
    void* pReserved;
} OrbisFiosOpAttr;

s32 PS4_SYSV_ABI sceFiosOpSyncWait(OrbisFiosOp op);
OrbisFiosSize PS4_SYSV_ABI sceFiosOpSyncWaitForIO(OrbisFiosOp op);

void RegisterlibSceFios2(Core::Loader::SymbolsResolver* sym);
} // namespace Libraries::Fios2