#include "power_stand.h"

namespace engine {

	auto PowerStand::start_testing() -> void {
		// initial engine temperature
		double Teng{ _Tamb };

		// maximum power value
		double maxH{ 0.0 };
		// maximum crankshaft rotation speed
		double maxV{ 0.0 };

		for (std::size_t i = 0; i < _eng.get_M_size(); ++i) {
			double H{ _eng.get_power(i) };
			if (H > maxH) {
				maxH = H;
				maxV = _eng.get_V(i);
			}
		}

		std::cout << "Maximum power: " << maxH << " kilowatt with velocity: " << maxV << " radian per second" << std::endl;
	}

} // namespace engine