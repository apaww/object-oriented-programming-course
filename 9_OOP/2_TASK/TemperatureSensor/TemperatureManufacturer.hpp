#pragma once

#include "TemperatureSensor.hpp"

class TemperatureSensor;

class TemperatureManufacturer {
public:
  static void setInBatchId(TemperatureSensor &sensor, const std::string& in_batch_id) {
    sensor.in_batch_id = in_batch_id;
  }

  static void setCurrentTemperature(TemperatureSensor &sensor, const double temperature) {
    sensor.current_temperature = temperature;
    sensor.normalize();
  }

  static void addLastTemperature(TemperatureSensor &sensor, const double temperature) {
    sensor.addLastTemperature(temperature);
  }
};
