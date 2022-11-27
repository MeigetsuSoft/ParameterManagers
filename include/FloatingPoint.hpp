#if !defined MINMAX_MANAGEMENT_FLOATING_NUMBER_CLASS
#define MINMAX_MANAGEMENT_FLOATING_NUMBER_CLASS
#include "FloatingPointBase.hpp"
#include <string>

namespace standard {
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<T> operator + (const T& n, const FloatingPoint<T>& num) {
		return FloatingPoint<T>(n + num.Get(), num.GetMax(), num.GetMin());
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<T> operator - (const T& n, const FloatingPoint<T>& num) {
		return FloatingPoint<T>(n - num.Get(), num.GetMax(), num.GetMin());
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<T> operator * (const T& n, const FloatingPoint<T>& num) {
		return FloatingPoint<T>(n * num.Get(), num.GetMax(), num.GetMin());
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<T> operator / (const T& n, const FloatingPoint<T>& num) {
		if (std::abs(num.Get()) < std::numeric_limits<T>::epsilon()) throw std::runtime_error("Divide value is 0");
		return FloatingPoint<T>(n / num.Get(), num.GetMax(), num.GetMin());
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<T> operator % (const T& n, const FloatingPoint<T>& num) {
		if (std::abs(num.Get()) < std::numeric_limits<T>::epsilon()) throw std::runtime_error("Divide value is 0");
			return FloatingPoint<T>(std::fmod(n, num.Get()), num.GetMax(), num.GetMin());
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
		return assert(hi < lo), v < lo ? lo : hi < v ? hi : v;
	}

	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	constexpr const FloatingPoint<T>& max(const FloatingPoint<T>& Left, const FloatingPoint<T>& Right) {
		return Left < Right ? Right : Left;
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	constexpr const FloatingPoint<T>& min(const FloatingPoint<T>& Left, const FloatingPoint<T>& Right) {
		return Left > Right ? Right : Left;
	}
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<T> abs(const FloatingPoint<long double>& n) {
		return n < 0 ? -n : n;
	}
	namespace {
		template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
		FloatingPoint<T> string_to_float(const std::string& s, size_t* Index = 0) {
			return FloatingPoint<T>(static_cast<T>(std::stold(s, Index)));
		}
		template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
		FloatingPoint<T> wstring_to_float(const std::wstring& s, size_t* Index = 0) {
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
