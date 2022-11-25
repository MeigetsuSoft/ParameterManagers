#include <iutest/iutest.hpp>
#include "IntegerBase.hpp"

template<typename T>
struct IntegerOperator : public ::iutest::Test{};

IUTEST_TYPED_TEST_CASE(IntegerOperator, ::iutest::Types<
	short,
	int,
	long,
	long long,
	unsigned short,
	unsigned int,
	unsigned long,
	unsigned long long
>);

IUTEST_TYPED_TEST(IntegerOperator, equal) {
	using num = standard::Integer<TypeParam>;
	const num a = 0;
	const num b = 0;
	IUTEST_ASSERT(a == b);
}

IUTEST_TYPED_TEST(IntegerOperator, ne) {
	using num = standard::Integer<TypeParam>;
	const num a = 0;
	const num b = 5;
	IUTEST_ASSERT(a != b);
}

IUTEST_TYPED_TEST(IntegerOperator, large) {
	using num = standard::Integer<TypeParam>;
	const num a = 7;
	const num b = 0;
	IUTEST_ASSERT(a > b);
}

IUTEST_TYPED_TEST(IntegerOperator, small) {
	using num = standard::Integer<TypeParam>;
	const num a = 125;
	const num b = 127;
	IUTEST_ASSERT(a < b);
}

IUTEST_TYPED_TEST(IntegerOperator, largeeqA) {
	using num = standard::Integer<TypeParam>;
	const num a = 17;
	const num b = 15;
	IUTEST_ASSERT(a >= b);
}

IUTEST_TYPED_TEST(IntegerOperator, largeeqB) {
	using num = standard::Integer<TypeParam>;
	const num a = 44;
	const num b = 44;
	IUTEST_ASSERT(a >= b);
}

IUTEST_TYPED_TEST(IntegerOperator, smalleqA) {
	using num = standard::Integer<TypeParam>;
	const num a = 75;
	const num b = 98;
	IUTEST_ASSERT(a <= b);
}

IUTEST_TYPED_TEST(IntegerOperator, smalleqB) {
	using num = standard::Integer<TypeParam>;
	const num a = 55;
	const num b = 55;
	IUTEST_ASSERT(a <= b);
}

IUTEST_TYPED_TEST(IntegerOperator, plus) {
	using num = standard::Integer<TypeParam>;
	const num a = 1;
	const num b = 2;
	IUTEST_ASSERT_EQ(3, a + b);
}

IUTEST_TYPED_TEST(IntegerOperator, minus) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(0, a - b);
}

IUTEST_TYPED_TEST(IntegerOperator, multiplication) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(4, a * b);
}

IUTEST_TYPED_TEST(IntegerOperator, division) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(1, a / b);
}

IUTEST_TYPED_TEST(IntegerOperator, and) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(2 & 2, a & b);
}

IUTEST_TYPED_TEST(IntegerOperator, mod) {
	using num = standard::Integer<TypeParam>;
	const num a = 140;
	const num b = 45;
	IUTEST_ASSERT_EQ(5, a % b);
}

IUTEST_TYPED_TEST(IntegerOperator, or) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(2, a | b);
}

IUTEST_TYPED_TEST(IntegerOperator, not) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	IUTEST_ASSERT_EQ(-3, ~a);
}

IUTEST_TYPED_TEST(IntegerOperator, xor) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(0, a ^ b);
}

IUTEST_TYPED_TEST(IntegerOperator, left_shift) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(8, a << b);
}

IUTEST_TYPED_TEST(IntegerOperator, right_shift) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(0, a >> b);
}
