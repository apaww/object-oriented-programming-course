#pragma once

#include "MedicalTemperatureSensor.hpp"

class MedicalTemperatureSensorWithSignal: virtual public MedicalTemperatureSensor {
protected:
	double beep_frequency;
public:
	MedicalTemperatureSensorWithSignal(std::string id, std::string in_batch_id, double current_temperature, double last_temperatures[], size_t size, size_t capacity, double lower_bound, double higher_bound, double beep_frequency): MedicalTemperatureSensor(id, in_batch_id, current_temperature, last_temperatures, size, capacity, lower_bound, higher_bound), beep_frequency(beep_frequency) {
		std::cout << "MedicalTemperatureSensorWithSignal constructor called!" << std::endl;
	}
	void beep() {
		std::cout << "beep at " << beep_frequency << " frequency!\a" << std::endl;
	}
};
