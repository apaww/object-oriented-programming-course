#include <iostream>
#include "TemperatureSensor.hpp"
#include "TemperatureCalibrator.hpp"

int main() {
  double history[3] = {10.0, 15.0, 20.0};
  TemperatureSensor sensor("1", "1", 25.0, history, 3, 3);
  sensor.printSensor();

  TemperatureCalibrator::calibrateCurrentTemperature(sensor, -3.0);
  std::cout << "after calibrate current(-3)" << std::endl;
  sensor.printSensor();

  TemperatureCalibrator::calibrateLastTemperatures(sensor, 2.0);
  std::cout << "after calibrate last(+2)" << std::endl;
  sensor.printSensor();

  return 0;
}
