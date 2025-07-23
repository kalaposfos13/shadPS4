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
    s32 PS4_SYSV_ABI clear();
    s32 PS4_SYSV_ABI append(char const*);
    s32 PS4_SYSV_ABI append(char const*, unsigned long);
    s32 PS4_SYSV_ABI append(Json2::String const&);
    s32 PS4_SYSV_ABI resize(unsigned long);
    s32 PS4_SYSV_ABI reserve(unsigned long);
    s32 PS4_SYSV_ABI at(unsigned long);
    s32 PS4_SYSV_ABI find(char, unsigned long);
    s32 PS4_SYSV_ABI find(char const*, unsigned long);
    s32 PS4_SYSV_ABI find(char const*, unsigned long, unsigned long);
    s32 PS4_SYSV_ABI find(Json2::String const&, unsigned long);
    s32 PS4_SYSV_ABI size();
    s32 PS4_SYSV_ABI c_str();
    s32 PS4_SYSV_ABI empty();
    s32 PS4_SYSV_ABI rfind(char, unsigned long);
    s32 PS4_SYSV_ABI rfind(char const*, unsigned long);
    s32 PS4_SYSV_ABI rfind(char const*, unsigned long, unsigned long);
    s32 PS4_SYSV_ABI rfind(Json2::String const&, unsigned long);
    s32 PS4_SYSV_ABI length();
    s32 PS4_SYSV_ABI substr(unsigned long, unsigned long);
    s32 PS4_SYSV_ABI compare(char const*);
    s32 PS4_SYSV_ABI compare(Json2::String const&);
    s32 PS4_SYSV_ABI capacity();
    s32 PS4_SYSV_ABI operator==(char const*);
    s32 PS4_SYSV_ABI operator==(Json2::String const&);
    s32 PS4_SYSV_ABI operator=(Json2::String const&);
    s32 PS4_SYSV_ABI operator+=(unsigned char);
    s32 PS4_SYSV_ABI operator+=(char const*);
    PS4_SYSV_ABI String(char const*);
    PS4_SYSV_ABI String(Json2::String const&);
    PS4_SYSV_ABI String();
    PS4_SYSV_ABI ~String();
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
    s32 PS4_SYSV_ABI referArray();
    s32 PS4_SYSV_ABI referValue(unsigned long);
    s32 PS4_SYSV_ABI referValue(Json2::String const&);
    s32 PS4_SYSV_ABI referObject();
    s32 PS4_SYSV_ABI referString();
    s32 PS4_SYSV_ABI referBoolean();
    s32 PS4_SYSV_ABI referInteger();
    s32 PS4_SYSV_ABI referUInteger();
    s32 PS4_SYSV_ABI setNullAccessCallBack(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, void*), void*);
    s32 PS4_SYSV_ABI setSpecialFloatHandler(Json2::Value const (*)(Json2::FunctionType, double, Json2::Value const*, void*, bool*), void*);
    s32 PS4_SYSV_ABI setTypeMismatchHandler(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, Json2::Value const*, void*), void*);
    s32 PS4_SYSV_ABI setElementAccessFailureHandler(void (*)(int, Json2::String const*, unsigned long const*, Json2::Value const*, Json2::Value const*, void*), void*);
    s32 PS4_SYSV_ABI set(bool);
    s32 PS4_SYSV_ABI set(double);
    s32 PS4_SYSV_ABI set(long);
    s32 PS4_SYSV_ABI set(unsigned long);
    s32 PS4_SYSV_ABI set(Json2::ValueType);
    s32 PS4_SYSV_ABI set(char const*);
    s32 PS4_SYSV_ABI set(Json2::Array const&);
    s32 PS4_SYSV_ABI set(Json2::Object const&);
    s32 PS4_SYSV_ABI set(Json2::String const&);
    s32 PS4_SYSV_ABI set(Json2::Value const&);
    s32 PS4_SYSV_ABI swap(Json2::Value&);
    s32 PS4_SYSV_ABI clear();
    s32 PS4_SYSV_ABI referReal();
    s32 PS4_SYSV_ABI serialize(int (*)(Json2::String&, void*), void*);
    s32 PS4_SYSV_ABI serialize(Json2::String&);
    s32 PS4_SYSV_ABI serialize(Json2::String&, int (*)(Json2::String&, void*), void*);
    s32 PS4_SYSV_ABI getBoolean();
    s32 PS4_SYSV_ABI getInteger();
    s32 PS4_SYSV_ABI getUInteger();
    s32 PS4_SYSV_ABI count();
    s32 PS4_SYSV_ABI getReal();
    s32 PS4_SYSV_ABI getType();
    s32 PS4_SYSV_ABI getArray();
    s32 PS4_SYSV_ABI getValue(unsigned long);
    s32 PS4_SYSV_ABI getValue(Json2::String const&);
    s32 PS4_SYSV_ABI toString(Json2::String&);
    s32 PS4_SYSV_ABI getObject();
    s32 PS4_SYSV_ABI getString();
    s32 PS4_SYSV_ABI operator=(Json2::Value const&);
    PS4_SYSV_ABI operator bool();
    s32 PS4_SYSV_ABI operator[](unsigned long);
    s32 PS4_SYSV_ABI operator[](char const*);
    s32 PS4_SYSV_ABI operator[](Json2::String const&);
    PS4_SYSV_ABI Value(bool);
    PS4_SYSV_ABI Value(double);
    PS4_SYSV_ABI Value(long);
    PS4_SYSV_ABI Value(unsigned long);
    PS4_SYSV_ABI Value(Json2::ValueType);
    PS4_SYSV_ABI Value(char const*);
    PS4_SYSV_ABI Value(Json2::Array const&);
    PS4_SYSV_ABI Value(Json2::Object const&);
    PS4_SYSV_ABI Value(Json2::String const&);
    PS4_SYSV_ABI Value(Json2::Value const&);
    PS4_SYSV_ABI Value();
    PS4_SYSV_ABI ~Value();
};

