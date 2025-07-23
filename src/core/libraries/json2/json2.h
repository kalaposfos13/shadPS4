// SPDX-FileCopyrightText: Copyright 2025 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "common/types.h"

namespace Core::Loader {
class SymbolsResolver;
}

namespace Libraries::Json2 {

s32 PS4_SYSV_ABI Free(void*);
s32 PS4_SYSV_ABI Malloc(unsigned long);

// some of these might be enums
struct ValueType {};
struct FunctionType {};
struct SpecialFloatFormatType {};

class Object;
class Array;

class String {
public:
    s32 npos;
    s32 clear();
    s32 append(char const*);
    s32 append(char const*, unsigned long);
    s32 append(Json2::String const&);
    s32 resize(unsigned long);
    s32 reserve(unsigned long);
    s32 at(unsigned long);
    s32 find(char, unsigned long);
    s32 find(char const*, unsigned long);
    s32 find(char const*, unsigned long, unsigned long);
    s32 find(Json2::String const&, unsigned long);
    s32 size();
    s32 c_str();
    s32 empty();
    s32 rfind(char, unsigned long);
    s32 rfind(char const*, unsigned long);
    s32 rfind(char const*, unsigned long, unsigned long);
    s32 rfind(Json2::String const&, unsigned long);
    s32 length();
    s32 substr(unsigned long, unsigned long);
    s32 compare(char const*);
    s32 compare(Json2::String const&);
    s32 capacity();
    s32 operator==(char const*);
    s32 operator==(Json2::String const&);
    s32 operator=(Json2::String const&);
    s32 operator+=(unsigned char);
    s32 operator+=(char const*);
    String(char const*);
    String(Json2::String const&);
    String();
    ~String();
};

class Value {
public:
    static s32 s_nullbool;
    static s32 s_nullreal;
    static s32 s_nullarray;
    static s32 s_nullobject;
    static s32 s_nullstring;
    static s32 s_nullinteger;
    static s32 s_nulluinteger;
    s32 referArray();
    s32 referValue(unsigned long);
    s32 referValue(Json2::String const&);
    s32 referObject();
    s32 referString();
    s32 referBoolean();
    s32 referInteger();
    s32 referUInteger();
    s32 setNullAccessCallBack(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, void*), void*);
    s32 setSpecialFloatHandler(Json2::Value const (*)(Json2::FunctionType, double, Json2::Value const*, void*, bool*), void*);
    s32 setTypeMismatchHandler(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, Json2::Value const*, void*), void*);
    s32 setElementAccessFailureHandler(void (*)(int, Json2::String const*, unsigned long const*, Json2::Value const*, Json2::Value const*, void*), void*);
    s32 set(bool);
    s32 set(double);
    s32 set(long);
    s32 set(unsigned long);
    s32 set(Json2::ValueType);
    s32 set(char const*);
    s32 set(Json2::Array const&);
    s32 set(Json2::Object const&);
    s32 set(Json2::String const&);
    s32 set(Json2::Value const&);
    s32 swap(Json2::Value&);
    s32 clear();
    s32 referReal();
    s32 serialize(int (*)(Json2::String&, void*), void*);
    s32 serialize(Json2::String&);
    s32 serialize(Json2::String&, int (*)(Json2::String&, void*), void*);
    s32 getBoolean();
    s32 getInteger();
    s32 getUInteger();
    s32 count();
    s32 getReal();
    s32 getType();
    s32 getArray();
    s32 getValue(unsigned long);
    s32 getValue(Json2::String const&);
    s32 toString(Json2::String&);
    s32 getObject();
    s32 getString();
    s32 operator=(Json2::Value const&);
    operator bool();
    s32 operator[](unsigned long);
    s32 operator[](char const*);
    s32 operator[](Json2::String const&);
    Value(bool);
    Value(double);
    Value(long);
    Value(unsigned long);
    Value(Json2::ValueType);
    Value(char const*);
    Value(Json2::Array const&);
    Value(Json2::Object const&);
    Value(Json2::String const&);
    Value(Json2::Value const&);
    Value();
    ~Value();
};

class MemAllocator {
public:
    s32 notifyError(int, unsigned long, void*);
    MemAllocator();
    ~MemAllocator();
};

class InitParameter {};

