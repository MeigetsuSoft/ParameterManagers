#if !defined MINMAX_MANAGEMENT_NUMBER_CLASS
#define MINMAX_MANAGEMENT_NUMBER_CLASS
#include "Integer.hpp"
#include "FloatingPoint.hpp"

namespace standard {
	template<typename I, typename F, std::enable_if_t<std::is_integral<I>::value && std::is_floating_point<F>::value, std::nullptr_t> = nullptr>
	inline Integer<I> operator + (const Integer<I>& i, const FloatingPoint<F>& f) {
		return Integer<I>(i.Get() + static_cast<I>(f.Get()), i.GetMax(), i.GetMin());
	}
	template<typename I, typename F, std::enable_if_t<std::is_integral<I>::value&& std::is_floating_point<F>::value, std::nullptr_t> = nullptr>
	inline Integer<I> operator - (const Integer<I>& i, const FloatingPoint<F>& f) {
		return Integer<I>(i.Get() - static_cast<I>(f.Get()), i.GetMax(), i.GetMin());
	}
	template<typename I, typename F, std::enable_if_t<std::is_integral<I>::value&& std::is_floating_point<F>::value, std::nullptr_t> = nullptr>
	inline Integer<I> operator * (const Integer<I>& i, const FloatingPoint<F>& f) {
		return Integer<I>(i.Get() * static_cast<I>(f.Get()), i.GetMax(), i.GetMin());
	}
	template<typename I, typename F, std::enable_if_t<std::is_integral<I>::value&& std::is_floating_point<F>::value, std::nullptr_t> = nullptr>
	inline Integer<I> operator / (const Integer<I>& i, const FloatingPoint<F>& f) {
		if (f.Get() < std::numeric_limits<F>::epsilon()) throw std::runtime_error("Divide value is 0");
		return Integer<I>(i.Get() / static_cast<I>(f.Get()), i.GetMax(), i.GetMin());
	}
	template<typename I, typename F, std::enable_if_t<std::is_integral<I>::value&& std::is_floating_point<F>::value, std::nullptr_t> = nullptr>
	inline Integer<I> operator % (const Integer<I>& i, const FloatingPoint<F>& f) {
		if (f.Get() < std::numeric_limits<F>::epsilon()) throw std::runtime_error("Divide value is 0");
		return Integer<I>(std::fmod(static_cast<F>(i.Get()), f.Get()), i.GetMax(), i.GetMin());
	}

	template<typename I, typename F, std::enable_if_t<std::is_integral<I>::value&& std::is_floating_point<F>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<F> operator + (const FloatingPoint<F>& f, const Integer<I>& i) {
		return FloatingPoint<F>(f.Get() + static_cast<F>(i.Get()), f.GetMax(), f.GetMin());
	}
	template<typename I, typename F, std::enable_if_t<std::is_integral<I>::value&& std::is_floating_point<F>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<F> operator - (const FloatingPoint<F>& f, const Integer<I>& i) {
		return FloatingPoint<F>(f.Get() - static_cast<F>(i.Get()), f.GetMax(), f.GetMin());
	}
	template<typename I, typename F, std::enable_if_t<std::is_integral<I>::value&& std::is_floating_point<F>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<F> operator * (const FloatingPoint<F>& f, const Integer<I>& i) {
		return FloatingPoint<F>(f.Get() * static_cast<F>(i.Get()), f.GetMax(), f.GetMin());
	}
	template<typename I, typename F, std::enable_if_t<std::is_integral<I>::value&& std::is_floating_point<F>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<F> operator / (const FloatingPoint<F>& f, const Integer<I>& i) {
		if (i.Get() == 0) throw std::runtime_error("Divide value is 0");
		return FloatingPoint<F>(f.Get() / static_cast<F>(i.Get()), f.GetMax(), f.GetMin());
	}
	template<typename I, typename F, std::enable_if_t<std::is_integral<I>::value&& std::is_floating_point<F>::value, std::nullptr_t> = nullptr>
	inline FloatingPoint<F> operator % (const FloatingPoint<F>& f, const Integer<I>& i) {
		if (i.Get() == 0) throw std::runtime_error("Divide value is 0");
		return FloatingPoint<F>(std::fmod(f.Get(), static_cast<F>(i.Get())), f.GetMax(), f.GetMin());
	}
}
#endif
