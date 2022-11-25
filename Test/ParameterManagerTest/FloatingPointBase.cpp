#include <iutest/iutest.hpp>
#include "FloatingPointBase.hpp"
template<typename T>
struct FloatOperator : public ::iutest::Test {};

IUTEST_TYPED_TEST_CASE(FloatOperator, ::iutest::Types<
	float,
	double,
	long double
>);

IUTEST_TYPED_TEST(FloatOperator, equal) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 0;
	const num b = 0;
	IUTEST_ASSERT(a == b);
}

IUTEST_TYPED_TEST(FloatOperator, ne) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 0;
	const num b = 5;
	IUTEST_ASSERT(a != b);
}

IUTEST_TYPED_TEST(FloatOperator, large) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 7;
	const num b = 0;
	IUTEST_ASSERT(a > b);
}

IUTEST_TYPED_TEST(FloatOperator, small) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 125;
	const num b = 127;
	IUTEST_ASSERT(a < b);
}

IUTEST_TYPED_TEST(FloatOperator, largeeqA) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 17;
	const num b = 15;
	IUTEST_ASSERT(a >= b);
}

IUTEST_TYPED_TEST(FloatOperator, largeeqB) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 44;
	const num b = 44;
	IUTEST_ASSERT(a >= b);
}

IUTEST_TYPED_TEST(FloatOperator, smalleqA) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 75;
	const num b = 98;
	IUTEST_ASSERT(a <= b);
}

IUTEST_TYPED_TEST(FloatOperator, smalleqB) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 55;
	const num b = 55;
	IUTEST_ASSERT(a <= b);
}

IUTEST_TYPED_TEST(FloatOperator, plus) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 1;
	const num b = 2;
	IUTEST_ASSERT_EQ(3, a + b);
}

IUTEST_TYPED_TEST(FloatOperator, minus) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(0, a - b);
}

IUTEST_TYPED_TEST(FloatOperator, multiplication) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(4, a * b);
}

IUTEST_TYPED_TEST(FloatOperator, division) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(1, a / b);
}

IUTEST_TYPED_TEST(FloatOperator, mod) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 140;
	const num b = 45;
	IUTEST_ASSERT_EQ(5, a % b);
}
