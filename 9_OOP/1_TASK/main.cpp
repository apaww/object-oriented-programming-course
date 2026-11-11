#include <iostream>
#include "TemperatureSensor.hpp"
#include "TemperatureManufacturer.hpp"

int main() {
  TemperatureSensor sensor("1", "1", 20.0, nullptr, 0, 0);
  sensor.printSensor();

  calibrate(sensor, 5.0);
  std::cout << "after calibrate(+5)" << std::endl;
  sensor.printSensor();

  TemperatureManufacturer::setCurrentTemperature(sensor, 5000.0);
  TemperatureManufacturer::setInBatchId(sensor, "2");
  TemperatureManufacturer::addLastTemperature(sensor, 42.0);
  std::cout << "after manufacturer" << std::endl;
  sensor.printSensor();

  return 0;
}
