#if !defined CXX14_COMPATIBLE_CLAMP
#define CXX14_COMPATIBLE_CLAMP
#include <algorithm>
#include <cassert>

#if defined _MSC_VER
#define CPP_VER _MSVC_LANG
#else
#define CPP_VER __cplusplus
#endif

namespace standard {
#if CPP_VER < 201703L
	template<typename T, class Compare> 
	constexpr const T& cxx14clamp(const T& v, const T& lo, const T& hi, Compare comp) {
		return assert(!comp(hi, lo)),
			comp(v, lo) ? lo : comp(hi, v) ? hi : v;
	}
#endif
	template<class T, std::enable_if_t<std::is_arithmetic<T>::value, std::nullptr_t> = nullptr> 
	constexpr const T& clamp(const T& v, const T& lo, const T& hi) {
#if CPP_VER < 201703L
		return cxx14clamp(v, lo, hi, std::less<>());
#else
		return std::clamp(v, lo, hi);
#endif
	}
}
#if defined CPP_VER
#undef CPP_VER
#endif
#endif
