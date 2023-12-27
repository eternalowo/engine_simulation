#include "internal_combustion_engine.h"

namespace engine {

	auto InternalCombustionEngine::get_acceleration(std::size_t i) const -> double {
		return _M[i] / _I;
	}

	auto InternalCombustionEngine::get_heating_rate(std::size_t i) const -> double {
		return _M[i] * _Hm + _V[i] * _V[i] * _Hv;
	}

	auto InternalCombustionEngine::get_cooling_rate(double Tamb, double Teng) const -> double {
		return _C * (Tamb - Teng);
	}

	auto InternalCombustionEngine::get_power(std::size_t i) const -> double {
		return _M[i] * _V[i] / 1000.0;
	}

	auto InternalCombustionEngine::get_M_size() const -> std::size_t {
		return _M.size();
	}

	auto InternalCombustionEngine::get_V(std::size_t i) const -> double {
		return _V[i];
	}

} // namespace engine 