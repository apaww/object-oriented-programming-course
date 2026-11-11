#pragma once

#include "TemperatureSensor.hpp"

class Meteostation {
private:
  TemperatureSensor builtin_sensor;
  TemperatureSensor& external_sensor1;
  TemperatureSensor& external_sensor2;

public:
  Meteostation(TemperatureSensor& ts1, TemperatureSensor& ts2): builtin_sensor("123", "123", 20., nullptr, 0, 0), external_sensor1(ts1), external_sensor2(ts2) {}

  void printBuiltinSensor() const {
    builtin_sensor.printSensor();
  }

  void printExternalSensors() const {
    external_sensor1.printSensor();
    external_sensor2.printSensor();
  }
};
