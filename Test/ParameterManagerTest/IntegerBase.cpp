#include <iutest/iutest.hpp>
#include "IntegerBase.hpp"

template<typename T>
struct IntegerBaseOperator : public ::iutest::Test{};

IUTEST_TYPED_TEST_CASE(IntegerBaseOperator, ::iutest::Types<
	short,
	int,
	long,
	long long,
	unsigned short,
	unsigned int,
	unsigned long,
	unsigned long long
>);

IUTEST_TYPED_TEST(IntegerBaseOperator, equal) {
	using num = standard::Integer<TypeParam>;
	const num a = 0;
	const num b = 0;
	IUTEST_ASSERT(a == b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, ne) {
	using num = standard::Integer<TypeParam>;
	const num a = 0;
	const num b = 5;
	IUTEST_ASSERT(a != b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, large) {
	using num = standard::Integer<TypeParam>;
	const num a = 7;
	const num b = 0;
	IUTEST_ASSERT(a > b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, small) {
	using num = standard::Integer<TypeParam>;
	const num a = 125;
	const num b = 127;
	IUTEST_ASSERT(a < b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, largeeqA) {
	using num = standard::Integer<TypeParam>;
	const num a = 17;
	const num b = 15;
	IUTEST_ASSERT(a >= b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, largeeqB) {
	using num = standard::Integer<TypeParam>;
	const num a = 44;
	const num b = 44;
	IUTEST_ASSERT(a >= b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, smalleqA) {
	using num = standard::Integer<TypeParam>;
	const num a = 75;
	const num b = 98;
	IUTEST_ASSERT(a <= b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, smalleqB) {
	using num = standard::Integer<TypeParam>;
	const num a = 55;
	const num b = 55;
	IUTEST_ASSERT(a <= b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, plus) {
	using num = standard::Integer<TypeParam>;
	const num a = 1;
	const num b = 2;
	IUTEST_ASSERT_EQ(3, a + b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, minus) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(0, a - b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, multiplication) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(4, a * b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, division) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(1, a / b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, zerodivision) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 0;
	try {
		auto cache = a / b;
		IUTEST_FAIL();
	}
	catch (...) {
		IUTEST_SUCCEED();
	}
}

IUTEST_TYPED_TEST(IntegerBaseOperator, and) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(2, a & b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, mod) {
	using num = standard::Integer<TypeParam>;
	const num a = 140;
	const num b = 45;
	IUTEST_ASSERT_EQ(5, a % b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, or) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(2, a | b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, not) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	IUTEST_ASSERT_EQ(-3, ~a);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, xor) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(0, a ^ b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, left_shift) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(8, a << b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, right_shift) {
	using num = standard::Integer<TypeParam>;
	const num a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(0, a >> b);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, plus_equal) {
	using num = standard::Integer<TypeParam>;
	num a = 1;
	a += 2;
	IUTEST_ASSERT_EQ(3, a);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, minus_equal) {
	using num = standard::Integer<TypeParam>;
	num a = 2;
	a -= 2;
	IUTEST_ASSERT_EQ(0, a);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, multiplication_equal) {
	using num = standard::Integer<TypeParam>;
	num a = 2;
	a *= 2;
	IUTEST_ASSERT_EQ(4, a);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, division_equal) {
	using num = standard::Integer<TypeParam>;
	num a = 2;
	a /= 2;
	IUTEST_ASSERT_EQ(1, a);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, zerodivision_equal) {
	using num = standard::Integer<TypeParam>;
	num a = 2;
	try {
		a /= 0;
		IUTEST_FAIL();
	}
	catch (...) {
		IUTEST_SUCCEED();
	}
}

IUTEST_TYPED_TEST(IntegerBaseOperator, and_equal) {
	using num = standard::Integer<TypeParam>;
	num a = 2;
	a &= 2;
	IUTEST_ASSERT_EQ(2, a);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, mod_equal) {
	using num = standard::Integer<TypeParam>;
	num a = 140;
	a %= 45;
	IUTEST_ASSERT_EQ(5, a);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, or_equal) {
	using num = standard::Integer<TypeParam>;
	num a = 2;
	a |= 2;
	IUTEST_ASSERT_EQ(2, a);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, xor_equal) {
	using num = standard::Integer<TypeParam>;
	num a = 2;
	a ^= 2;
	IUTEST_ASSERT_EQ(0, a);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, left_shift_equal) {
	using num = standard::Integer<TypeParam>;
	num a = 2;
	a <<= 2;
	IUTEST_ASSERT_EQ(8, a);
}

IUTEST_TYPED_TEST(IntegerBaseOperator, right_shift_equal) {
	using num = standard::Integer<TypeParam>;
	num a = 2;
	a >>= 2;
	IUTEST_ASSERT_EQ(0, a);
}
