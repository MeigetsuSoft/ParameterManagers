#if !defined MINMAX_MANAGEMENT_INTEGRAL_NUMBER_CLASS_BASE
#define MINMAX_MANAGEMENT_INTEGRAL_NUMBER_CLASS_BASE
#include "NumberBase.hpp"

namespace standard {
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
	class Integer : public NumberBase<T> {
	public:
		Integer() = default;
		constexpr Integer(const T& num = 0)
			: NumberBase<T>(num, typeMax<T>, typeMin<T>) {}
		explicit constexpr Integer(const T& num, const T& max, const T& min)
			: NumberBase<T>(num, max, min) {}
		constexpr Integer(const NumberBase<T>& n)
			: NumberBase<T>(n) {}
		constexpr Integer operator + (const Integer& num) const { return NumberBase<T>::operator+(num); }
		constexpr Integer operator - (const Integer& num) const { return NumberBase<T>::operator-(num); }
		constexpr Integer operator * (const Integer& num) const { return NumberBase<T>::operator*(num); }
		constexpr Integer operator / (const Integer& num) const {
			return num.n != 0
				? Integer(this->n / num.n, this->maximum, this->minimum)
				: throw std::runtime_error("Divide value is 0");
		}
		constexpr Integer operator & (const Integer& num) const { return Integer(this->n & num.n, this->maximum, this->minimum); }
		constexpr Integer operator % (const Integer& num) const {
			return num.n != 0
				? Integer(this->n % num.n, this->maximum, this->minimum)
				: throw std::runtime_error("Divide value is 0");
		}
		constexpr Integer operator | (const Integer& num) const { return Integer(this->n | num.n, this->maximum, this->minimum); }
		constexpr Integer operator ^ (const Integer& num) const { return Integer(this->n ^ num.n, this->maximum, this->minimum); }
		constexpr Integer operator ~ () const { return Integer(~this->n, this->maximum, this->minimum); }
		constexpr Integer operator << (const Integer& num) const { return Integer(this->n << num.n, this->maximum, this->minimum); }
		constexpr Integer operator >> (const Integer& num) const { return Integer(this->n >> num.n, this->maximum, this->minimum); }
		Integer operator += (const Integer& num) { return NumberBase<T>::operator+=(num); }
		Integer operator ++ () { return NumberBase<T>::operator++(); }
		Integer operator ++ (int) { return NumberBase<T>::operator++(0); }
		Integer operator - () const { return NumberBase<T>::operator-(); }
		Integer operator -= (const Integer& num) { return NumberBase<T>::operator-=(num); }
		Integer operator -- () { return NumberBase<T>::operator--(); }
		Integer operator -- (int) { return NumberBase<T>::operator--(0); }
		Integer operator *= (const Integer& num) { return NumberBase<T>::operator*=(num); }
		Integer operator /= (const Integer& num) {
			if (num.n == 0) throw std::runtime_error("Divide value is 0");
			this->n = this->clamp(this->n / num.n);
			return *this;
		}
		Integer operator &= (const Integer& num) { this->n = this->clamp(this->n & num.n); return *this; }
		Integer operator %= (const Integer& num) {
			if (num.n == 0) throw std::runtime_error("Divide value is 0");
			this->n = this->clamp(this->n % num.n);
			return *this;
		}
		Integer operator |= (const Integer& num) { this->n = this->clamp(this->n | num.n); return *this; }
		Integer operator ^= (const Integer& num) { this->n = this->clamp(this->n ^ num.n); return *this; }
		Integer operator <<= (const Integer& num) {
			this->n = this->clamp(this->n << num.n);
			return *this;
		}
		Integer operator >>= (const Integer& num) {
			this->n = this->clamp(this->n >> num.n);
			return *this;
		}
		constexpr bool operator == (const Integer& num) const { return this->n == num.n; }
		constexpr bool operator != (const Integer& num) const { return this->n != num.n; }
		constexpr bool operator <  (const Integer& num) const { return this->n < num.n; }
		constexpr bool operator <= (const Integer& num) const { return this->n <= num.n; }
		constexpr bool operator >  (const Integer& num) const { return this->n > num.n; }
		constexpr bool operator >= (const Integer& num) const { return this->n >= num.n; }
		template<typename U, std::enable_if_t<std::is_integral<U>::value, std::nullptr_t> = nullptr>
		operator Integer<U>() {
			return Integer<U>(
				this->n,
				this->maximum >= std::numeric_limits<U>::max() ? std::numeric_limits<U>::max() : this->maximum,
				this->minimum <= std::numeric_limits<U>::min() ? std::numeric_limits<U>::min() : this->minimum
				);
		}
	};
}
#endif
