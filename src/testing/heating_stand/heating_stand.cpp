#include "heating_stand.h"

namespace engine {

	auto HeatingStand::start_testing() -> void {
		// initial engine temperature
		double Teng{ _Tamb };

		bool oh_flag{ true };

		for (std::size_t i = 0; i < _eng.get_M_size(); ++i) {
			double heating_rate = _eng.get_heating_rate(i);
			double cooling_rate = _eng.get_cooling_rate(_Tamb, Teng);

			double t_change{ heating_rate - cooling_rate };
			Teng += t_change * _dt;
			_simulation_time += _dt;

			if (Teng >= _eng.get_Toh()) {
				oh_flag = false;
				std::cout << std::endl << "Time until overheating: " << _simulation_time << " seconds" << std::endl;
				break;
			}
		}
		
		if (oh_flag) {
			std::cout << std::endl << "Engine will not overheat" << std::endl;
		}
	}

} // namespace engine