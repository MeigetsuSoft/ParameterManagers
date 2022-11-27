#if !defined MINMAX_MANAGEMENT_FLOATING_NUMBER_CLASS
#define MINMAX_MANAGEMENT_FLOATING_NUMBER_CLASS
#include "FloatingPointBase.hpp"
#include <string>

namespace standard {
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<T> operator + (const T& n, const FloatingPoint<T>& num) {
		return FloatingPoint<T>(clamp(n + num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin());
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<T> operator - (const T& n, const FloatingPoint<T>& num) {
		return FloatingPoint<T>(clamp(n - num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin());
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<T> operator * (const T& n, const FloatingPoint<T>& num) {
		return FloatingPoint<T>(clamp(n * num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin());
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<T> operator / (const T& n, const FloatingPoint<T>& num) {
		return FloatingPoint<T>(clamp(n / num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin())
	}
	namespace {
		template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
		constexpr bool eq(const T& n, const FloatingPoint<T>& num) {
			return std::abs(n - num.Get()) < std::numeric_limits<T>::epsilon();
		}
		template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
		constexpr bool ne(const T& n, const FloatingPoint<T>& num) {
			return !eq(n, num);
		}
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline bool operator == (const T& n, const FloatingPoint<T>& num) {
		return eq(n, num);
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline bool operator != (const T& n, const FloatingPoint<T>& num) {
		return ne(n, num);
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline bool operator <  (const T& n, const FloatingPoint<T>& num) {
		return n < num.Get() && !eq(n, num);
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline bool operator <= (const T& n, const FloatingPoint<T>& num) {
		return n <= num.Get();
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline bool operator >  (const T& n, const FloatingPoint<T>& num) {
		return n > num.Get() && !eq(n, num);
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline bool operator >= (const T& n, const FloatingPoint<T>& num) {
		return n >= num.Get();
	}

	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	constexpr FloatingPoint<T> clamp(const FloatingPoint<T>& v, const FloatingPoint<T>& lo, const FloatingPoint<T>& hi) {
		return FloatingPoint<T>(clamp<T>(v.Get(), lo.Get(), hi.Get()));
	}

	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	constexpr FloatingPoint<T> max(const FloatingPoint<T>& Left, const FloatingPoint<T>& Right) {
		return FloatingPoint<T>(std::max(Left.Get(), Right.Get()));
	}

	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	constexpr FloatingPoint<T> min(const FloatingPoint<T>& Left, const FloatingPoint<T>& Right) {
		return FloatingPoint<T>(std::min(Left.Get(), Right.Get()));
	}
	inline FloatingPoint<long double> abs(const FloatingPoint<long double> n) {
		return FloatingPoint<long double>(std::abs(n.Get()));
	}
	inline FloatingPoint<double> abs(const FloatingPoint<double> n) {
		return FloatingPoint<double>(std::abs(n.Get()));
	}
	inline FloatingPoint<float> abs(const FloatingPoint<float> n) {
		return FloatingPoint<float>(std::abs(n.Get()));
	}
	namespace {
		template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
		FloatingPoint<T> string_to_float(const std::string s, size_t* Index = 0) {
			return FloatingPoint<T>(static_cast<T>(std::stold(s, Index)));
		}
		template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
		FloatingPoint<T> wstring_to_float(const std::wstring s, size_t* Index = 0) {
			return FloatingPoint<T>(static_cast<T>(std::stold(s, Index)));
		}
	}
	inline FloatingPoint<float> stof(const std::string& s, size_t* Index = 0) {
		return string_to_float<float>(s, Index);
	}
	inline FloatingPoint<float> stof(const std::wstring& s, size_t* Index = 0) {
		return wstring_to_float<float>(s, Index);
	}
	inline FloatingPoint<double> stod(const std::string& s, size_t* Index = 0) {
		return string_to_float<double>(s, Index);
	}
	inline FloatingPoint<double> stod(const std::wstring& s, size_t* Index = 0) {
		return wstring_to_float<double>(s, Index);
	}
	inline FloatingPoint<long double> stold(const std::string& s, size_t* Index = 0) {
		return string_to_float<long double>(s, Index);
	}
	inline FloatingPoint<long double> stold(const std::wstring& s, size_t* Index = 0) {
		return wstring_to_float<long double>(s, Index);
	}
}
#endif
