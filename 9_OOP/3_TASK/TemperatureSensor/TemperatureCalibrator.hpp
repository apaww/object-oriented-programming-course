#pragma once

#include "TemperatureSensor.hpp"

class TemperatureSensor;

class TemperatureCalibrator {
public:
  static void calibrateCurrentTemperature(TemperatureSensor &sensor, double offset) {
    sensor.current_temperature += offset;
    sensor.normalize();
  } 

  static void calibrateLastTemperatures(TemperatureSensor &sensor, double offset) {
    for (int i = 0; i < sensor.size; ++i) {
      sensor.last_temperatures[i] += offset;
    }
    sensor.normalize();
  }
};
