#if !defined MGST_CPP_PARAMETER_MANAGER_CLASS
#define MGST_CPP_PARAMETER_MANAGER_CLASS
#include "Number.hpp"
#include <algorithm>
#include <functional>
#include <concepts>

namespace meigetsusoft {
	namespace {
		template<std::integral I>
		constexpr I CalcPercentIntBase(const standard::Integer<I>& Param) {
			return (Param.Get() - Param.GetMin()) * 100 / (Param.GetMax() - Param.GetMin());
		}
		template<std::integral I>
		constexpr I CalcLength(const standard::Integer<I>& Param) {
			const I Base = CalcPercentIntBase(Param);
			switch (Base) {
				case 0:
					return Param.Get() != Param.GetMin();
				case 100:
					return 100 - (Param.Get() != Param.GetMax());
				default:
					return Base;
			}
		}
		template<std::signed_integral I>
		constexpr I abs(const I& val) { return val < 0 ? -val : val; }
	}
	template<std::signed_integral I>
	class ParameterManager {
	private:
		standard::Integer<I> CurrentParam;
		standard::Integer<I> CurrentViewParam;
		standard::Integer<I> LastApplySpeed;
	protected:
		constexpr const standard::Integer<I>& GetCurrentParam() const noexcept { return this->CurrentParam; }
		constexpr const standard::Integer<I>& GetCurrentViewParam() const noexcept { return this->CurrentViewParam; }
	public:
		ParameterManager() = default;
		constexpr ParameterManager(const I& Default, const I& Max = standard::typeMax<I>, const I& Min = standard::typeMin<I>)
			: ParameterManager(Default, Default, Max, Min) {}
		constexpr ParameterManager(const I& Default, const I& ViewDefault, const I& Max, const I& Min)
			: CurrentParam(Default, Max, Min), CurrentViewParam(Default, Max, Min), LastApplySpeed(0) {}
		// パラメーターをゲージで表示する
		void ViewByGauge(const std::function<void(const I&, const I&)>& GaugeDrawFunction, const I& GaugeMaxLength) const {
			const I& CurrentLen = CalcLength(this->CurrentParam),
				CurrentViewLen = CalcLength(this->CurrentParam);
			GaugeDrawFunction(std::max(CurrentLen, CurrentViewLen), std::min(CurrentLen, CurrentViewLen));
		}
		// パラメーターを数値で表示する。最大値は表示しない
		void ViewByNumParam(const std::function<void(const I&)>& ParameterDrawFunction, const bool& UseCurrent = false) const {
			ParameterDrawFunction(UseCurrent ? this->CurrentParam.Get() : this->CurrentViewParam.Get());
		}
		// パラメーターを数値で表示する。最大値も表示する
		void ViewByNumParam(const std::function<void(const I&, const I&)>& ParameterDrawFunction, const bool& UseCurrent = false) const {
			const auto& UseParam = UseCurrent ? this->CurrentParam : this->CurrentViewParam;
			ParameterDrawFunction(UseParam.Get(), UseParam.GetMax());
		}
		// 表示パラメーターと現在の値を少しずつ同期する
		void Update() {
			if (this->Synced()) {
				this->LastApplySpeed = 0;
				return;
			}
			const auto ApplySpeed = standard::clamp<I>(
				standard::max(this->LastApplySpeed, standard::abs(this->CurrentParam - this->CurrentViewParam) / 10).Get(),
				1, 
				abs(this->CurrentParam.Get() - this->CurrentViewParam.Get())
			);
			this->CurrentViewParam -= this->CurrentParam < this->CurrentViewParam ? ApplySpeed : -ApplySpeed;
			this->LastApplySpeed = ApplySpeed;
 		}
		constexpr bool Synced() const noexcept {
			return this->CurrentParam == this->CurrentViewParam;
		}
		ParameterManager& operator += (const I& Val) {
			this->CurrentParam += Val;
			return *this;
		}
		ParameterManager& operator -= (const I& Val) {
			this->CurrentParam -= Val;
			return *this;
		}
		constexpr bool IsMin() const noexcept {
			return this->CurrentParam.Get() == this->CurrentParam.GetMin();
		}
		constexpr bool IsMax() const noexcept {
			return this->CurrentParam.Get() == this->CurrentParam.GetMax();
		}
		template<std::floating_point F>
		constexpr standard::FloatingPoint<F> GetRatio() const noexcept {
			const auto& Param = this->CurrentParam;
			return standard::FloatingPoint<F>(static_cast<F>(Param.Get() - Param.GetMin()) * 100.0 / static_cast<F>(Param.GetMax() - Param.GetMin()));
		}
	};
}
#endif
