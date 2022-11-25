#if !defined MGST_CPP_STEP_CHANGE_PARAMETER_CLASS
#define MGST_CPP_STEP_CHANGE_PARAMETER_CLASS
#include "ParameterManager.hpp"

namespace meigetsusoft {
	namespace DefeatMonster {
		template<std::signed_integral I>
		class StepChangeParameter : private ParameterManager<I> {
		private:
			const I StepWidth;
		public:
			constexpr StepChangeParameter() : StepChangeParameter(0, 0) {}
			constexpr StepChangeParameter(const I& Default, const I& StepCount)
				: ParameterManager<I>(Default, (Default * 2) - (Default % StepCount), Default% StepCount), StepWidth(Default / StepCount) {}
			// パラメーターをゲージで表示する
			void ViewByGauge(const std::function<void(const I&, const I&)>& GaugeDrawFunction, const I& GaugeMaxLength) const {
				ParameterManager<I>::ViewByGauge(GaugeDrawFunction, GaugeMaxLength);
			}
			// パラメーターを数値で表示する。最大値は表示しない
			void ViewByNumParam(const std::function<void(const I&)>& GaugeDrawFunction, const bool& UseCurrent = false) const {
				ParameterManager<I>::ViewByNumParam(GaugeDrawFunction, UseCurrent);
			}
			// パラメーターを数値で表示する。最大値も表示する
			void ViewByNumParam(const std::function<void(const I&, const I&)>& GaugeDrawFunction, const bool& UseCurrent = false) const {
				ParameterManager<I>::ViewByNumParam(GaugeDrawFunction, UseCurrent);
			}
			// 表示パラメーターと現在の値を少しずつ同期する
			void Update() {
				ParameterManager<I>::Update();
			}
			constexpr bool Synced() const noexcept {
				return ParameterManager<I>::Synced();
			}
			StepChangeParameter& operator += (const I& Step) {
				ParameterManager<I>::operator+=(Step * this->StepWidth);
				return *this;
			}
			StepChangeParameter& operator -= (const I& Step) {
				ParameterManager<I>::operator-=(Step * this->StepWidth);
				return *this;
			}
			constexpr bool IsMin() const noexcept {
				return ParameterManager<I>::IsMin();
			}
			constexpr bool IsMax() const noexcept {
				return ParameterManager<I>::IsMax();
			}
			constexpr I GetCurrentStep() const noexcept {
				const auto& Current = this->GetCurrentParam();
				return (Current.Get() - ((Current.GetMax() + Current.GetMin()) / 2)) / this->StepWidth;
			}
		};
	}
}
#endif
