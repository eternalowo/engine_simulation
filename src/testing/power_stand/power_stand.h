#ifndef POWER_STAND_H_
#define POWER_STAND_H_

#include <iostream>

#include "../stand_interface/stand_interface.h"
 
namespace engine {

	class PowerStand : public TestingStand {
	// power testing stand
	public:
		PowerStand(const InternalCombustionEngine& eng, double dt, double simulation_time,
			double Tamb) : TestingStand(eng), _simulation_time(simulation_time), _Tamb(Tamb) {}

		virtual auto start_testing() -> void override;

	private:
		double _dt;
		double _simulation_time;
		double _Tamb;
	};

} // namespace engine

#endif