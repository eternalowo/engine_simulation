#ifndef TESTING_STAND_INTERFACE_H_
#define TESTING_STAND_INTERFACE_H_

#include "../../engine/internal_combustion_engine/internal_combustion_engine.h"

namespace engine {

	class TestingStand {
	// testing stand interface
	// (я не стал выносить dt, начальное время и температуру окружения в данный класс
	// т.к. предполагаю, что тестирование может быть связано не только с данными параметрами)
	public:
		explicit TestingStand(const InternalCombustionEngine& eng) : _eng(eng) {}

		virtual auto start_testing() -> void = 0;

	protected:
		InternalCombustionEngine _eng;
	};

} // namespace enging

#endif