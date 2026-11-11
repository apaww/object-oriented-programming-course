#include "TemperatureSensor.hpp"

unsigned int TemperatureSensor::fallback_id = 0;
unsigned int TemperatureSensor::object_count = 0;
const std::string TemperatureSensor::classname = "TemperatureSensor";

void calibrate(TemperatureSensor &sensor, double offset) {
    sensor.current_temperature += offset;
    for (size_t i = 0; i < sensor.size; ++i) {
      sensor.last_temperatures[i] += offset;
    }
    sensor.normalize();
}

std::ostream& operator<<(std::ostream& os, const TemperatureSensor& ts) {
  return ts.printSensor(os);
}

std::istream& operator>>(std::istream& is, TemperatureSensor& ts) {
  std::string in_batch_id;
  double current_temperature;
  is >> in_batch_id >> current_temperature;
  ts.setInBatchId(in_batch_id);
  ts.setCurrentTemperature(current_temperature);
  return is;
}
