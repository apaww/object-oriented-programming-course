#pragma once

#include "MedicalTemperatureSensor.hpp"

class BluetoothMedicalTemperatureSensor: virtual public MedicalTemperatureSensor {
protected:
	std::string method;
public:
	BluetoothMedicalTemperatureSensor(std::string id, std::string in_batch_id, double current_temperature, double last_temperatures[], size_t size, size_t capacity, double lower_bound, double higher_bound, std::string method): MedicalTemperatureSensor(id, in_batch_id, current_temperature, last_temperatures, size, capacity, lower_bound, higher_bound), method(method) {
                std::cout << "BluetoothMedicalTemperatureSensor constructor called!" << std::endl;
        }

	void Send_T() {
		std::cout << "Temperatures sent via " << method << "!" << std::endl;
	}
};
