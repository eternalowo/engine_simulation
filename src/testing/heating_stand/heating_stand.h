#ifndef HEATING_STAND_H_
#define HEATING_STAND_H_

#include <iostream>

#include "../stand_interface/stand_interface.h"

namespace engine {

	class HeatingStand : public TestingStand {
	// heat testing stand
	public: 
		HeatingStand(const InternalCombustionEngine& eng, double dt, double simulation_time,
			double Tamb) : TestingStand(eng), _dt(dt), _simulation_time(simulation_time), _Tamb(Tamb) {}

		virtual auto start_testing() -> void override;

	private:
		double _dt;
		double _simulation_time;
		double _Tamb;
	};

} // namespace engine

#endif