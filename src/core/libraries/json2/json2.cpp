// SPDX-FileCopyrightText: Copyright 2025 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "common/logging/log.h"
#include "core/libraries/error_codes.h"
#include "core/libraries/json2/json2.h"
#include "core/libraries/libs.h"
#include "json2.h"

namespace Libraries::Json2 {

s32 PS4_SYSV_ABI Json2::Initializer::initialize(Json2::InitParameter const*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Initializer::initialize(Json2::InitParameter2 const*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Initializer::setAllocatorInfoCallBack(void (*)(int, Json2::ValueType, void*), void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Initializer::setGlobalNullAccessCallback(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, void*), void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Initializer::setGlobalSpecialFloatHandler(Json2::Value const (*)(Json2::FunctionType, double, Json2::Value const*, void*, bool*), void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Initializer::setGlobalTypeMismatchHandler(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, Json2::Value const*, void*), void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Initializer::setGlobalElementAccessFailureHandler(void (*)(int, Json2::String const*, unsigned long const*, Json2::Value const*, Json2::Value const*, void*), void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Initializer::terminate() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

PS4_SYSV_ABI Json2::Initializer::Initializer() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Initializer::~Initializer() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

s32 PS4_SYSV_ABI Json2::MemAllocator::notifyError(int, unsigned long, void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

PS4_SYSV_ABI Json2::MemAllocator::MemAllocator() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::MemAllocator::~MemAllocator() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

s32 PS4_SYSV_ABI Json2::InitParameter2::setAllocator(Json2::MemAllocator*, void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::InitParameter2::setFileBufferSize(unsigned long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::InitParameter2::setSpecialFloatFormatType(Json2::SpecialFloatFormatType) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

PS4_SYSV_ABI Json2::InitParameter2::InitParameter2() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::InitParameterRtti::InitParameterRtti(Json2::AllocParamRtti*, void*, unsigned long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

s32 PS4_SYSV_ABI Json2::InitParameterRtti2::setAllocatorRtti(Json2::AllocParamRtti*, void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::InternalInitializer::terminate_staticlib() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::InternalInitializer::initialize_staticlib(Json2::InitParameter const*, Json2::InternalInitializer::InitOption) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

PS4_SYSV_ABI Json2::InternalInitializer::InternalInitializer() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::InternalInitializer::~InternalInitializer() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

s32 PS4_SYSV_ABI Free(void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::push_front(Json2::Value const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::clear() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::erase(Json2::Array::iterator const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::insert(Json2::Array::iterator const&, Json2::Value const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::iterator::advance(unsigned long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::iterator::operator=(Json2::Array::iterator const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

PS4_SYSV_ABI Json2::Array::iterator::iterator(Json2::Array::iterator const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Array::iterator::iterator() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Array::iterator::~iterator() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

s32 PS4_SYSV_ABI Json2::Array::iterator::operator++(int) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::iterator::operator++() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::pop_back() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::pop_front() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::push_back(Json2::Value const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::operator=(Json2::Array const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

PS4_SYSV_ABI Json2::Array::Array(Json2::Array const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Array::Array() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Array::~Array() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

s32 PS4_SYSV_ABI Json2::Value::referArray() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::referValue(unsigned long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::referValue(Json2::String const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::referObject() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::referString() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::referBoolean() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::referInteger() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::referUInteger() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::setNullAccessCallBack(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, void*), void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::setSpecialFloatHandler(Json2::Value const (*)(Json2::FunctionType, double, Json2::Value const*, void*, bool*), void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::setTypeMismatchHandler(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, Json2::Value const*, void*), void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::setElementAccessFailureHandler(void (*)(int, Json2::String const*, unsigned long const*, Json2::Value const*, Json2::Value const*, void*), void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::set(bool) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::set(double) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::set(long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::set(unsigned long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::set(Json2::ValueType) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::set(char const*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::set(Json2::Array const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::set(Json2::Object const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::set(Json2::String const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::set(Json2::Value const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::swap(Json2::Value&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::clear() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::referReal() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::serialize(int (*)(Json2::String&, void*), void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::serialize(Json2::String&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::serialize(Json2::String&, int (*)(Json2::String&, void*), void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::operator=(Json2::Value const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

PS4_SYSV_ABI Json2::Value::Value(bool) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Value::Value(double) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Value::Value(long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Value::Value(unsigned long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Value::Value(Json2::ValueType) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Value::Value(char const*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Value::Value(Json2::Array const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Value::Value(Json2::Object const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Value::Value(Json2::String const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Value::Value(Json2::Value const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Value::Value() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Value::~Value() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

s32 PS4_SYSV_ABI Malloc(unsigned long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

PS4_SYSV_ABI Json2::Object::Pair::Pair(Json2::String const&, Json2::Value const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Object::Pair::Pair() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Object::Pair::~Pair() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

s32 PS4_SYSV_ABI Json2::Object::clear() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::erase(Json2::String const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::insert(Json2::Object::Pair const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::iterator::advance(unsigned long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::iterator::operator=(Json2::Object::iterator const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

PS4_SYSV_ABI Json2::Object::iterator::iterator(Json2::Object::iterator const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Object::iterator::iterator() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Object::iterator::~iterator() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

s32 PS4_SYSV_ABI Json2::Object::iterator::operator++(int) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::iterator::operator++() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::operator=(Json2::Object const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

PS4_SYSV_ABI Json2::Object::Object(Json2::Object const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Object::Object() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::Object::~Object() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

s32 PS4_SYSV_ABI Json2::Object::operator[](Json2::String const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Parser::parse(Json2::Value&, int (*)(char&, void*), void*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Parser::parse(Json2::Value&, char const*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Parser::parse(Json2::Value&, char const*, unsigned long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::clear() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::append(char const*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::append(char const*, unsigned long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::append(Json2::String const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::resize(unsigned long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::reserve(unsigned long) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::operator=(Json2::String const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

PS4_SYSV_ABI Json2::String::String(char const*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::String::String(Json2::String const&) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::String::String() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

PS4_SYSV_ABI Json2::String::~String() {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return;
}

s32 PS4_SYSV_ABI Json2::String::operator+=(unsigned char) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::operator+=(char const*) {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::InitParameter2::getUserData() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::InitParameter2::getAllocator() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::InitParameter2::getFileBufferSize() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::InitParameter2::getSpecialFloatFormatType() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::end() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::back() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::size() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::begin() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::empty() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::front() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::iterator::operator*() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::iterator::operator!=(Json2::Array::iterator const&) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Array::iterator::operator->() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::getBoolean() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::getInteger() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::getUInteger() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::count() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::getReal() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::getType() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::getArray() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::getValue(unsigned long) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::getValue(Json2::String const&) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::toString(Json2::String&) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::getObject() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::getString() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

PS4_SYSV_ABI Json2::Value::operator bool() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return true;
}

s32 PS4_SYSV_ABI Json2::Value::operator[](unsigned long) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::operator[](char const*) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Value::operator[](Json2::String const&) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::end() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::find(Json2::String const&) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::size() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::begin() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::empty() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::iterator::operator*() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::iterator::operator==(Json2::Object::iterator const&) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::iterator::operator!=(Json2::Object::iterator const&) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::Object::iterator::operator->() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::at(unsigned long) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::find(char, unsigned long) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::find(char const*, unsigned long) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::find(char const*, unsigned long, unsigned long) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::find(Json2::String const&, unsigned long) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::size() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::c_str() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::empty() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::rfind(char, unsigned long) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::rfind(char const*, unsigned long) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::rfind(char const*, unsigned long, unsigned long) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::rfind(Json2::String const&, unsigned long) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::length() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::substr(unsigned long, unsigned long) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::compare(char const*) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::compare(Json2::String const&) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::capacity() const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::operator==(char const*) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

s32 PS4_SYSV_ABI Json2::String::operator==(Json2::String const&) const {
    LOG_ERROR(Lib_Json2, "(STUBBED) called");
    return ORBIS_OK;
}

void RegisterLib(Core::Loader::SymbolsResolver* sym) {
    constexpr const char* j = "libSceJson";
    constexpr const char* j2 = "libSceJson2";

    // LIB_FUNCTION("Cxwy7wHq4J0", j2, 1, j, 1, 1, Json2::Initializer::initialize(Json2::InitParameter const*));
    LIB_OVERLOADED_MEMBER_FUNCTION("Cxwy7wHq4J0", j2, 1, j, 1, 1, Json2::Initializer, initialize, s32 (Json2::Initializer::*)(Json2::InitParameter const*));
    // LIB_FUNCTION("IXW-z8pggfg", j2, 1, j, 1, 1, Json2::Initializer::initialize(Json2::InitParameter2 const*));
    LIB_OVERLOADED_MEMBER_FUNCTION("IXW-z8pggfg", j2, 1, j, 1, 1, Json2::Initializer, initialize, s32 (Json2::Initializer::*)(Json2::InitParameter2 const*));

    // LIB_FUNCTION("R996H0YIhiQ", j2, 1, j, 1, 1, Json2::Initializer::setAllocatorInfoCallBack(void (*)(int, Json2::ValueType, void*), void*));
    LIB_OVERLOADED_MEMBER_FUNCTION("R996H0YIhiQ", j2, 1, j, 1, 1, Json2::Initializer, setAllocatorInfoCallBack, s32 (Json2::Initializer::*)(void (*)(int, Json2::ValueType, void*), void*));

    // LIB_FUNCTION("cK6bYHf-Q5E", j2, 1, j, 1, 1, Json2::Initializer::Initializer());
    LIB_FUNCTION("cK6bYHf-Q5E", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Initializer>));
    // LIB_FUNCTION("RujUxbr3haM", j2, 1, j, 1, 1, Json2::Initializer::~Initializer());
    LIB_FUNCTION("RujUxbr3haM", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Initializer>));

    // LIB_FUNCTION("+drDFyAS6u4", j2, 1, j, 1, 1, Json2::Initializer::setGlobalNullAccessCallback(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, void*), void*));
    LIB_OVERLOADED_MEMBER_FUNCTION("+drDFyAS6u4", j2, 1, j, 1, 1, Json2::Initializer, setGlobalNullAccessCallback, s32 (Json2::Initializer::*)(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, void*), void*));

    // LIB_FUNCTION("UeuWT+yNdCQ", j2, 1, j, 1, 1, Json2::Value::Value(bool));
    LIB_FUNCTION("UeuWT+yNdCQ", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, bool>));
    LIB_OVERLOADED_MEMBER_FUNCTION("i1393UBWu1U", j2, 1, j, 1, 1, Json2::Initializer, setGlobalSpecialFloatHandler, s32 (Json2::Initializer::*)(Json2::Value const (*)(Json2::FunctionType, double, Json2::Value const*, void*, bool*), void*));
    LIB_OVERLOADED_MEMBER_FUNCTION("tck9g-yOqPg", j2, 1, j, 1, 1, Json2::Initializer, setGlobalTypeMismatchHandler, s32 (Json2::Initializer::*)(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, Json2::Value const*, void*), void*));
    LIB_OVERLOADED_MEMBER_FUNCTION("j8Q7SBgMm28", j2, 1, j, 1, 1, Json2::Initializer, setGlobalElementAccessFailureHandler, s32 (Json2::Initializer::*)(void (*)(int, Json2::String const*, unsigned long const*, Json2::Value const*, Json2::Value const*, void*), void*));
    LIB_OVERLOADED_MEMBER_FUNCTION("PR5k1penBLM", j2, 1, j, 1, 1, Json2::Initializer, terminate, s32 (Json2::Initializer::*)());
    LIB_FUNCTION("cK6bYHf-Q5E", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Initializer>));
    LIB_FUNCTION("6qFqND4iwPA", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Initializer>));
    LIB_FUNCTION("RujUxbr3haM", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Initializer>));
    LIB_FUNCTION("qQZGdYkEytk", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Initializer>));
    LIB_OVERLOADED_MEMBER_FUNCTION("i-XwZjw0OOY", j2, 1, j, 1, 1, Json2::MemAllocator, notifyError, s32 (Json2::MemAllocator::*)(int, unsigned long, void*));
    LIB_FUNCTION("-hJRce8wn1U", j2, 1, j, 1, 1, (ctor_wrapper<Json2::MemAllocator>));
    LIB_FUNCTION("ypazoTrKYhE", j2, 1, j, 1, 1, (dtor_wrapper<Json2::MemAllocator>));
    LIB_FUNCTION("O1uwoqazS2A", j2, 1, j, 1, 1, (dtor_wrapper<Json2::MemAllocator>));
    LIB_FUNCTION("OcAgPxcq5Vk", j2, 1, j, 1, 1, (dtor_wrapper<Json2::MemAllocator>));
    LIB_OVERLOADED_MEMBER_FUNCTION("I2QC8PYhJWY", j2, 1, j, 1, 1, Json2::InitParameter2, setAllocator, s32 (Json2::InitParameter2::*)(Json2::MemAllocator*, void*));
    LIB_OVERLOADED_MEMBER_FUNCTION("Eu95jmqn5Rw", j2, 1, j, 1, 1, Json2::InitParameter2, setFileBufferSize, s32 (Json2::InitParameter2::*)(unsigned long));
    LIB_OVERLOADED_MEMBER_FUNCTION("WVZBP4IyM+E", j2, 1, j, 1, 1, Json2::InitParameter2, setSpecialFloatFormatType, s32 (Json2::InitParameter2::*)(Json2::SpecialFloatFormatType));
    LIB_FUNCTION("WSOuge5IsCg", j2, 1, j, 1, 1, (ctor_wrapper<Json2::InitParameter2>));
    LIB_FUNCTION("GvGvswb0v34", j2, 1, j, 1, 1, (ctor_wrapper<Json2::InitParameter2>));
    LIB_FUNCTION("6i18OJSvFWk", j2, 1, j, 1, 1, (ctor_wrapper<Json2::InitParameterRtti, Json2::AllocParamRtti*, void*, unsigned long>));
    LIB_FUNCTION("Mp8DPb3M4I0", j2, 1, j, 1, 1, (ctor_wrapper<Json2::InitParameterRtti, Json2::AllocParamRtti*, void*, unsigned long>));
    LIB_OVERLOADED_MEMBER_FUNCTION("W72B9ylU2JA", j2, 1, j, 1, 1, Json2::InitParameterRtti2, setAllocatorRtti, s32 (Json2::InitParameterRtti2::*)(Json2::AllocParamRtti*, void*));
    LIB_OVERLOADED_MEMBER_FUNCTION("dvp2zGSQzMs", j2, 1, j, 1, 1, Json2::InternalInitializer, terminate_staticlib, s32 (Json2::InternalInitializer::*)());
    LIB_OVERLOADED_MEMBER_FUNCTION("BPSPc3pUMJo", j2, 1, j, 1, 1, Json2::InternalInitializer, initialize_staticlib, s32 (Json2::InternalInitializer::*)(Json2::InitParameter const*, Json2::InternalInitializer::InitOption));
    LIB_FUNCTION("WntRKhYTmZw", j2, 1, j, 1, 1, (ctor_wrapper<Json2::InternalInitializer>));
    LIB_FUNCTION("2n+fxNdSZfs", j2, 1, j, 1, 1, (ctor_wrapper<Json2::InternalInitializer>));
    LIB_FUNCTION("yudT4-bglko", j2, 1, j, 1, 1, (dtor_wrapper<Json2::InternalInitializer>));
    LIB_FUNCTION("caP-y4fH-zQ", j2, 1, j, 1, 1, (dtor_wrapper<Json2::InternalInitializer>));
    LIB_FUNCTION("bnk+edDbqMk", j2, 1, j, 1, 1, Json2::Free);
    LIB_OVERLOADED_MEMBER_FUNCTION("MQxDxBzWz40", j2, 1, j, 1, 1, Json2::Array, push_front, s32 (Json2::Array::*)(Json2::Value const&));
    LIB_OVERLOADED_MEMBER_FUNCTION("qVOSuDRHCpA", j2, 1, j, 1, 1, Json2::Array, clear, s32 (Json2::Array::*)());
    LIB_OVERLOADED_MEMBER_FUNCTION("2mbVAtshWRI", j2, 1, j, 1, 1, Json2::Array, erase, s32 (Json2::Array::*)(Json2::Array::iterator const&));
    LIB_OVERLOADED_MEMBER_FUNCTION("ixJAz92H1uE", j2, 1, j, 1, 1, Json2::Array, insert, s32 (Json2::Array::*)(Json2::Array::iterator const&, Json2::Value const&));
    LIB_OVERLOADED_MEMBER_FUNCTION("43MESLndGvQ", j2, 1, j, 1, 1, Json2::Array::iterator, advance, s32 (Json2::Array::iterator::*)(unsigned long));
    LIB_OVERLOADED_MEMBER_FUNCTION("T3WReElX4BY", j2, 1, j, 1, 1, Json2::Array::iterator, operator=, s32 (Json2::Array::iterator::*)(Json2::Array::iterator const&));
    LIB_FUNCTION("IaIvX3kgyb0", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array::iterator, Json2::Array::iterator const&>));
    LIB_FUNCTION("TAPTWYaYf8Q", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array::iterator>));
    LIB_FUNCTION("Hdc3DSIsG2I", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array::iterator, Json2::Array::iterator const&>));
    LIB_FUNCTION("JSg1MSo7NKE", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array::iterator>));
    LIB_FUNCTION("9yLjn46Ypfs", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Array::iterator>));
    LIB_FUNCTION("9niNrXsF3Bc", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Array::iterator>));
    LIB_OVERLOADED_MEMBER_FUNCTION("GEylwSsiGG8", j2, 1, j, 1, 1, Json2::Array::iterator, operator++, s32 (Json2::Array::iterator::*)(int));
    LIB_OVERLOADED_MEMBER_FUNCTION("w5+VCznos5E", j2, 1, j, 1, 1, Json2::Array::iterator, operator++, s32 (Json2::Array::iterator::*)());
    LIB_OVERLOADED_MEMBER_FUNCTION("woec1toi4Xw", j2, 1, j, 1, 1, Json2::Array, pop_back, s32 (Json2::Array::*)());
    LIB_OVERLOADED_MEMBER_FUNCTION("pPs3qZTZQvQ", j2, 1, j, 1, 1, Json2::Array, pop_front, s32 (Json2::Array::*)());
    LIB_OVERLOADED_MEMBER_FUNCTION("zQtLRTqceMY", j2, 1, j, 1, 1, Json2::Array, push_back, s32 (Json2::Array::*)(Json2::Value const&));
    LIB_OVERLOADED_MEMBER_FUNCTION("w5UbvPLGye0", j2, 1, j, 1, 1, Json2::Array, operator=, s32 (Json2::Array::*)(Json2::Array const&));
    LIB_FUNCTION("bI5AGFMydrA", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array, Json2::Array const&>));
    LIB_FUNCTION("JP-PtKMiI1E", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array>));
    LIB_FUNCTION("6NlbpyIfUuY", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array, Json2::Array const&>));
    LIB_FUNCTION("t6AHhkWu4mY", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array>));
    LIB_FUNCTION("HJ8GpRT1aiw", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Array>));
    LIB_FUNCTION("MIyMPw7YTGM", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Array>));

    LIB_MEMBER_FUNCTION("nM5XqdeXFPw", j2, 1, j, 1, 1, Json2::Value, referArray);
    // LIB_FUNCTION("gLzCc67aTbw", j2, 1, j, 1, 1, Json2::Value::referValue(unsigned long));
    // LIB_FUNCTION("wLsJlmgEIaI", j2, 1, j, 1, 1, Json2::Value::referValue(Json2::String const&));
    // LIB_FUNCTION("bUw2Go-rxtE", j2, 1, j, 1, 1, Json2::Value::s_nullbool);
    // LIB_FUNCTION("GpEG1IcP86s", j2, 1, j, 1, 1, Json2::Value::s_nullreal);
    // LIB_FUNCTION("-NxEk7XLkDY", j2, 1, j, 1, 1, Json2::Value::referObject());
    // LIB_FUNCTION("m5J28iw-QPs", j2, 1, j, 1, 1, Json2::Value::referString());
    // LIB_FUNCTION("zwDiN3-CRTA", j2, 1, j, 1, 1, Json2::Value::s_nullarray);
    // LIB_FUNCTION("QxjfcfBhEdc", j2, 1, j, 1, 1, Json2::Value::referBoolean());
    // LIB_FUNCTION("R0ac5QOdlpo", j2, 1, j, 1, 1, Json2::Value::referInteger());
    // LIB_FUNCTION("3YODFwSqgtc", j2, 1, j, 1, 1, Json2::Value::s_nullobject);
    // LIB_FUNCTION("24kDIV0aDzs", j2, 1, j, 1, 1, Json2::Value::s_nullstring);
    // LIB_FUNCTION("Nx5tez4siL4", j2, 1, j, 1, 1, Json2::Value::referUInteger());
    // LIB_FUNCTION("dJSD90mnj1w", j2, 1, j, 1, 1, Json2::Value::s_nullinteger);
    // LIB_FUNCTION("xxBnIBiUVzY", j2, 1, j, 1, 1, Json2::Value::s_nulluinteger);
    // LIB_FUNCTION("Xbl-LYVFNEE", j2, 1, j, 1, 1, Json2::Value::setNullAccessCallBack(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, void*), void*));
    // LIB_FUNCTION("bJWBpvGCIJU", j2, 1, j, 1, 1, Json2::Value::setSpecialFloatHandler(Json2::Value const (*)(Json2::FunctionType, double, Json2::Value const*, void*, bool*), void*));
    // LIB_FUNCTION("ukQodCmg99s", j2, 1, j, 1, 1, Json2::Value::setTypeMismatchHandler(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, Json2::Value const*, void*), void*));
    // LIB_FUNCTION("6tTbrt1O1SY", j2, 1, j, 1, 1, Json2::Value::setElementAccessFailureHandler(void (*)(int, Json2::String const*, unsigned long const*, Json2::Value const*, Json2::Value const*, void*), void*));
    // LIB_FUNCTION("5yHuiWXo2gg", j2, 1, j, 1, 1, Json2::Value::set(bool));
    // LIB_FUNCTION("BSmWDIkV4w4", j2, 1, j, 1, 1, Json2::Value::set(double));
    // LIB_FUNCTION("QxVVYhP-mvg", j2, 1, j, 1, 1, Json2::Value::set(long));
    // LIB_FUNCTION("SIe1ZmW7e7s", j2, 1, j, 1, 1, Json2::Value::set(unsigned long));
    // LIB_FUNCTION("IKQimvG9Wqs", j2, 1, j, 1, 1, Json2::Value::set(Json2::ValueType));
    // LIB_FUNCTION("n6FC+l9DU70", j2, 1, j, 1, 1, Json2::Value::set(char const*));
    // LIB_FUNCTION("195ad-jAsTU", j2, 1, j, 1, 1, Json2::Value::set(Json2::Array const&));
    // LIB_FUNCTION("dFCphqnd+a4", j2, 1, j, 1, 1, Json2::Value::set(Json2::Object const&));
    // LIB_FUNCTION("6l3Bv2gysNc", j2, 1, j, 1, 1, Json2::Value::set(Json2::String const&));
    // LIB_FUNCTION("XL8+BUqjB1w", j2, 1, j, 1, 1, Json2::Value::set(Json2::Value const&));
    // LIB_FUNCTION("9PqrCLfKZZI", j2, 1, j, 1, 1, Json2::Value::swap(Json2::Value&));
    // LIB_FUNCTION("FIjXN2TkuTs", j2, 1, j, 1, 1, Json2::Value::clear());
    // LIB_FUNCTION("t7UEJrhojhk", j2, 1, j, 1, 1, Json2::Value::referReal());
    // LIB_FUNCTION("PyMbL9F2oBY", j2, 1, j, 1, 1, Json2::Value::serialize(int (*)(Json2::String&, void*), void*));
    // LIB_FUNCTION("R7FDWtcN6f8", j2, 1, j, 1, 1, Json2::Value::serialize(Json2::String&));
    // LIB_FUNCTION("l1URiQJlSoU", j2, 1, j, 1, 1, Json2::Value::serialize(Json2::String&, int (*)(Json2::String&, void*), void*));
    // LIB_FUNCTION("4zrm6VrgIAw", j2, 1, j, 1, 1, Json2::Value::operator=(Json2::Value const&));
    // LIB_FUNCTION("UeuWT+yNdCQ", j2, 1, j, 1, 1, Json2::Value::Value(bool));
    // LIB_FUNCTION("sOmU4vnx3s0", j2, 1, j, 1, 1, Json2::Value::Value(double));
    // LIB_FUNCTION("0lLK8+kDqmE", j2, 1, j, 1, 1, Json2::Value::Value(long));
    // LIB_FUNCTION("x4AUdbhpRB0", j2, 1, j, 1, 1, Json2::Value::Value(unsigned long));
    // LIB_FUNCTION("CbrT3dwDILo", j2, 1, j, 1, 1, Json2::Value::Value(Json2::ValueType));
    // LIB_FUNCTION("b9V6fmppLXY", j2, 1, j, 1, 1, Json2::Value::Value(char const*));
    // LIB_FUNCTION("iZeYfOxtMRg", j2, 1, j, 1, 1, Json2::Value::Value(Json2::Array const&));
    // LIB_FUNCTION("3xUXnmUkXfo", j2, 1, j, 1, 1, Json2::Value::Value(Json2::Object const&));
    // LIB_FUNCTION("sZIoMRGO+jk", j2, 1, j, 1, 1, Json2::Value::Value(Json2::String const&));
    // LIB_FUNCTION("fSb2oQTNrgA", j2, 1, j, 1, 1, Json2::Value::Value(Json2::Value const&));
    // LIB_FUNCTION("qBMjqyBn3OM", j2, 1, j, 1, 1, Json2::Value::Value());
    // LIB_FUNCTION("OK4Ot0ue7J0", j2, 1, j, 1, 1, Json2::Value::Value(bool));
    // LIB_FUNCTION("23nm4oXHlfI", j2, 1, j, 1, 1, Json2::Value::Value(double));
    // LIB_FUNCTION("EjxUpzR2Yx8", j2, 1, j, 1, 1, Json2::Value::Value(long));
    // LIB_FUNCTION("cqucBPSeVDA", j2, 1, j, 1, 1, Json2::Value::Value(unsigned long));
    // LIB_FUNCTION("PWm9MyJJVqU", j2, 1, j, 1, 1, Json2::Value::Value(Json2::ValueType));
    // LIB_FUNCTION("+hHa4QYtLY8", j2, 1, j, 1, 1, Json2::Value::Value(char const*));
    // LIB_FUNCTION("VH9dsKpQTmk", j2, 1, j, 1, 1, Json2::Value::Value(Json2::Array const&));
    // LIB_FUNCTION("JXlrCLLCLmc", j2, 1, j, 1, 1, Json2::Value::Value(Json2::Object const&));
    // LIB_FUNCTION("veNviXt6wC0", j2, 1, j, 1, 1, Json2::Value::Value(Json2::String const&));
    // LIB_FUNCTION("TZyuFeGuw9Y", j2, 1, j, 1, 1, Json2::Value::Value(Json2::Value const&));
    // LIB_FUNCTION("-wa17B7TGnw", j2, 1, j, 1, 1, Json2::Value::Value());
    // LIB_FUNCTION("WTtYf+cNnXI", j2, 1, j, 1, 1, Json2::Value::~Value());
    // LIB_FUNCTION("0eUrW9JAxM0", j2, 1, j, 1, 1, Json2::Value::~Value());
    // LIB_FUNCTION("Xzy0onDzSAc", j2, 1, j, 1, 1, Json2::Malloc(unsigned long));
    // LIB_FUNCTION("+hYsagaV-Ug", j2, 1, j, 1, 1, Json2::Object::Pair::Pair(Json2::String const&, Json2::Value const&));
    // LIB_FUNCTION("-uQnUEENfpk", j2, 1, j, 1, 1, Json2::Object::Pair::Pair());
    // LIB_FUNCTION("lt3J4dPvEtM", j2, 1, j, 1, 1, Json2::Object::Pair::Pair(Json2::String const&, Json2::Value const&));
    // LIB_FUNCTION("Wu-urs6MMpQ", j2, 1, j, 1, 1, Json2::Object::Pair::Pair());
    // LIB_FUNCTION("Q0ng4sWj2E8", j2, 1, j, 1, 1, Json2::Object::Pair::~Pair());
    // LIB_FUNCTION("TM0Sj+Ebins", j2, 1, j, 1, 1, Json2::Object::Pair::~Pair());
    // LIB_FUNCTION("oH8aBmLU+fc", j2, 1, j, 1, 1, Json2::Object::clear());
    // LIB_FUNCTION("3ZhL-MkICwI", j2, 1, j, 1, 1, Json2::Object::erase(Json2::String const&));
    // LIB_FUNCTION("ol7KhQl8kfw", j2, 1, j, 1, 1, Json2::Object::insert(Json2::Object::Pair const&));
    // LIB_FUNCTION("h-V8r4EF7bo", j2, 1, j, 1, 1, Json2::Object::iterator::advance(unsigned long));
    // LIB_FUNCTION("w7nqTT3zgxU", j2, 1, j, 1, 1, Json2::Object::iterator::operator=(Json2::Object::iterator const&));
    // LIB_FUNCTION("JATlaeBu+lU", j2, 1, j, 1, 1, Json2::Object::iterator::iterator(Json2::Object::iterator const&));
    // LIB_FUNCTION("a2Zv3idT0sU", j2, 1, j, 1, 1, Json2::Object::iterator::iterator());
    // LIB_FUNCTION("r5CShmcua+M", j2, 1, j, 1, 1, Json2::Object::iterator::iterator(Json2::Object::iterator const&));
    // LIB_FUNCTION("OxO+V0ouoS4", j2, 1, j, 1, 1, Json2::Object::iterator::iterator());
    // LIB_FUNCTION("hoINmSMlYjI", j2, 1, j, 1, 1, Json2::Object::iterator::~iterator());
    // LIB_FUNCTION("patTzc7zBjw", j2, 1, j, 1, 1, Json2::Object::iterator::~iterator());
    // LIB_FUNCTION("dIVxrrdpS9M", j2, 1, j, 1, 1, Json2::Object::iterator::operator++(int));
    // LIB_FUNCTION("DlWmn2ZQuWY", j2, 1, j, 1, 1, Json2::Object::iterator::operator++());
    // LIB_FUNCTION("urOpESTBZmo", j2, 1, j, 1, 1, Json2::Object::operator=(Json2::Object const&));
    // LIB_FUNCTION("a+W7HHlwpBs", j2, 1, j, 1, 1, Json2::Object::Object(Json2::Object const&));
    // LIB_FUNCTION("OJPTonqdg0I", j2, 1, j, 1, 1, Json2::Object::Object());
    // LIB_FUNCTION("tSRqQ-+Y4PE", j2, 1, j, 1, 1, Json2::Object::Object(Json2::Object const&));
    // LIB_FUNCTION("SkKczWHdklc", j2, 1, j, 1, 1, Json2::Object::Object());
    // LIB_FUNCTION("5JmzZt8twAo", j2, 1, j, 1, 1, Json2::Object::~Object());
    // LIB_FUNCTION("1siRBursJjw", j2, 1, j, 1, 1, Json2::Object::~Object());
    // LIB_FUNCTION("ERuf9y0DY84", j2, 1, j, 1, 1, Json2::Object::operator[](Json2::String const&));
    // LIB_FUNCTION("itqj2YmuAa8", j2, 1, j, 1, 1, Json2::Parser::parse(Json2::Value&, int (*)(char&, void*), void*));
    // LIB_FUNCTION("LB3jxppxyKU", j2, 1, j, 1, 1, Json2::Parser::parse(Json2::Value&, char const*));
    // LIB_FUNCTION("S5JxQnoGF3E", j2, 1, j, 1, 1, Json2::Parser::parse(Json2::Value&, char const*, unsigned long));
    // LIB_FUNCTION("pCF8Ohwre44", j2, 1, j, 1, 1, Json2::String::npos);
    // LIB_FUNCTION("A+FhGENHV-E", j2, 1, j, 1, 1, Json2::String::clear());
    // LIB_FUNCTION("Va5FJ6TmNCw", j2, 1, j, 1, 1, Json2::String::append(char const*));
    // LIB_FUNCTION("bREqDgXlqDU", j2, 1, j, 1, 1, Json2::String::append(char const*, unsigned long));
    // LIB_FUNCTION("Rz00kiTKypo", j2, 1, j, 1, 1, Json2::String::append(Json2::String const&));
    // LIB_FUNCTION("PiR0tiTnNbM", j2, 1, j, 1, 1, Json2::String::resize(unsigned long));
    // LIB_FUNCTION("Z9tyi1-LrQg", j2, 1, j, 1, 1, Json2::String::reserve(unsigned long));
    // LIB_FUNCTION("cn9svYGWKDQ", j2, 1, j, 1, 1, Json2::String::operator=(Json2::String const&));
    // LIB_FUNCTION("9KUZFjI1IxA", j2, 1, j, 1, 1, Json2::String::String(char const*));
    // LIB_FUNCTION("0CAesfH963Q", j2, 1, j, 1, 1, Json2::String::String(Json2::String const&));
    // LIB_FUNCTION("qSmqLXXCPas", j2, 1, j, 1, 1, Json2::String::String());
    // LIB_FUNCTION("N78gkQzXRL4", j2, 1, j, 1, 1, Json2::String::String(char const*));
    // LIB_FUNCTION("gALFgNfF+9I", j2, 1, j, 1, 1, Json2::String::String(Json2::String const&));
    // LIB_FUNCTION("eG9E9M6XvTM", j2, 1, j, 1, 1, Json2::String::String());
    // LIB_FUNCTION("cG1VE2HMl6c", j2, 1, j, 1, 1, Json2::String::~String());
    // LIB_FUNCTION("Ui7YFnSTCBw", j2, 1, j, 1, 1, Json2::String::~String());
    // LIB_FUNCTION("-Wek6mFXOrc", j2, 1, j, 1, 1, Json2::String::operator+=(unsigned char));
    // LIB_FUNCTION("aVDQZGAqOo8", j2, 1, j, 1, 1, Json2::String::operator+=(char const*));
    // LIB_FUNCTION("GWtzpTKbZ+0", j2, 1, j, 1, 1, Json2::InitParameter2::getUserData() const);
    // LIB_FUNCTION("BykPm1ajcM0", j2, 1, j, 1, 1, Json2::InitParameter2::getAllocator() const);
    // LIB_FUNCTION("Pcg6xQUhq9E", j2, 1, j, 1, 1, Json2::InitParameter2::getFileBufferSize() const);
    // LIB_FUNCTION("PDkib0zyABg", j2, 1, j, 1, 1, Json2::InitParameter2::getSpecialFloatFormatType() const);
    // LIB_FUNCTION("WXF2ihRF+B8", j2, 1, j, 1, 1, Json2::Array::end() const);
    // LIB_FUNCTION("bAM9Qwofus0", j2, 1, j, 1, 1, Json2::Array::back() const);
    // LIB_FUNCTION("rQGJeNjOuUk", j2, 1, j, 1, 1, Json2::Array::size() const);
    // LIB_FUNCTION("bcH5EnFE2xY", j2, 1, j, 1, 1, Json2::Array::begin() const);
    // LIB_FUNCTION("9uP25i6ipno", j2, 1, j, 1, 1, Json2::Array::empty() const);
    // LIB_FUNCTION("zcfZQyM7eAE", j2, 1, j, 1, 1, Json2::Array::front() const);
    // LIB_FUNCTION("wcgr5mte7T8", j2, 1, j, 1, 1, Json2::Array::iterator::operator*() const);
    // LIB_FUNCTION("5AZPp99ogrc", j2, 1, j, 1, 1, Json2::Array::iterator::operator!=(Json2::Array::iterator const&) const);
    // LIB_FUNCTION("iAIYn4oAWvI", j2, 1, j, 1, 1, Json2::Array::iterator::operator->() const);
    // LIB_FUNCTION("zTwZdI8AZ5Y", j2, 1, j, 1, 1, Json2::Value::getBoolean() const);
    // LIB_FUNCTION("DIxvoy7Ngvk", j2, 1, j, 1, 1, Json2::Value::getInteger() const);
    // LIB_FUNCTION("sn4HNCtNRzY", j2, 1, j, 1, 1, Json2::Value::getUInteger() const);
    // LIB_FUNCTION("RBw+4NukeGQ", j2, 1, j, 1, 1, Json2::Value::count() const);
    // LIB_FUNCTION("3qrge7L-AU4", j2, 1, j, 1, 1, Json2::Value::getReal() const);
    // LIB_FUNCTION("SHtAad20YYM", j2, 1, j, 1, 1, Json2::Value::getType() const);
    // LIB_FUNCTION("ONT8As5R1ug", j2, 1, j, 1, 1, Json2::Value::getArray() const);
    // LIB_FUNCTION("0YqYAoO-+Uo", j2, 1, j, 1, 1, Json2::Value::getValue(unsigned long) const);
    // LIB_FUNCTION("MsMOdxWfbwQ", j2, 1, j, 1, 1, Json2::Value::getValue(Json2::String const&) const);
    // LIB_FUNCTION("Ncel8t2Rrpc", j2, 1, j, 1, 1, Json2::Value::toString(Json2::String&) const);
    // LIB_FUNCTION("IlsmvBtMkak", j2, 1, j, 1, 1, Json2::Value::getObject() const);
    // LIB_FUNCTION("epJ6x2LV0kU", j2, 1, j, 1, 1, Json2::Value::getString() const);
    // LIB_FUNCTION("a-aMMUXqrN0", j2, 1, j, 1, 1, Json2::Value::operator bool() const);
    // LIB_FUNCTION("XlWbvieLj2M", j2, 1, j, 1, 1, Json2::Value::operator[](unsigned long) const);
    // LIB_FUNCTION("HwDt5lD9Bfo", j2, 1, j, 1, 1, Json2::Value::operator[](char const*) const);
    // LIB_FUNCTION("clF7J7N9xXE", j2, 1, j, 1, 1, Json2::Value::operator[](Json2::String const&) const);
    // LIB_FUNCTION("ivMCitpSQNk", j2, 1, j, 1, 1, Json2::Object::end() const);
    // LIB_FUNCTION("ehN1Biw3tw8", j2, 1, j, 1, 1, Json2::Object::find(Json2::String const&) const);
    // LIB_FUNCTION("fSGHm9RjN5U", j2, 1, j, 1, 1, Json2::Object::size() const);
    // LIB_FUNCTION("xhAcaIwnrgk", j2, 1, j, 1, 1, Json2::Object::begin() const);
    // LIB_FUNCTION("i2l3IYvQ9UE", j2, 1, j, 1, 1, Json2::Object::empty() const);
    // LIB_FUNCTION("ZCd6IYoD3Bc", j2, 1, j, 1, 1, Json2::Object::iterator::operator*() const);
    // LIB_FUNCTION("q3YO1c0RqFo", j2, 1, j, 1, 1, Json2::Object::iterator::operator==(Json2::Object::iterator const&) const);
    // LIB_FUNCTION("+isUKw4zud4", j2, 1, j, 1, 1, Json2::Object::iterator::operator!=(Json2::Object::iterator const&) const);
    // LIB_FUNCTION("EnesV4gXDtE", j2, 1, j, 1, 1, Json2::Object::iterator::operator->() const);
    // LIB_FUNCTION("KrKM-5SdQrA", j2, 1, j, 1, 1, Json2::String::at(unsigned long) const);
    // LIB_FUNCTION("x4SuxMR26I4", j2, 1, j, 1, 1, Json2::String::find(char, unsigned long) const);
    // LIB_FUNCTION("yjsf6SvXA08", j2, 1, j, 1, 1, Json2::String::find(char const*, unsigned long) const);
    // LIB_FUNCTION("wwDnDDsQVc0", j2, 1, j, 1, 1, Json2::String::find(char const*, unsigned long, unsigned long) const);
    // LIB_FUNCTION("awkeNR6Ukp8", j2, 1, j, 1, 1, Json2::String::find(Json2::String const&, unsigned long) const);
    // LIB_FUNCTION("UVBkipSD2sw", j2, 1, j, 1, 1, Json2::String::size() const);
    // LIB_FUNCTION("L1KAkYWml-M", j2, 1, j, 1, 1, Json2::String::c_str() const);
    // LIB_FUNCTION("wM4LO2iK3s8", j2, 1, j, 1, 1, Json2::String::empty() const);
    // LIB_FUNCTION("t+Dx3eQtBPQ", j2, 1, j, 1, 1, Json2::String::rfind(char, unsigned long) const);
    // LIB_FUNCTION("VpQBXbaHXOo", j2, 1, j, 1, 1, Json2::String::rfind(char const*, unsigned long) const);
    // LIB_FUNCTION("A29RHrlfTM0", j2, 1, j, 1, 1, Json2::String::rfind(char const*, unsigned long, unsigned long) const);
    // LIB_FUNCTION("-R9mdXBspeQ", j2, 1, j, 1, 1, Json2::String::rfind(Json2::String const&, unsigned long) const);
    // LIB_FUNCTION("EUH+EmT-v9E", j2, 1, j, 1, 1, Json2::String::length() const);
    // LIB_FUNCTION("8OCexW9qJgQ", j2, 1, j, 1, 1, Json2::String::substr(unsigned long, unsigned long) const);
    // LIB_FUNCTION("Yfw63FVJgtU", j2, 1, j, 1, 1, Json2::String::compare(char const*) const);
    // LIB_FUNCTION("PXIHOuLUN40", j2, 1, j, 1, 1, Json2::String::compare(Json2::String const&) const);
    // LIB_FUNCTION("q0qeup2r7hA", j2, 1, j, 1, 1, Json2::String::capacity() const);
    // LIB_FUNCTION("VbFjEs--uiA", j2, 1, j, 1, 1, Json2::String::operator==(char const*) const);
    // LIB_FUNCTION("DM43TNBBfb0", j2, 1, j, 1, 1, Json2::String::operator==(Json2::String const&) const);
};

} // namespace Libraries::Json2