#pragma once

#include "ConstexprString.h"


constexpr char cref1[] = "abcd1";
constexpr char cref2[] = "xabcd2";
constexpr auto ConstexprString1 = ces::make_string("efg1");
constexpr auto ConstexprString2 = ces::make_string("yyyefg2");
constexpr char expected_ConstexprString1[]    = "efg1";

constexpr auto cref1_ConstexprString1    = cref1 + ConstexprString1;
constexpr auto ConstexprString1_cref1    = ConstexprString1 + cref1;
constexpr auto ConstexprString1_ConstexprString2 = ConstexprString1 + ConstexprString2;



constexpr char expected_cref1_ConstexprString1[]    = "abcd1efg1";
constexpr char expected_cref1_cref2 []      = "abcd1xabcd2";
constexpr char expected_ConstexprString1_cref1[]    = "efg1abcd1";
constexpr char expected_ConstexprString1_ConstexprString2[] = "efg1yyyefg2";




static_assert(ces::make_string(L"") == L"","__________");
static_assert(ces::make_string(L"ab") == L"ab","__________");
static_assert(ces::make_string(U"ab") == U"ab","__________");

static_assert(ces::make_string("") == "","__________");
static_assert(ces::make_string("ab") == "ab","__________");

static_assert(ces::make_string("") + "" == "","__________");
static_assert(ces::make_string("") + cref1 == cref1,"__________");

static_assert(cref1_ConstexprString1 == expected_cref1_ConstexprString1,"__________");
static_assert(ConstexprString1_cref1 == expected_ConstexprString1_cref1,"__________");
static_assert(ConstexprString1_ConstexprString2 == expected_ConstexprString1_ConstexprString2,"__________");

static_assert(ConstexprString1 + cref1 + "foo" + ConstexprString1 + ConstexprString1 + ConstexprString1 == "efg1abcd1fooefg1efg1efg1","__________");



static_assert(ces::make_string("").empty()==true,"__________");
static_assert(ces::make_string("").length()==0,"__________");
static_assert(ces::make_string("1").length()==1,"__________");
static_assert(ces::make_string("1").empty()==false,"__________");

constexpr auto xx = ces::make_string("ab");
static_assert(ces::conditional(false , "c", xx)==xx,"__________");
