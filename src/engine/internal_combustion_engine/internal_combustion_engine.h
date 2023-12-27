#ifndef INTERNAL_COMBUSTION_ENGINE_H_
#define INTERNAL_COMBUSTION_ENGINE_H_

#include <vector>

#include "../heat_engine_interface/heat_engine_interface.h"

namespace engine {

	class InternalCombustionEngine : public HeatEngine {
	// internal combustion engine class
	public:
		InternalCombustionEngine(double I, const std::vector<double>& M,
			const std::vector<double>& V, double Toh, double Hm, double Hv, double C)
			: HeatEngine(Toh), _I(I), _M(M), _V(V), _Hm(Hm), _Hv(Hv), _C(C) {}
		
		auto get_acceleration(std::size_t i) const -> double;

		auto get_heating_rate(std::size_t i) const -> double;

		auto get_cooling_rate(double Tamb, double Teng) const -> double;

		auto get_power(std::size_t i) const -> double;

		auto get_M_size() const -> std::size_t;

		auto get_V(std::size_t i) const -> double;

	private:
		double _I, _Hm, _Hv, _C;
		std::vector<double> _M;
		std::vector<double> _V;
	};

} // namespace engine

#endif