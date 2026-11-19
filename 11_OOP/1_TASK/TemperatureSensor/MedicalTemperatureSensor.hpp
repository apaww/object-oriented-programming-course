#pragma once

#include "TemperatureSensor.hpp"

class MedicalTemperatureSensor: public TemperatureSensor {
protected:
	double lower_bound;
	double higher_bound;

	void normalizeTemperature(double& temperature) override {                                                            
		if (temperature < lower_bound) temperature = lower_bound;
		if (temperature > higher_bound) temperature = higher_bound;
	}
public:
	MedicalTemperatureSensor(std::string id, std::string in_batch_id, double current_temperature, double last_temperatures[], size_t size, size_t capacity, double lower_bound, double higher_bound): TemperatureSensor(id, in_batch_id, current_temperature, last_temperatures, size, capacity), lower_bound(lower_bound), higher_bound(higher_bound) {
		std::cout << "MedicalTemperatureSensor constructor called!" << std::endl;
		normalize();
        }
};
