#include <iostream>

#include "../src/testing/heating_stand/heating_stand.h"
#include "../src/testing/power_stand/power_stand.h"

int main() {
	// initial configuration
	const double I{ 10.0 };
	const std::vector<double> M{ 20.0, 75.0, 100.0, 105.0, 75.0,  0.0 };
	const std::vector<double> V{ 0.0,  75.0, 150.0, 200.0, 250.0, 300.0};
	const double Toh{ 110.0 };
	const double Hm{ 0.01 };
	const double Hv{ 0.0001 };
	const double C{ 0.1 };

	// предполагается, что значения M и V меняются со временем dt, т.к. не указано точно время,
	// в течение которого происходят изменения, дана только зависимость двух величин
	const double dt{ 0.1 };

	// initial simulation time
	double simulation_time{ 0.0 };

	// ambient temperature
	double Tamb{ 20.0 };
	std::cout << "Enter ambient temperature: ";
	std::cin >> Tamb;

	auto testing_engine{ engine::InternalCombustionEngine(I, M, V, Toh, Hm, Hv, C) };
	
	auto heating_test{ engine::HeatingStand(testing_engine, dt, simulation_time, Tamb) };
	auto power_test{ engine::PowerStand(testing_engine, dt, simulation_time, Tamb) };

	// starting tests
	heating_test.start_testing();
	power_test.start_testing();

	return 0;
}