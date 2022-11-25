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
			// �p�����[�^�[���Q�[�W�ŕ\������
			void ViewByGauge(const std::function<void(const I&, const I&)>& GaugeDrawFunction, const I& GaugeMaxLength) const {
				ParameterManager<I>::ViewByGauge(GaugeDrawFunction, GaugeMaxLength);
			}
			// �p�����[�^�[�𐔒l�ŕ\������B�ő�l�͕\�����Ȃ�
			void ViewByNumParam(const std::function<void(const I&)>& GaugeDrawFunction, const bool& UseCurrent = false) const {
				ParameterManager<I>::ViewByNumParam(GaugeDrawFunction, UseCurrent);
			}
			// �p�����[�^�[�𐔒l�ŕ\������B�ő�l���\������
			void ViewByNumParam(const std::function<void(const I&, const I&)>& GaugeDrawFunction, const bool& UseCurrent = false) const {
				ParameterManager<I>::ViewByNumParam(GaugeDrawFunction, UseCurrent);
			}
			// �\���p�����[�^�[�ƌ��݂̒l����������������
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
