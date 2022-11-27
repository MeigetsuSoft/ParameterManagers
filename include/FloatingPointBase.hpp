#if !defined MINMAX_MANAGEMENT_FLOATING_NUMBER_CLASS_BASE
#define MINMAX_MANAGEMENT_FLOATING_NUMBER_CLASS_BASE
#include "NumberBase.hpp"

namespace standard {
	template<typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> = nullptr>
	class FloatingPoint : public NumberBase<T> {
	public:
		constexpr FloatingPoint(const T& num = 0)
			: NumberBase<T>(num, typeMax<T>, typeMin<T>) {}
		explicit constexpr FloatingPoint(const T& num, const T& max, const T& min)
			: NumberBase<T>(num, max, min) {}
		constexpr FloatingPoint(const NumberBase<T>& n)
			: NumberBase<T>(n) {}
		constexpr FloatingPoint operator + (const FloatingPoint& num) const { return NumberBase<T>::operator+(num); }
		constexpr FloatingPoint operator - (const FloatingPoint& num) const { return NumberBase<T>::operator-(num); }
		constexpr FloatingPoint operator - () const { return NumberBase<T>::operator-(); }
		constexpr FloatingPoint operator * (const FloatingPoint& num) const { return NumberBase<T>::operator*(num); }
		constexpr FloatingPoint operator / (const FloatingPoint& num) const {
			return num.n != 0
				? FloatingPoint(this->n / num.n, this->maximum, this->minimum)
				: throw std::runtime_error("Divide value is 0");
		}
		constexpr FloatingPoint operator % (const FloatingPoint& num) const {
			return num.n != 0
				? FloatingPoint(std::fmod(this->n, num.n), this->maximum, this->minimum)
				: throw std::runtime_error("Divide value is 0");
		}
		FloatingPoint& operator += (const FloatingPoint& num) {
			NumberBase<T>::operator+=(num);
			return *this;
		}
		FloatingPoint& operator ++ () {
			NumberBase<T>::operator++();
			return *this;
		}
		FloatingPoint& operator ++ (int) {
			NumberBase<T>::operator++(0);
			return *this;
		}
		FloatingPoint& operator -= (const FloatingPoint& num) {
			NumberBase<T>::operator-=(num);
			return *this;
		}
		FloatingPoint& operator -- () {
			NumberBase<T>::operator--();
			return *this;
		}
		FloatingPoint& operator -- (int) {
			NumberBase<T>::operator--(0);
			return *this;
		}
		FloatingPoint& operator *= (const FloatingPoint& num) {
			NumberBase<T>::operator*=(num);
			return *this;
		}
		FloatingPoint& operator /= (const FloatingPoint& num) {
			if (num.n == 0) throw std::runtime_error("Divide value is 0");
			this->n = this->clamp(this->n = num.n);
			return *this;
		}
		FloatingPoint& operator %= (const FloatingPoint& num) {
			if (num.n == 0) throw std::runtime_error("Divide value is 0");
			this->n = this->clamp(std::fmod(this->n, num.n));
			return *this;
		}
		constexpr bool operator == (const FloatingPoint& num) const { return std::abs(this->n - num.n) < std::numeric_limits<T>::epsilon(); }
		constexpr bool operator != (const FloatingPoint& num) const { return !this->operator==(num); }
		constexpr bool operator <  (const FloatingPoint& num) const { return !this->operator==(num) && this->n < num.n; }
		constexpr bool operator <= (const FloatingPoint& num) const { return !this->operator>(num); }
		constexpr bool operator >  (const FloatingPoint& num) const { return !this->operator==(num) && this->n > num.n; }
		constexpr bool operator >= (const FloatingPoint& num) const { return !this->operator<(num); }
		template<typename U, std::enable_if_t<std::is_floating_point<U>::value, std::nullptr_t> = nullptr>
		operator FloatingPoint<U>() {
			return FloatingPoint<U>(
				this->n,
				this->maximum >= std::numeric_limits<U>::max() ? std::numeric_limits<U>::max() : this->maximum,
				this->minimum <= std::numeric_limits<U>::min() ? std::numeric_limits<U>::min() : this->minimum
				);
		}
	};
}
#endif
