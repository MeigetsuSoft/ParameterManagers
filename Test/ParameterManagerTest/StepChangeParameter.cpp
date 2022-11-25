#include <iutest/iutest.hpp>
#include "StepChangeParameter.hpp"

template<typename T>
struct StepChangeParameterOperator : public ::iutest::Test {};

IUTEST_TYPED_TEST_CASE(StepChangeParameterOperator, ::iutest::Types<
	short,
	int,
	long,
	long long
>);

IUTEST_TYPED_TEST(StepChangeParameterOperator, ParamValueNoChange) {
	using num = meigetsusoft::DefeatMonster::StepChangeParameter<TypeParam>;
	const num a(100, 6);
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(100, a); }, true);
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(100, a); }, false);
}

IUTEST_TYPED_TEST(StepChangeParameterOperator, ParamValueAfterChangeMinus) {
	using num = meigetsusoft::DefeatMonster::StepChangeParameter<TypeParam>;
	num a(100, 6);
	a -= 7;
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(4, a); }, true);
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(100, a); }, false);
}

IUTEST_TYPED_TEST(StepChangeParameterOperator, ParamValueAfterChangePlus) {
	using num = meigetsusoft::DefeatMonster::StepChangeParameter<TypeParam>;
	num a(100, 6);
	a += 4;
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(164, a); }, true);
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(100, a); }, false);
}

IUTEST_TYPED_TEST(StepChangeParameterOperator, ParamValueAfterChangeAfterApply) {
	using num = meigetsusoft::DefeatMonster::StepChangeParameter<TypeParam>;
	num a(100, 6);
	a += 2;
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(132, a); }, true);
	while (!a.Synced()) a.Update();
	a.ViewByNumParam([](const TypeParam& a) { IUTEST_ASSERT_EQ(132, a); }, false);
}


IUTEST_TYPED_TEST(StepChangeParameterOperator, StepCalculation) {
	using num = meigetsusoft::DefeatMonster::StepChangeParameter<TypeParam>;
	num a(100, 6);
	a -= 4;
	IUTEST_ASSERT_EQ(-4, a.GetCurrentStep());
}
