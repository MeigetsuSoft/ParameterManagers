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
		constexpr const T& clamp(const T num) {
			return standard::clamp(num, this->minimum, this->maximum);
		}
		using classbase = NumberBase<T>;
	public:
		constexpr NumberBase(const T& num = 0)
			: NumberBase(num, typeMax<T>, typeMin<T>) {}
		explicit constexpr NumberBase(const T& num, const T& max, const T& min)
			: n(standard::clamp(num, min, max)), maximum(max), minimum(min) {}
		constexpr NumberBase operator + (const NumberBase& num) const { return NumberBase(this->n + num.n, this->maximum, this->minimum); }
		constexpr NumberBase operator - (const NumberBase& num) const { return NumberBase(this->n - num.n, this->maximum, this->minimum); }
		constexpr NumberBase operator * (const NumberBase& num) const { return NumberBase(this->n * num.n, this->maximum, this->minimum); }
		NumberBase operator += (const NumberBase& num) { this->n = this->clamp(this->n + num.n); return *this; }
		NumberBase operator ++ () { this->n = this->clamp(this->n + 1); return *this; }
		NumberBase operator ++ (int) {
			const auto t = *this;
			this->n = this->clamp(this->n + 1);
			return t;
		}
		NumberBase operator - () const { return NumberBase(-this->n, this->maximum, this->minimum); }
		NumberBase operator -= (const NumberBase& num) { this->n = this->clamp(this->n - num.n); return *this; }
		NumberBase operator -- () { this->n = this->clamp(this->n - 1); return *this; }
		NumberBase operator -- (int) {
			const auto t = *this;
			this->n = this->clamp(this->n - 1);
			return t;
		}
		NumberBase operator *= (const NumberBase& num) { this->n = this->clamp(this->n = num.n); return *this; }

		// ���ݒl���擾����
		constexpr const T& Get() const noexcept { return this->n; }
		// �ݒ肳��Ă��錻�݂̍ő�l���擾����
		constexpr const T& GetMax() const noexcept { return this->maximum; }
		// �ݒ肳��Ă��錻�݂̍ő�l���擾����
		constexpr const T& GetMin() const noexcept { return this->minimum; }
		// ���ݒl���w�肳�ꂽ�l�ɕύX����
		void Set(const T& num) noexcept { this->n = this->clamp(num); }
		// �ő�l���w�肳�ꂽ�l�ɕύX����
		// ��O : �����Ɏw�肳�ꂽ�l�����݂̍ŏ��l��菬�����ꍇ�Astd::runtime_error����������
		void SetMax(const T& num) {
			if (num < this->minimum) throw std::runtime_error("maximum must be larger than minimum.");
			this->maximum = num;
			this->n = this->clamp(this->n);
		}
		// �ŏ��l���w�肳�ꂽ�l�ɕύX����
		// ��O : �����Ɏw�肳�ꂽ�l�����݂̍ő�l���傫���ꍇ�Astd::runtime_error����������
		void SetMin(const T& num) {
			if (num > this->maximum) throw std::runtime_error("minimum must be smaller than maximum.");
			this->minimum = num;
			this->n = this->clamp(this->n);
		}
		// �ő�l�Ɏw�肳�ꂽ�l�����Z����
		// ��O : �����Ɏw�肳�ꂽ�l�����̏ꍇ�A�v�Z���邱�Ƃɂ���čő�l���ŏ��l�������ꍇ�Astd::runtime_error����������
		void AddToMax(const T num) { this->SetMax(this->maximum + num); }
		// �ő�l�Ɏw�肳�ꂽ�l�����Z����
		// ��O : �����Ɏw�肳�ꂽ�l�����̏ꍇ�A�v�Z���邱�Ƃɂ���čŏ��l���ő�l������ꍇ�Astd::runtime_error����������
		void AddToMin(const T num) { this->SetMin(this->minimum + num); }
	};
}
#endif
