#include <iutest/iutest.hpp>
#include "FloatingPointBase.hpp"
template<typename T>
struct FloatingPointBaseOperator : public ::iutest::Test {};

IUTEST_TYPED_TEST_CASE(FloatingPointBaseOperator, ::iutest::Types<
	float,
	double,
	long double
>);

IUTEST_TYPED_TEST(FloatingPointBaseOperator, equal) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 0;
	const num b = 0;
	IUTEST_ASSERT(a == b);
}

IUTEST_TYPED_TEST(FloatingPointBaseOperator, ne) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 0;
	const num b = 5;
	IUTEST_ASSERT(a != b);
}

IUTEST_TYPED_TEST(FloatingPointBaseOperator, large) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 7;
	const num b = 0;
	IUTEST_ASSERT(a > b);
}

IUTEST_TYPED_TEST(FloatingPointBaseOperator, small) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 125;
	const num b = 127;
	IUTEST_ASSERT(a < b);
}

IUTEST_TYPED_TEST(FloatingPointBaseOperator, largeeqA) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 17;
	const num b = 15;
	IUTEST_ASSERT(a >= b);
}

IUTEST_TYPED_TEST(FloatingPointBaseOperator, largeeqB) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 44;
	const num b = 44;
	IUTEST_ASSERT(a >= b);
}

IUTEST_TYPED_TEST(FloatingPointBaseOperator, smalleqA) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 75;
	const num b = 98;
	IUTEST_ASSERT(a <= b);
}

IUTEST_TYPED_TEST(FloatingPointBaseOperator, smalleqB) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 55;
	const num b = 55;
	IUTEST_ASSERT(a <= b);
}

IUTEST_TYPED_TEST(FloatingPointBaseOperator, plus) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 1;
	const num b = 2;
	IUTEST_ASSERT_EQ(3, a + b);
}

IUTEST_TYPED_TEST(FloatingPointBaseOperator, minus) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(0, a - b);
}

IUTEST_TYPED_TEST(FloatingPointBaseOperator, multiplication) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(4, a * b);
}

IUTEST_TYPED_TEST(FloatingPointBaseOperator, division) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(1, a / b);
}

IUTEST_TYPED_TEST(FloatingPointBaseOperator, mod) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 140;
	const num b = 45;
	IUTEST_ASSERT_EQ(5, a % b);
}

IUTEST_TYPED_TEST(FloatingPointBaseOperator, cast_operator) {
	using num = standard::FloatingPoint<TypeParam>;
	num a = 2;
	IUTEST_ASSERT_ALMOST_EQ(2, static_cast<TypeParam>(a));
}
