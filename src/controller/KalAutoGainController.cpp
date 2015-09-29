/**************************************************************/
/*                                                            */
/*     ================[ KaLMIA Library ]================     */
/*                                                            */
/*           Kaji-Lab Moderate Instrumental Assets            */
/*                                                            */
/*     ============== " Be Ambitious For " ==============     */
/*                                                            */
/*              Muroran Institute of Technology               */
/*      Electronic System Control Engineering Laboratory      */
/*                                                            */
/**************************************************************/

// KalAutoGainController.cpp
#include <controller/KalAutoGainController.hpp>
namespace kalmia {
	namespace controller {
		KalAutoGainController::KalAutoGainController ()
			: gain_ (0), previous_value_ (0)
		{}

		void KalAutoGainController::Update (double t, double pv){
			if ((abs (pv) < abs (previous_value_)) && ((previous_value_*gain_) <= 0)){
				gain_ = 1 / previous_value_;
			}
			previous_value_ = pv;
		}

		double KalAutoGainController::Output (){
			return abs (gain_);
		}
	}
}
