#include <iostream>
#include "TemperatureSensor.hpp"
#include "Meteostation.hpp"

int main() {
  TemperatureSensor external1("external 1", "1", 5.5, nullptr, 0, 0);
  TemperatureSensor external2("2", "2", 7.5, nullptr, 0, 0);

  Meteostation station(external1, external2);

  std::cout << "builtin:" << std::endl;
  station.printBuiltinSensor();

  std::cout << "external:" << std::endl;
  station.printExternalSensors();

  external1.setCurrentTemperature(6.0);
  external2.setCurrentTemperature(8.0);

  std::cout << "external after change:" << std::endl;
  station.printExternalSensors();
	return 0;
}
