// SPDX-FileCopyrightText: Copyright 2025 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "common/types.h"

namespace Libraries::NpUtility {

constexpr s32 SCE_NP_BANDWIDTH_TEST_ERROR_OUT_OF_MEMORY = 0x80551f04;
constexpr s32 SCE_NP_BANDWIDTH_TEST_ERROR_INVALID_ARGUMENT = 0x80551f05;
constexpr s32 SCE_NP_BANDWIDTH_TEST_ERROR_INVALID_SIZE = 0x80551f06;
constexpr s32 SCE_NP_BANDWIDTH_TEST_ERROR_CONTEXT_NOT_AVAILABLE = 0x80551f07;

} // namespace Libraries::NpUtility