class MemAllocator {
public:
    s32 PS4_SYSV_ABI notifyError(int, unsigned long, void*);
    PS4_SYSV_ABI MemAllocator();
    PS4_SYSV_ABI ~MemAllocator();
};

class InitParameter {};

class InitParameter2 {
public:
    s32 PS4_SYSV_ABI setAllocator(Json2::MemAllocator*, void*);
    s32 PS4_SYSV_ABI setFileBufferSize(unsigned long);
    s32 PS4_SYSV_ABI setSpecialFloatFormatType(Json2::SpecialFloatFormatType);
    s32 PS4_SYSV_ABI getUserData();
    s32 PS4_SYSV_ABI getAllocator();
    s32 PS4_SYSV_ABI getFileBufferSize();
    s32 PS4_SYSV_ABI getSpecialFloatFormatType();
    PS4_SYSV_ABI InitParameter2();
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
    PS4_SYSV_ABI InitParameterRtti(Json2::AllocParamRtti*, void*, unsigned long);
};

class InitParameterRtti2 {
public:
    s32 PS4_SYSV_ABI setAllocatorRtti(Json2::AllocParamRtti*, void*);
};

class InternalInitializer {
public:
    struct InitOption {};
    s32 PS4_SYSV_ABI terminate_staticlib();
    s32 PS4_SYSV_ABI initialize_staticlib(Json2::InitParameter const*, Json2::InternalInitializer::InitOption);
    PS4_SYSV_ABI InternalInitializer();
    PS4_SYSV_ABI ~InternalInitializer();
};

