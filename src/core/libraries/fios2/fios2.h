// SPDX-FileCopyrightText: Copyright 2025 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "common/types.h"

namespace Core::Loader {
class SymbolsResolver;
}

namespace Libraries::Fios2 {

void RegisterlibSceFios2(Core::Loader::SymbolsResolver* sym);
} // namespace Libraries::Fios2