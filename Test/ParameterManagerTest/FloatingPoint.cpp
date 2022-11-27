#include <iutest/iutest.hpp>
#include "FloatingPoint.hpp"

template<typename T>
struct FloatingPointOperator : public ::iutest::Test {};

IUTEST_TYPED_TEST_CASE(FloatingPointOperator, ::iutest::Types<
	float,
	double,
	long double
>);

IUTEST_TYPED_TEST(FloatingPointOperator, equal) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 0;
	const num b = 0;
	IUTEST_ASSERT(a == b);
}

IUTEST_TYPED_TEST(FloatingPointOperator, ne) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 0;
	const num b = 5;
	IUTEST_ASSERT(a != b);
}

IUTEST_TYPED_TEST(FloatingPointOperator, large) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 7;
	const num b = 0;
	IUTEST_ASSERT(a > b);
}

IUTEST_TYPED_TEST(FloatingPointOperator, small) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 125;
	const num b = 127;
	IUTEST_ASSERT(a < b);
}

IUTEST_TYPED_TEST(FloatingPointOperator, largeeqA) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 17;
	const num b = 15;
	IUTEST_ASSERT(a >= b);
}

IUTEST_TYPED_TEST(FloatingPointOperator, largeeqB) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 44;
	const num b = 44;
	IUTEST_ASSERT(a >= b);
}

IUTEST_TYPED_TEST(FloatingPointOperator, smalleqA) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 75;
	const num b = 98;
	IUTEST_ASSERT(a <= b);
}

IUTEST_TYPED_TEST(FloatingPointOperator, smalleqB) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 55;
	const num b = 55;
	IUTEST_ASSERT(a <= b);
}

IUTEST_TYPED_TEST(FloatingPointOperator, plus) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 1;
	const num b = 2;
	IUTEST_ASSERT_EQ(3, a + b);
}

IUTEST_TYPED_TEST(FloatingPointOperator, minus) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(0, a - b);
}

IUTEST_TYPED_TEST(FloatingPointOperator, multiplication) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(4, a * b);
}

IUTEST_TYPED_TEST(FloatingPointOperator, division) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 2;
	const num b = 2;
	IUTEST_ASSERT_EQ(1, a / b);
}

IUTEST_TYPED_TEST(FloatingPointOperator, zerodivision) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 2;
	const num b = 0;
	try {
		auto cache = a / b;
		IUTEST_FAIL();
	}
	catch (...) {
		IUTEST_SUCCEED();
	}
}

IUTEST_TYPED_TEST(FloatingPointOperator, mod) {
	using num = standard::FloatingPoint<TypeParam>;
	const TypeParam a = 140;
	const num b = 45;
	IUTEST_ASSERT_EQ(5, a % b);
}

IUTEST_TYPED_TEST(FloatingPointOperator, stl_max) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 2;
	const num b = 6;
	IUTEST_ASSERT_EQ(6, std::max(a, b));
}

IUTEST_TYPED_TEST(FloatingPointOperator, stl_min) {
	using num = standard::FloatingPoint<TypeParam>;
	const num a = 2;
	const num b = 6;
	IUTEST_ASSERT_EQ(2, std::min(a, b));
}