class Array {
public:
    class iterator {
    public:
        s32 PS4_SYSV_ABI advance(unsigned long);
        s32 PS4_SYSV_ABI operator=(Json2::Array::iterator const&);
        s32 PS4_SYSV_ABI operator++(int);
        s32 PS4_SYSV_ABI operator++();
        s32 PS4_SYSV_ABI operator*();
        s32 PS4_SYSV_ABI operator!=(Json2::Array::iterator const&);
        s32 PS4_SYSV_ABI operator->();
        PS4_SYSV_ABI iterator(Json2::Array::iterator const&);
        PS4_SYSV_ABI iterator();
        PS4_SYSV_ABI ~iterator();
    };
    s32 PS4_SYSV_ABI push_front(Json2::Value const&);
    s32 PS4_SYSV_ABI clear();
    s32 PS4_SYSV_ABI erase(Json2::Array::iterator const&);
    s32 PS4_SYSV_ABI insert(Json2::Array::iterator const&, Json2::Value const&);
    s32 PS4_SYSV_ABI pop_back();
    s32 PS4_SYSV_ABI pop_front();
    s32 PS4_SYSV_ABI push_back(Json2::Value const&);
    s32 PS4_SYSV_ABI operator=(Json2::Array const&);
    s32 PS4_SYSV_ABI end();
    s32 PS4_SYSV_ABI back();
    s32 PS4_SYSV_ABI size();
    s32 PS4_SYSV_ABI begin();
    s32 PS4_SYSV_ABI empty();
    s32 PS4_SYSV_ABI front();
    PS4_SYSV_ABI Array(Json2::Array const&);
    PS4_SYSV_ABI Array();
    PS4_SYSV_ABI ~Array();
};

class Object {
public:
    class Pair {
    public:
        PS4_SYSV_ABI Pair(Json2::String const&, Json2::Value const&);
        PS4_SYSV_ABI Pair();
        PS4_SYSV_ABI ~Pair();
    };
    class iterator {
    public:
        PS4_SYSV_ABI iterator(Json2::Object::iterator const&);
        PS4_SYSV_ABI iterator();
        PS4_SYSV_ABI ~iterator();
        s32 PS4_SYSV_ABI advance(unsigned long);
        s32 PS4_SYSV_ABI operator=(Json2::Object::iterator const&);
        s32 PS4_SYSV_ABI operator++(int);
        s32 PS4_SYSV_ABI operator++();
        s32 PS4_SYSV_ABI operator*();
        s32 PS4_SYSV_ABI operator==(Json2::Object::iterator const&);
        s32 PS4_SYSV_ABI operator!=(Json2::Object::iterator const&);
        s32 PS4_SYSV_ABI operator->();
    };
    s32 PS4_SYSV_ABI clear();
    s32 PS4_SYSV_ABI erase(Json2::String const&);
    s32 PS4_SYSV_ABI insert(Json2::Object::Pair const&);
    s32 PS4_SYSV_ABI end();
    s32 PS4_SYSV_ABI find(Json2::String const&);
    s32 PS4_SYSV_ABI size();
    s32 PS4_SYSV_ABI begin();
    s32 PS4_SYSV_ABI empty();
    s32 PS4_SYSV_ABI operator=(Json2::Object const&);
    s32 PS4_SYSV_ABI operator[](Json2::String const&);
    PS4_SYSV_ABI Object(Json2::Object const&);
    PS4_SYSV_ABI Object();
    PS4_SYSV_ABI ~Object();
};

class Parser {
public:
    s32 PS4_SYSV_ABI parse(Json2::Value&, int (*)(char&, void*), void*);
    s32 PS4_SYSV_ABI parse(Json2::Value&, char const*);
    s32 PS4_SYSV_ABI parse(Json2::Value&, char const*, unsigned long);
};

template <typename T, typename... Args>
void PS4_SYSV_ABI ctor_wrapper(void* _this, Args... args) {
    new (_this) T(std::forward<Args>(args)...);
}

template <typename T>
void PS4_SYSV_ABI dtor_wrapper(T* _this) {
    _this->~T();
}

void RegisterLib(Core::Loader::SymbolsResolver* sym);
} // namespace Libraries::Json2