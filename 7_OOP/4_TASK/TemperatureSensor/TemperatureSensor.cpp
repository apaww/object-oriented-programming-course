#include "TemperatureSensor.hpp"

unsigned int TemperatureSensor::fallback_id = 0;
unsigned int TemperatureSensor::object_count = 0;
const std::string TemperatureSensor::classname = "TemperatureSensor";

std::ostream& operator<<(std::ostream& os, const TemperatureSensor& ts) {
	ts.printSensor();
	return os;
}
