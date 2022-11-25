#include <iutest/iutest.hpp>
#include "ParameterManager.hpp"

template<typename T>
struct ParameterManagerOperator : public ::iutest::Test {};

IUTEST_TYPED_TEST_CASE(ParameterManagerOperator, ::iutest::Types<
	short,
	int,
	long,
	long long
>);

IUTEST_TYPED_TEST(ParameterManagerOperator, ParamValueNoChange) {
	using num = meigetsusoft::ParameterManager<TypeParam>;
	const num a(100, 100, 0);
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(100, a); }, true);
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(100, a); }, false);
}

IUTEST_TYPED_TEST(ParameterManagerOperator, ParamValueAfterChangeMinus) {
	using num = meigetsusoft::ParameterManager<TypeParam>;
	num a(100, 100, 0);
	a -= 60;
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(40, a); }, true);
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(100, a); }, false);
}

IUTEST_TYPED_TEST(ParameterManagerOperator, ParamValueAfterChangePlus) {
	using num = meigetsusoft::ParameterManager<TypeParam>;
	num a(70, 100, 0);
	a += 60;
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(100, a); }, true);
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(70, a); }, false);
}

IUTEST_TYPED_TEST(ParameterManagerOperator, ParamValueAfterChangeAfterApply) {
	using num = meigetsusoft::ParameterManager<TypeParam>;
	num a(70, 100, 0);
	a += 25;
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(95, a); }, true);
	while (!a.Synced()) a.Update();
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(95, a); }, false);
}
