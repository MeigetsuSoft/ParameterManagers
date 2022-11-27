#if !defined MINMAX_MANAGEMENT_INTEGRAL_NUMBER_CLASS
#define MINMAX_MANAGEMENT_INTEGRAL_NUMBER_CLASS
#include "IntegerBase.hpp"
#include <string>

namespace standard {
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	constexpr Integer<T> clamp(const Integer<T>& v, const Integer<T>& lo, const Integer<T>& hi) { return Integer<T>(clamp<T>(v.Get(), lo.Get(), hi.Get())); }

	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline Integer<T> operator + (const T& n, const Integer<T>& num) {
		return Integer<T>(clamp(n + num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin()); 
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline Integer<T> operator - (const T& n, const Integer<T>& num) {
		return Integer<T>(clamp(n - num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin()); 
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline Integer<T> operator * (const T& n, const Integer<T>& num) {
		return Integer<T>(clamp(n * num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin()); 
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline Integer<T> operator / (const T& n, const Integer<T>& num) {
		return Integer<T>(clamp(n / num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin()); 
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline Integer<T> operator & (const T& n, const Integer<T>& num) {
		return Integer<T>(clamp(n & num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin());
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline Integer<T> operator % (const T& n, const Integer<T>& num) {
		return Integer<T>(clamp(n % num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin());
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline Integer<T> operator | (const T& n, const Integer<T>& num) {
		return Integer<T>(clamp(n | num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin());
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline Integer<T> operator ^ (const T& n, const Integer<T>& num) {
		return Integer<T>(clamp(n ^ num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin());
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline Integer<T> operator << (const T& n, const Integer<T>& num) {
		return Integer<T>(clamp(n << num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin());
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline Integer<T> operator >> (const T& n, const Integer<T>& num) {
		return Integer<T>(clamp(n >> num.Get(), num.GetMin(), num.GetMax()), num.GetMax(), num.GetMin());
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline bool operator == (const T& n, const Integer<T>& num) {
		return n == num.Get(); 
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline bool operator != (const T& n, const Integer<T>& num) {
		return n != num.Get(); 
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline bool operator <  (const T& n, const Integer<T>& num) {
		return n < num.Get(); 
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline bool operator <= (const T& n, const Integer<T>& num) {
		return n <= num.Get(); 
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline bool operator >  (const T& n, const Integer<T>& num) {
		return n > num.Get(); 
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline bool operator >= (const T& n, const Integer<T>& num) {
		return n >= num.Get();
	}

	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	constexpr Integer<T> max(const Integer<T>& Left, const Integer<T>& Right) {
		return Integer<T>(std::max(Left.Get(), Right.Get()));
	}

	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	inline Integer<T> abs(const Integer<T>& n) {
		return Integer<T>(n < 0 ? -n.Get() : n.Get()); 
	}

	namespace {
		template<typename T, std::enable_if_t<std::is_signed<T>::value, std::nullptr_t> = nullptr>
		Integer<T> string_to_signed_integer(const std::string& s, size_t* Index = 0, const int Base = 10) {return Integer<T>(static_cast<T>(std::stoll(s, Index, Base))); }
		template<typename T, std::enable_if_t<std::is_signed<T>::value, std::nullptr_t> = nullptr>
		Integer<T> wstring_to_signed_integer(const std::wstring& s, size_t* Index = 0, const int Base = 10) {return Integer<T>(static_cast<T>(std::stoll(s, Index, Base))); }
		template<typename T, std::enable_if_t<std::is_unsigned<T>::value, std::nullptr_t> = nullptr>
		Integer<T> string_to_unsigned_integer(const std::string& s, size_t* Index = 0, const int Base = 10) {return Integer<T>(static_cast<T>(std::stoull(s, Index, Base))); }
		template<typename T, std::enable_if_t<std::is_unsigned<T>::value, std::nullptr_t> = nullptr>
		Integer<T> wstring_to_unsigned_integer(const std::wstring& s, size_t* Index = 0, const int Base = 10) {return Integer<T>(static_cast<T>(std::stoull(s, Index, Base))); }
	}
	inline Integer<int> stoi(const std::string& s, size_t* Index = 0, const int Base = 10) {return string_to_signed_integer<int>(s, Index, Base); }
	inline Integer<int> stoi(const std::wstring& s, size_t* Index = 0, const int Base = 10) {return wstring_to_signed_integer<int>(s, Index, Base); }
	inline Integer<long> stol(const std::string& s, size_t* Index = 0, const int Base = 10) {return string_to_signed_integer<long>(s, Index, Base); }
	inline Integer<long> stol(const std::wstring& s, size_t* Index = 0, const int Base = 10) {return wstring_to_signed_integer<long>(s, Index, Base); }
	inline Integer<long long> stoll(const std::string& s, size_t* Index = 0, const int Base = 10) {return string_to_signed_integer<long long>(s, Index, Base); }
	inline Integer<long long> stoll(const std::wstring& s, size_t* Index = 0, const int Base = 10) {return wstring_to_signed_integer<long long>(s, Index, Base); }
	inline Integer<unsigned int> stoui(const std::string& s, size_t* Index = 0, const int Base = 10) {return string_to_unsigned_integer<unsigned int>(s, Index, Base); }
	inline Integer<unsigned int> stoui(const std::wstring& s, size_t* Index = 0, const int Base = 10) {return wstring_to_unsigned_integer<unsigned int>(s, Index, Base); }
	inline Integer<unsigned long> stoul(const std::string& s, size_t* Index = 0, const int Base = 10) {return string_to_unsigned_integer<unsigned long>(s, Index, Base); }
	inline Integer<unsigned long> stoul(const std::wstring& s, size_t* Index = 0, const int Base = 10) {return wstring_to_unsigned_integer<unsigned long>(s, Index, Base); }
	inline Integer<unsigned long long> stoull(const std::string& s, size_t* Index = 0, const int Base = 10) {return string_to_unsigned_integer<unsigned long long>(s, Index, Base); }
	inline Integer<unsigned long long> stoull(const std::wstring& s, size_t* Index = 0, const int Base = 10) {return wstring_to_unsigned_integer<unsigned long long>(s, Index, Base); }
}
#endif
