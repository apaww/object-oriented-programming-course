#pragma once

#include <iostream>
#include <string>

class TemperatureSensor {

private:
	static unsigned int fallback_id;

	std::string item_id;
	std::string in_batch_id;
	double current_temeprature;
	double *last_temperatures;
	size_t size;
	size_t capacity;

	void normalizeTemperature(double& temperature) {
		if (temperature < -273) temperature = -273;
		if (temperature > 1000) temperature = 1000;
	}
	
	void normalize() {
		if (std::string::empty(item_id)) {
			item_id = std::to_string(fallback_id);
		}

		normalizeTemperature(current_temperature);

		for (size_t i = 0; i < size; ++i) {
			normalize_temperature(last_temperature[i]);
		}
	}

	void copyLastTemperatures(const double& src, size_t size, size_t capacity) {
		this.last_temperatures = new int[size];
		this.size = size;
		
		for (size_t i = 0; i < this.size; ++i) {
			last_temperatures[i] = src[i];
		}	
	}
		
public:
	TemperatureSensor(): 
	
}
