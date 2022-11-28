#if !defined MINMAX_MANAGEMENT_NUMBER_CLASS_BASE
#define MINMAX_MANAGEMENT_NUMBER_CLASS_BASE
#include "clamp.hpp"
#include <cmath>
#include <type_traits>
#include <limits>
#include <stdexcept>
#ifdef max
#undef max
#endif
#ifdef min
#undef min
#endif

namespace standard {
	template<typename T> constexpr T typeMax = std::numeric_limits<T>::max();
	template<typename T> constexpr T typeMin = std::numeric_limits<T>::min();

	template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, std::nullptr_t> = nullptr>
	class NumberBase {
	protected:
		T n, maximum, minimum;
		constexpr const T& clamp(const T& num) {
			return standard::clamp(num, this->minimum, this->maximum);
		}
		using classbase = NumberBase<T>;
	public:
		constexpr NumberBase(const T& num = 0)
			: NumberBase(num, typeMax<T>, typeMin<T>) {}
		explicit constexpr NumberBase(const T& num, const T& max, const T& min)
			: n(standard::clamp(num, min, max)), maximum(max), minimum(min) {}
		constexpr NumberBase operator + (const NumberBase& num) const { return NumberBase(this->n + num.n, this->maximum, this->minimum); }
		constexpr NumberBase operator - () const { return NumberBase(-this->n, this->maximum, this->minimum); }
		constexpr NumberBase operator - (const NumberBase& num) const { return NumberBase(this->n - num.n, this->maximum, this->minimum); }
		constexpr NumberBase operator * (const NumberBase& num) const { return NumberBase(this->n * num.n, this->maximum, this->minimum); }
		NumberBase& operator += (const NumberBase& num) { 
			this->n = this->clamp(this->n + num.n); 
			return *this;
		}
		NumberBase& operator ++ () {
			this->n = this->clamp(this->n + 1);
			return *this;
		}
		NumberBase& operator ++ (int) {
			const auto t = *this;
			this->n = this->clamp(this->n + 1);
			return t;
		}
		NumberBase& operator -= (const NumberBase& num) { 
			this->n = this->clamp(this->n - num.n);
			return *this;
		}
		NumberBase operator -- () { 
			this->n = this->clamp(this->n - 1);
			return *this;
		}
		NumberBase& operator -- (int) {
			const auto t = *this;
			this->n = this->clamp(this->n - 1);
			return t;
		}
		NumberBase& operator *= (const NumberBase& num) {
			this->n = this->clamp(this->n * num.n);
			return *this;
		}

		// 現在値を取得する
		constexpr const T& Get() const noexcept { return this->n; }
		// 設定されている現在の最大値を取得する
		constexpr const T& GetMax() const noexcept { return this->maximum; }
		// 設定されている現在の最大値を取得する
		constexpr const T& GetMin() const noexcept { return this->minimum; }
		// 現在値を指定された値に変更する
		void Set(const T& num) noexcept { this->n = this->clamp(num); }
		// 最大値を指定された値に変更する
		// 例外 : 引数に指定された値が現在の最小値より小さい場合、std::runtime_errorが投げられる
		void SetMax(const T& num) {
			if (num < this->minimum) throw std::runtime_error("maximum must be larger than minimum.");
			this->maximum = num;
			this->n = this->clamp(this->n);
		}
		// 最小値を指定された値に変更する
		// 例外 : 引数に指定された値が現在の最大値より大きい場合、std::runtime_errorが投げられる
		void SetMin(const T& num) {
			if (num > this->maximum) throw std::runtime_error("minimum must be smaller than maximum.");
			this->minimum = num;
			this->n = this->clamp(this->n);
		}
		// 最大値に指定された値を加算する
		// 例外 : 引数に指定された値が負の場合、計算することによって最大値が最小値を下回る場合、std::runtime_errorが投げられる
		void AddToMax(const T& num) { this->SetMax(this->maximum + num); }
		// 最大値に指定された値を加算する
		// 例外 : 引数に指定された値が正の場合、計算することによって最小値が最大値を上回る場合、std::runtime_errorが投げられる
		void AddToMin(const T& num) { this->SetMin(this->minimum + num); }
	};
}
#endif
