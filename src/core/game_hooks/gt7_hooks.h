// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "core/linker.h"
#include "core/game_hooks/LightHook.h"
#include "common/types.h"

namespace GT7Hooks {

struct hObject;

struct PrintTarget {
    u64 vtable;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u32 dword28;
    int field_2C;
    u8* buffer;
    u64 bufferSize;
};

struct hObject_vt {
    void* field_0x00;
    void* field_0x08;
    void* field_0x10;
    char* (PS4_SYSV_ABI *rc_class)(char** outStr, hObject* this_);
    void (PS4_SYSV_ABI *toString)(char** outStr, hObject* this_);
    void* field_0x20;
    void* field_0x28;
    void* field_0x30;
    void* field_0x38;
    void* field_0x40;
    void* field_0x48;
    void* field_0x50;
    void* field_0x58;
    void* field_0x60;
    void* field_0x68;
    void* field_0x70;
    void* field_0x78;
    void* field_0x80;
    void* field_0x88;
    void* field_0x90;
    void* field_0x98;
    void* field_0xA0;
    void* field_0xA8;
    void* field_0xB0;
    void* field_0xB8;
    void* field_0xC0;
    void* field_0xC8;
    void* field_0xD0;
    void* field_0xD8;
    void* field_0xE0;
    void* field_0xE8;
    void* field_0xF0;
    void* field_0xF8;
    void* field_0x100;
    void* field_0x108;
    void* field_0x110;
    void* field_0x118;
    void* field_0x120;
    void* field_0x128;
    void* field_0x130;
    void* field_0x138;
    void* field_0x140;
    void* field_0x148;
    void* field_0x150;
    void* field_0x158;
    void* field_0x160;
    void* field_0x168;
    void* field_0x170;
    void* field_0x178;
    void* field_0x180;
    void* field_0x188;
    void* field_0x190;
    void* field_0x198;
    void* field_0x1A0;
    void* field_0x1A8;
    void* field_0x1B0;
    void* field_0x1B8;
    void* call;
};

struct hObject {
    hObject_vt* vt;
    void* field_0x08;
    void* field_0x10;
    void* field_0x18;
};

struct hThread : hObject {
    char* source_file_name;
    int source_line_number;
    int field_0x2C;
    char* field_0x30;
    char* field_0x38;
    char* field_0x40;
    char* field_0x48;
};

struct hClass : hObject {

};

struct HCode
{
    void* vt;
    void* field_0x08;
    void* field_0x10;
    void* field_0x18;
    void* field_0x20;
    void* field_0x28;
    void* field_0x30;
    void* field_0x38;
    void* field_0x40;
    void* field_0x48;
    void* field_0x50;
    void* field_0x58;
    void* field_0x60;
    char* name;
};

struct hExecCode
{
    void* vt;
    char* field_0x08;
    HCode* code;
    void* field_0x18;
    void* field_0x20;
    void* field_0x28;
    void* field_0x30;
    void* field_0x38;
    void* field_0x40;
    void* field_0x48;
    void* field_0x50;
    void* module;
    void* field_0x60;
};

struct hFunctionValue
{
    void* vt;
    char* field_0x08;
    char* field_0x10;
    char* field_0x18;
    hExecCode* exec_code;
};

struct hFunctionObject : hObject {
    hFunctionValue* value;
};

struct hSymbol {
    char* name;
};



void Initialize(Core::Module* module);

} // namespace GT7Hooks