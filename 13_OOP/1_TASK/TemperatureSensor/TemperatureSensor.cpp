#include "TemperatureSensor.hpp"

unsigned int TemperatureSensor::fallback_id = 0;
unsigned int TemperatureSensor::object_count = 0;
const std::string TemperatureSensor::classname = "TemperatureSensor";

std::ostream& operator<<(std::ostream& os, const TemperatureSensor& ts) {
	ts.printSensor();
	return os;
}

std::istream& operator>>(std::istream& is, TemperatureSensor& ts) {
	is >> ts.in_batch_id >> ts.current_temperature;
	return is;
}