class InitParameter2 {
public:
    s32 setAllocator(Json2::MemAllocator*, void*);
    s32 setFileBufferSize(unsigned long);
    s32 setSpecialFloatFormatType(Json2::SpecialFloatFormatType);
    s32 getUserData();
    s32 getAllocator();
    s32 getFileBufferSize();
    s32 getSpecialFloatFormatType();
    InitParameter2();
};

class Initializer {
public:
    s32 PS4_SYSV_ABI initialize(Json2::InitParameter const*);
    s32 PS4_SYSV_ABI initialize(Json2::InitParameter2 const*);
    s32 PS4_SYSV_ABI setAllocatorInfoCallBack(void (*)(int, Json2::ValueType, void*), void*);
    s32 PS4_SYSV_ABI setGlobalNullAccessCallback(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, void*), void*);
    s32 PS4_SYSV_ABI setGlobalSpecialFloatHandler(Json2::Value const (*)(Json2::FunctionType, double, Json2::Value const*, void*, bool*), void*);
    s32 PS4_SYSV_ABI setGlobalTypeMismatchHandler(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, Json2::Value const*, void*), void*);
    s32 PS4_SYSV_ABI setGlobalElementAccessFailureHandler(void (*)(int, Json2::String const*, unsigned long const*, Json2::Value const*, Json2::Value const*, void*), void*);
    s32 PS4_SYSV_ABI terminate();
    PS4_SYSV_ABI Initializer();
    PS4_SYSV_ABI ~Initializer();
};

struct AllocParamRtti {};

class InitParameterRtti {
public:
    InitParameterRtti(Json2::AllocParamRtti*, void*, unsigned long);
};

class InitParameterRtti2 {
public:
    s32 setAllocatorRtti(Json2::AllocParamRtti*, void*);
};

class InternalInitializer {
public:
    struct InitOption {};
    s32 terminate_staticlib();
    s32 initialize_staticlib(Json2::InitParameter const*, Json2::InternalInitializer::InitOption);
    InternalInitializer();
    ~InternalInitializer();
};

class Array {
public:
    class iterator {
    public:
        s32 advance(unsigned long);
        s32 operator=(Json2::Array::iterator const&);
        s32 operator++(int);
        s32 operator++();
        s32 operator*();
        s32 operator!=(Json2::Array::iterator const&);
        s32 operator->();
        iterator(Json2::Array::iterator const&);
        iterator();
        ~iterator();
    };
    s32 push_front(Json2::Value const&);
    s32 clear();
    s32 erase(Json2::Array::iterator const&);
    s32 insert(Json2::Array::iterator const&, Json2::Value const&);
    s32 pop_back();
    s32 pop_front();
    s32 push_back(Json2::Value const&);
    s32 operator=(Json2::Array const&);
    s32 end();
    s32 back();
    s32 size();
    s32 begin();
    s32 empty();
    s32 front();
    Array(Json2::Array const&);
    Array();
    ~Array();
};

class Object {
public:
    class Pair {
    public:
        Pair(Json2::String const&, Json2::Value const&);
        Pair();
        ~Pair();
    };
    class iterator {
    public:
        iterator(Json2::Object::iterator const&);
        iterator();
        ~iterator();
        s32 advance(unsigned long);
        s32 operator=(Json2::Object::iterator const&);
        s32 operator++(int);
        s32 operator++();
        s32 operator*();
        s32 operator==(Json2::Object::iterator const&);
        s32 operator!=(Json2::Object::iterator const&);
        s32 operator->();
    };
    s32 clear();
    s32 erase(Json2::String const&);
    s32 insert(Json2::Object::Pair const&);
    s32 end();
    s32 find(Json2::String const&);
    s32 size();
    s32 begin();
    s32 empty();
    s32 operator=(Json2::Object const&);
    s32 operator[](Json2::String const&);
    Object(Json2::Object const&);
    Object();
    ~Object();
};

class Parser {
public:
    s32 parse(Json2::Value&, int (*)(char&, void*), void*);
    s32 parse(Json2::Value&, char const*);
    s32 parse(Json2::Value&, char const*, unsigned long);
};

template <typename T, typename... Args>
void ctor_wrapper(void* _this, Args... args) {
    new (_this) T(std::forward<Args>(args)...);
}

template <typename T>
void dtor_wrapper(T* _this) {
    _this->~T();
}

void RegisterLib(Core::Loader::SymbolsResolver* sym);
} // namespace Libraries::Json2