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

#define LF LIB_FUNCTION
#define LMF LIB_MEMBER_FUNCTION
#define LOMF LIB_OVERLOADED_MEMBER_FUNCTION

void RegisterLib(Core::Loader::SymbolsResolver* sym) {
    constexpr const char* j = "libSceJson";
    constexpr const char* j2 = "libSceJson2";

    LF("bnk+edDbqMk", j2, 1, j, 1, 1, Json2::Free);
    LF("Xzy0onDzSAc", j2, 1, j, 1, 1, Json2::Malloc);

    // LF("Cxwy7wHq4J0", j2, 1, j, 1, 1, Json2::Initializer::initialize(Json2::InitParameter const*));
    LOMF("Cxwy7wHq4J0", j2, 1, j, 1, 1, Json2::Initializer, initialize, s32 (Json2::Initializer::*)(Json2::InitParameter const*));
    // LF("IXW-z8pggfg", j2, 1, j, 1, 1, Json2::Initializer::initialize(Json2::InitParameter2 const*));
    LOMF("IXW-z8pggfg", j2, 1, j, 1, 1, Json2::Initializer, initialize, s32 (Json2::Initializer::*)(Json2::InitParameter2 const*));

    // LF("R996H0YIhiQ", j2, 1, j, 1, 1, Json2::Initializer::setAllocatorInfoCallBack(void (*)(int, Json2::ValueType, void*), void*));
    LMF("R996H0YIhiQ", j2, 1, j, 1, 1, Json2::Initializer, setAllocatorInfoCallBack);

    // LF("cK6bYHf-Q5E", j2, 1, j, 1, 1, Json2::Initializer::Initializer());
    LF("cK6bYHf-Q5E", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Initializer>));
    // LF("RujUxbr3haM", j2, 1, j, 1, 1, Json2::Initializer::~Initializer());
    LF("RujUxbr3haM", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Initializer>));

    // LF("+drDFyAS6u4", j2, 1, j, 1, 1, Json2::Initializer::setGlobalNullAccessCallback(Json2::Value const& (*)(Json2::ValueType, Json2::Value const*, void*), void*));
    LMF("+drDFyAS6u4", j2, 1, j, 1, 1, Json2::Initializer, setGlobalNullAccessCallback);

    // LF("UeuWT+yNdCQ", j2, 1, j, 1, 1, Json2::Value::Value(bool));
    LF("UeuWT+yNdCQ", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, bool>));
    LMF("i1393UBWu1U", j2, 1, j, 1, 1, Json2::Initializer, setGlobalSpecialFloatHandler);
    LMF("tck9g-yOqPg", j2, 1, j, 1, 1, Json2::Initializer, setGlobalTypeMismatchHandler);
    LMF("j8Q7SBgMm28", j2, 1, j, 1, 1, Json2::Initializer, setGlobalElementAccessFailureHandler);
    LOMF("PR5k1penBLM", j2, 1, j, 1, 1, Json2::Initializer, terminate, s32 (Json2::Initializer::*)());
    LF("cK6bYHf-Q5E", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Initializer>));
    LF("6qFqND4iwPA", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Initializer>));
    LF("RujUxbr3haM", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Initializer>));
    LF("qQZGdYkEytk", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Initializer>));
    LOMF("i-XwZjw0OOY", j2, 1, j, 1, 1, Json2::MemAllocator, notifyError, s32 (Json2::MemAllocator::*)(int, unsigned long, void*));
    LF("-hJRce8wn1U", j2, 1, j, 1, 1, (ctor_wrapper<Json2::MemAllocator>));
    LF("ypazoTrKYhE", j2, 1, j, 1, 1, (dtor_wrapper<Json2::MemAllocator>));
    LF("O1uwoqazS2A", j2, 1, j, 1, 1, (dtor_wrapper<Json2::MemAllocator>));
    LF("OcAgPxcq5Vk", j2, 1, j, 1, 1, (dtor_wrapper<Json2::MemAllocator>));
    LOMF("I2QC8PYhJWY", j2, 1, j, 1, 1, Json2::InitParameter2, setAllocator, s32 (Json2::InitParameter2::*)(Json2::MemAllocator*, void*));
    LOMF("Eu95jmqn5Rw", j2, 1, j, 1, 1, Json2::InitParameter2, setFileBufferSize, s32 (Json2::InitParameter2::*)(unsigned long));
    LOMF("WVZBP4IyM+E", j2, 1, j, 1, 1, Json2::InitParameter2, setSpecialFloatFormatType, s32 (Json2::InitParameter2::*)(Json2::SpecialFloatFormatType));
    LF("WSOuge5IsCg", j2, 1, j, 1, 1, (ctor_wrapper<Json2::InitParameter2>));
    LF("GvGvswb0v34", j2, 1, j, 1, 1, (ctor_wrapper<Json2::InitParameter2>));
    LF("6i18OJSvFWk", j2, 1, j, 1, 1, (ctor_wrapper<Json2::InitParameterRtti, Json2::AllocParamRtti*, void*, unsigned long>));
    LF("Mp8DPb3M4I0", j2, 1, j, 1, 1, (ctor_wrapper<Json2::InitParameterRtti, Json2::AllocParamRtti*, void*, unsigned long>));
    LOMF("W72B9ylU2JA", j2, 1, j, 1, 1, Json2::InitParameterRtti2, setAllocatorRtti, s32 (Json2::InitParameterRtti2::*)(Json2::AllocParamRtti*, void*));
    LOMF("dvp2zGSQzMs", j2, 1, j, 1, 1, Json2::InternalInitializer, terminate_staticlib, s32 (Json2::InternalInitializer::*)());
    LOMF("BPSPc3pUMJo", j2, 1, j, 1, 1, Json2::InternalInitializer, initialize_staticlib, s32 (Json2::InternalInitializer::*)(Json2::InitParameter const*, Json2::InternalInitializer::InitOption));
    LF("WntRKhYTmZw", j2, 1, j, 1, 1, (ctor_wrapper<Json2::InternalInitializer>));
    LF("2n+fxNdSZfs", j2, 1, j, 1, 1, (ctor_wrapper<Json2::InternalInitializer>));
    LF("yudT4-bglko", j2, 1, j, 1, 1, (dtor_wrapper<Json2::InternalInitializer>));
    LF("caP-y4fH-zQ", j2, 1, j, 1, 1, (dtor_wrapper<Json2::InternalInitializer>));

    LOMF("MQxDxBzWz40", j2, 1, j, 1, 1, Json2::Array, push_front, s32 (Json2::Array::*)(Json2::Value const&));
    LOMF("qVOSuDRHCpA", j2, 1, j, 1, 1, Json2::Array, clear, s32 (Json2::Array::*)());
    LOMF("2mbVAtshWRI", j2, 1, j, 1, 1, Json2::Array, erase, s32 (Json2::Array::*)(Json2::Array::iterator const&));
    LOMF("ixJAz92H1uE", j2, 1, j, 1, 1, Json2::Array, insert, s32 (Json2::Array::*)(Json2::Array::iterator const&, Json2::Value const&));
    LOMF("43MESLndGvQ", j2, 1, j, 1, 1, Json2::Array::iterator, advance, s32 (Json2::Array::iterator::*)(unsigned long));
    LOMF("T3WReElX4BY", j2, 1, j, 1, 1, Json2::Array::iterator, operator=, s32 (Json2::Array::iterator::*)(Json2::Array::iterator const&));
    LF("IaIvX3kgyb0", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array::iterator, Json2::Array::iterator const&>));
    LF("TAPTWYaYf8Q", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array::iterator>));
    LF("Hdc3DSIsG2I", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array::iterator, Json2::Array::iterator const&>));
    LF("JSg1MSo7NKE", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array::iterator>));
    LF("9yLjn46Ypfs", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Array::iterator>));
    LF("9niNrXsF3Bc", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Array::iterator>));
    LOMF("GEylwSsiGG8", j2, 1, j, 1, 1, Json2::Array::iterator, operator++, s32 (Json2::Array::iterator::*)(int));
    LOMF("w5+VCznos5E", j2, 1, j, 1, 1, Json2::Array::iterator, operator++, s32 (Json2::Array::iterator::*)());
    LOMF("woec1toi4Xw", j2, 1, j, 1, 1, Json2::Array, pop_back, s32 (Json2::Array::*)());
    LOMF("pPs3qZTZQvQ", j2, 1, j, 1, 1, Json2::Array, pop_front, s32 (Json2::Array::*)());
    LOMF("zQtLRTqceMY", j2, 1, j, 1, 1, Json2::Array, push_back, s32 (Json2::Array::*)(Json2::Value const&));
    LOMF("w5UbvPLGye0", j2, 1, j, 1, 1, Json2::Array, operator=, s32 (Json2::Array::*)(Json2::Array const&));
    LF("bI5AGFMydrA", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array, Json2::Array const&>));
    LF("JP-PtKMiI1E", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array>));
    LF("6NlbpyIfUuY", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array, Json2::Array const&>));
    LF("t6AHhkWu4mY", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Array>));
    LF("HJ8GpRT1aiw", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Array>));
    LF("MIyMPw7YTGM", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Array>));

    LMF("nM5XqdeXFPw", j2, 1, j, 1, 1, Json2::Value, referArray);
    LOMF("gLzCc67aTbw", j2, 1, j, 1, 1, Json2::Value, referValue, s32 (Json2::Value::*)(unsigned long));
    LOMF("wLsJlmgEIaI", j2, 1, j, 1, 1, Json2::Value, referValue, s32 (Json2::Value::*)(Json2::String const&));
    LOMF("-NxEk7XLkDY", j2, 1, j, 1, 1, Json2::Value, referObject, s32 (Json2::Value::*)());
    LOMF("m5J28iw-QPs", j2, 1, j, 1, 1, Json2::Value, referString, s32 (Json2::Value::*)());
    LOMF("QxjfcfBhEdc", j2, 1, j, 1, 1, Json2::Value, referBoolean, s32 (Json2::Value::*)());
    LOMF("R0ac5QOdlpo", j2, 1, j, 1, 1, Json2::Value, referInteger, s32 (Json2::Value::*)());
    LOMF("Nx5tez4siL4", j2, 1, j, 1, 1, Json2::Value, referUInteger, s32 (Json2::Value::*)());
    LMF("Xbl-LYVFNEE", j2, 1, j, 1, 1, Json2::Value, setNullAccessCallBack);
    LMF("bJWBpvGCIJU", j2, 1, j, 1, 1, Json2::Value, setSpecialFloatHandler);
    LMF("ukQodCmg99s", j2, 1, j, 1, 1, Json2::Value, setTypeMismatchHandler);
    LMF("6tTbrt1O1SY", j2, 1, j, 1, 1, Json2::Value, setElementAccessFailureHandler);
    LOMF("5yHuiWXo2gg", j2, 1, j, 1, 1, Json2::Value, set, s32 (Json2::Value::*)(bool));
    LOMF("BSmWDIkV4w4", j2, 1, j, 1, 1, Json2::Value, set, s32 (Json2::Value::*)(double));
    LOMF("QxVVYhP-mvg", j2, 1, j, 1, 1, Json2::Value, set, s32 (Json2::Value::*)(long));
    LOMF("SIe1ZmW7e7s", j2, 1, j, 1, 1, Json2::Value, set, s32 (Json2::Value::*)(unsigned long));
    LOMF("IKQimvG9Wqs", j2, 1, j, 1, 1, Json2::Value, set, s32 (Json2::Value::*)(Json2::ValueType));
    LOMF("n6FC+l9DU70", j2, 1, j, 1, 1, Json2::Value, set, s32 (Json2::Value::*)(char const*));
    LOMF("195ad-jAsTU", j2, 1, j, 1, 1, Json2::Value, set, s32 (Json2::Value::*)(Json2::Array const&));
    LOMF("dFCphqnd+a4", j2, 1, j, 1, 1, Json2::Value, set, s32 (Json2::Value::*)(Json2::Object const&));
    LOMF("6l3Bv2gysNc", j2, 1, j, 1, 1, Json2::Value, set, s32 (Json2::Value::*)(Json2::String const&));
    LOMF("XL8+BUqjB1w", j2, 1, j, 1, 1, Json2::Value, set, s32 (Json2::Value::*)(Json2::Value const&));
    LOMF("9PqrCLfKZZI", j2, 1, j, 1, 1, Json2::Value, swap, s32 (Json2::Value::*)(Json2::Value&));
    LOMF("FIjXN2TkuTs", j2, 1, j, 1, 1, Json2::Value, clear, s32 (Json2::Value::*)());
    LOMF("t7UEJrhojhk", j2, 1, j, 1, 1, Json2::Value, referReal, s32 (Json2::Value::*)());
    LOMF("PyMbL9F2oBY", j2, 1, j, 1, 1, Json2::Value, serialize, s32 (Json2::Value::*)(int (*)(Json2::String&, void*), void*));
    LOMF("R7FDWtcN6f8", j2, 1, j, 1, 1, Json2::Value, serialize, s32 (Json2::Value::*)(Json2::String&));
    LOMF("l1URiQJlSoU", j2, 1, j, 1, 1, Json2::Value, serialize, s32 (Json2::Value::*)(Json2::String&, int (*)(Json2::String&, void*), void*));
    LOMF("4zrm6VrgIAw", j2, 1, j, 1, 1, Json2::Value, operator=, s32 (Json2::Value::*)(Json2::Value const&));
    LF("UeuWT+yNdCQ", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, bool>));
    LF("sOmU4vnx3s0", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, double>));
    LF("0lLK8+kDqmE", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, long>));
    LF("x4AUdbhpRB0", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, unsigned long>));
    LF("CbrT3dwDILo", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, Json2::ValueType>));
    LF("b9V6fmppLXY", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, char const*>));
    LF("iZeYfOxtMRg", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, Json2::Array const&>));
    LF("3xUXnmUkXfo", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, Json2::Object const&>));
    LF("sZIoMRGO+jk", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, Json2::String const&>));
    LF("fSb2oQTNrgA", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, Json2::Value const&>));
    LF("qBMjqyBn3OM", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value>));
    LF("OK4Ot0ue7J0", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, bool>));
    LF("23nm4oXHlfI", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, double>));
    LF("EjxUpzR2Yx8", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, long>));
    LF("cqucBPSeVDA", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, unsigned long>));
    LF("PWm9MyJJVqU", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, Json2::ValueType>));
    LF("+hHa4QYtLY8", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, char const*>));
    LF("VH9dsKpQTmk", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, Json2::Array const&>));
    LF("JXlrCLLCLmc", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, Json2::Object const&>));
    LF("veNviXt6wC0", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, Json2::String const&>));
    LF("TZyuFeGuw9Y", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value, Json2::Value const&>));
    LF("-wa17B7TGnw", j2, 1, j, 1, 1, (ctor_wrapper<Json2::Value>));
    LF("WTtYf+cNnXI", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Value>));
    LF("0eUrW9JAxM0", j2, 1, j, 1, 1, (dtor_wrapper<Json2::Value>));

    // LF("+hYsagaV-Ug", j2, 1, j, 1, 1, Json2::Object::Pair::Pair(Json2::String const&, Json2::Value const&));
    // LF("-uQnUEENfpk", j2, 1, j, 1, 1, Json2::Object::Pair::Pair());
    // LF("lt3J4dPvEtM", j2, 1, j, 1, 1, Json2::Object::Pair::Pair(Json2::String const&, Json2::Value const&));
    // LF("Wu-urs6MMpQ", j2, 1, j, 1, 1, Json2::Object::Pair::Pair());
    // LF("Q0ng4sWj2E8", j2, 1, j, 1, 1, Json2::Object::Pair::~Pair());
    // LF("TM0Sj+Ebins", j2, 1, j, 1, 1, Json2::Object::Pair::~Pair());
    // LF("oH8aBmLU+fc", j2, 1, j, 1, 1, Json2::Object::clear());
    // LF("3ZhL-MkICwI", j2, 1, j, 1, 1, Json2::Object::erase(Json2::String const&));
    // LF("ol7KhQl8kfw", j2, 1, j, 1, 1, Json2::Object::insert(Json2::Object::Pair const&));
    // LF("h-V8r4EF7bo", j2, 1, j, 1, 1, Json2::Object::iterator::advance(unsigned long));
    // LF("w7nqTT3zgxU", j2, 1, j, 1, 1, Json2::Object::iterator::operator=(Json2::Object::iterator const&));
    // LF("JATlaeBu+lU", j2, 1, j, 1, 1, Json2::Object::iterator::iterator(Json2::Object::iterator const&));
    // LF("a2Zv3idT0sU", j2, 1, j, 1, 1, Json2::Object::iterator::iterator());
    // LF("r5CShmcua+M", j2, 1, j, 1, 1, Json2::Object::iterator::iterator(Json2::Object::iterator const&));
    // LF("OxO+V0ouoS4", j2, 1, j, 1, 1, Json2::Object::iterator::iterator());
    // LF("hoINmSMlYjI", j2, 1, j, 1, 1, Json2::Object::iterator::~iterator());
    // LF("patTzc7zBjw", j2, 1, j, 1, 1, Json2::Object::iterator::~iterator());
    // LF("dIVxrrdpS9M", j2, 1, j, 1, 1, Json2::Object::iterator::operator++(int));
    // LF("DlWmn2ZQuWY", j2, 1, j, 1, 1, Json2::Object::iterator::operator++());
    // LF("urOpESTBZmo", j2, 1, j, 1, 1, Json2::Object::operator=(Json2::Object const&));
    // LF("a+W7HHlwpBs", j2, 1, j, 1, 1, Json2::Object::Object(Json2::Object const&));
    // LF("OJPTonqdg0I", j2, 1, j, 1, 1, Json2::Object::Object());
    // LF("tSRqQ-+Y4PE", j2, 1, j, 1, 1, Json2::Object::Object(Json2::Object const&));
    // LF("SkKczWHdklc", j2, 1, j, 1, 1, Json2::Object::Object());
    // LF("5JmzZt8twAo", j2, 1, j, 1, 1, Json2::Object::~Object());
    // LF("1siRBursJjw", j2, 1, j, 1, 1, Json2::Object::~Object());
    // LF("ERuf9y0DY84", j2, 1, j, 1, 1, Json2::Object::operator[](Json2::String const&));
    // LF("itqj2YmuAa8", j2, 1, j, 1, 1, Json2::Parser::parse(Json2::Value&, int (*)(char&, void*), void*));
    // LF("LB3jxppxyKU", j2, 1, j, 1, 1, Json2::Parser::parse(Json2::Value&, char const*));
    // LF("S5JxQnoGF3E", j2, 1, j, 1, 1, Json2::Parser::parse(Json2::Value&, char const*, unsigned long));
    // LF("pCF8Ohwre44", j2, 1, j, 1, 1, Json2::String::npos);
    // LF("A+FhGENHV-E", j2, 1, j, 1, 1, Json2::String::clear());
    // LF("Va5FJ6TmNCw", j2, 1, j, 1, 1, Json2::String::append(char const*));
    // LF("bREqDgXlqDU", j2, 1, j, 1, 1, Json2::String::append(char const*, unsigned long));
    // LF("Rz00kiTKypo", j2, 1, j, 1, 1, Json2::String::append(Json2::String const&));
    // LF("PiR0tiTnNbM", j2, 1, j, 1, 1, Json2::String::resize(unsigned long));
    // LF("Z9tyi1-LrQg", j2, 1, j, 1, 1, Json2::String::reserve(unsigned long));
    // LF("cn9svYGWKDQ", j2, 1, j, 1, 1, Json2::String::operator=(Json2::String const&));
    // LF("9KUZFjI1IxA", j2, 1, j, 1, 1, Json2::String::String(char const*));
    // LF("0CAesfH963Q", j2, 1, j, 1, 1, Json2::String::String(Json2::String const&));
    // LF("qSmqLXXCPas", j2, 1, j, 1, 1, Json2::String::String());
    // LF("N78gkQzXRL4", j2, 1, j, 1, 1, Json2::String::String(char const*));
    // LF("gALFgNfF+9I", j2, 1, j, 1, 1, Json2::String::String(Json2::String const&));
    // LF("eG9E9M6XvTM", j2, 1, j, 1, 1, Json2::String::String());
    // LF("cG1VE2HMl6c", j2, 1, j, 1, 1, Json2::String::~String());
    // LF("Ui7YFnSTCBw", j2, 1, j, 1, 1, Json2::String::~String());
    // LF("-Wek6mFXOrc", j2, 1, j, 1, 1, Json2::String::operator+=(unsigned char));
    // LF("aVDQZGAqOo8", j2, 1, j, 1, 1, Json2::String::operator+=(char const*));
    // LF("GWtzpTKbZ+0", j2, 1, j, 1, 1, Json2::InitParameter2::getUserData() const);
    // LF("BykPm1ajcM0", j2, 1, j, 1, 1, Json2::InitParameter2::getAllocator() const);
    // LF("Pcg6xQUhq9E", j2, 1, j, 1, 1, Json2::InitParameter2::getFileBufferSize() const);
    // LF("PDkib0zyABg", j2, 1, j, 1, 1, Json2::InitParameter2::getSpecialFloatFormatType() const);
    // LF("WXF2ihRF+B8", j2, 1, j, 1, 1, Json2::Array::end() const);
    // LF("bAM9Qwofus0", j2, 1, j, 1, 1, Json2::Array::back() const);
    // LF("rQGJeNjOuUk", j2, 1, j, 1, 1, Json2::Array::size() const);
    // LF("bcH5EnFE2xY", j2, 1, j, 1, 1, Json2::Array::begin() const);
    // LF("9uP25i6ipno", j2, 1, j, 1, 1, Json2::Array::empty() const);
    // LF("zcfZQyM7eAE", j2, 1, j, 1, 1, Json2::Array::front() const);
    // LF("wcgr5mte7T8", j2, 1, j, 1, 1, Json2::Array::iterator::operator*() const);
    // LF("5AZPp99ogrc", j2, 1, j, 1, 1, Json2::Array::iterator::operator!=(Json2::Array::iterator const&) const);
    // LF("iAIYn4oAWvI", j2, 1, j, 1, 1, Json2::Array::iterator::operator->() const);
    // LF("zTwZdI8AZ5Y", j2, 1, j, 1, 1, Json2::Value::getBoolean() const);
    // LF("DIxvoy7Ngvk", j2, 1, j, 1, 1, Json2::Value::getInteger() const);
    // LF("sn4HNCtNRzY", j2, 1, j, 1, 1, Json2::Value::getUInteger() const);
    // LF("RBw+4NukeGQ", j2, 1, j, 1, 1, Json2::Value::count() const);
    // LF("3qrge7L-AU4", j2, 1, j, 1, 1, Json2::Value::getReal() const);
    // LF("SHtAad20YYM", j2, 1, j, 1, 1, Json2::Value::getType() const);
    // LF("ONT8As5R1ug", j2, 1, j, 1, 1, Json2::Value::getArray() const);
    // LF("0YqYAoO-+Uo", j2, 1, j, 1, 1, Json2::Value::getValue(unsigned long) const);
    // LF("MsMOdxWfbwQ", j2, 1, j, 1, 1, Json2::Value::getValue(Json2::String const&) const);
    // LF("Ncel8t2Rrpc", j2, 1, j, 1, 1, Json2::Value::toString(Json2::String&) const);
    // LF("IlsmvBtMkak", j2, 1, j, 1, 1, Json2::Value::getObject() const);
    // LF("epJ6x2LV0kU", j2, 1, j, 1, 1, Json2::Value::getString() const);
    // LF("a-aMMUXqrN0", j2, 1, j, 1, 1, Json2::Value::operator bool() const);
    // LF("XlWbvieLj2M", j2, 1, j, 1, 1, Json2::Value::operator[](unsigned long) const);
    // LF("HwDt5lD9Bfo", j2, 1, j, 1, 1, Json2::Value::operator[](char const*) const);
    // LF("clF7J7N9xXE", j2, 1, j, 1, 1, Json2::Value::operator[](Json2::String const&) const);
    // LF("ivMCitpSQNk", j2, 1, j, 1, 1, Json2::Object::end() const);
    // LF("ehN1Biw3tw8", j2, 1, j, 1, 1, Json2::Object::find(Json2::String const&) const);
    // LF("fSGHm9RjN5U", j2, 1, j, 1, 1, Json2::Object::size() const);
    // LF("xhAcaIwnrgk", j2, 1, j, 1, 1, Json2::Object::begin() const);
    // LF("i2l3IYvQ9UE", j2, 1, j, 1, 1, Json2::Object::empty() const);
    // LF("ZCd6IYoD3Bc", j2, 1, j, 1, 1, Json2::Object::iterator::operator*() const);
    // LF("q3YO1c0RqFo", j2, 1, j, 1, 1, Json2::Object::iterator::operator==(Json2::Object::iterator const&) const);
    // LF("+isUKw4zud4", j2, 1, j, 1, 1, Json2::Object::iterator::operator!=(Json2::Object::iterator const&) const);
    // LF("EnesV4gXDtE", j2, 1, j, 1, 1, Json2::Object::iterator::operator->() const);
    // LF("KrKM-5SdQrA", j2, 1, j, 1, 1, Json2::String::at(unsigned long) const);
    // LF("x4SuxMR26I4", j2, 1, j, 1, 1, Json2::String::find(char, unsigned long) const);
    // LF("yjsf6SvXA08", j2, 1, j, 1, 1, Json2::String::find(char const*, unsigned long) const);
    // LF("wwDnDDsQVc0", j2, 1, j, 1, 1, Json2::String::find(char const*, unsigned long, unsigned long) const);
    // LF("awkeNR6Ukp8", j2, 1, j, 1, 1, Json2::String::find(Json2::String const&, unsigned long) const);
    // LF("UVBkipSD2sw", j2, 1, j, 1, 1, Json2::String::size() const);
    // LF("L1KAkYWml-M", j2, 1, j, 1, 1, Json2::String::c_str() const);
    // LF("wM4LO2iK3s8", j2, 1, j, 1, 1, Json2::String::empty() const);
    // LF("t+Dx3eQtBPQ", j2, 1, j, 1, 1, Json2::String::rfind(char, unsigned long) const);
    // LF("VpQBXbaHXOo", j2, 1, j, 1, 1, Json2::String::rfind(char const*, unsigned long) const);
    // LF("A29RHrlfTM0", j2, 1, j, 1, 1, Json2::String::rfind(char const*, unsigned long, unsigned long) const);
    // LF("-R9mdXBspeQ", j2, 1, j, 1, 1, Json2::String::rfind(Json2::String const&, unsigned long) const);
    // LF("EUH+EmT-v9E", j2, 1, j, 1, 1, Json2::String::length() const);
    // LF("8OCexW9qJgQ", j2, 1, j, 1, 1, Json2::String::substr(unsigned long, unsigned long) const);
    // LF("Yfw63FVJgtU", j2, 1, j, 1, 1, Json2::String::compare(char const*) const);
    // LF("PXIHOuLUN40", j2, 1, j, 1, 1, Json2::String::compare(Json2::String const&) const);
    // LF("q0qeup2r7hA", j2, 1, j, 1, 1, Json2::String::capacity() const);
    // LF("VbFjEs--uiA", j2, 1, j, 1, 1, Json2::String::operator==(char const*) const);
    // LF("DM43TNBBfb0", j2, 1, j, 1, 1, Json2::String::operator==(Json2::String const&) const);
};

} // namespace Libraries::Json2