#ifndef HEAT_ENGINE_INTERFACE_H_
#define HEAT_ENGINE_INTERFACE_H_

namespace engine {

	class HeatEngine { 
	// heat engine interface
	// (предполагается, что моделироваться будет работа именно тепловых двигателей)
	public:
		explicit HeatEngine(double Toh) : _Toh(Toh) {}

		virtual auto get_Toh() const -> double { return _Toh; };

	private:
		double _Toh; // overheating temperature
	};

} // namespace engine

#endif