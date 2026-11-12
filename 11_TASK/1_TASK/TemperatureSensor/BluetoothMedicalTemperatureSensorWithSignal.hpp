#pragma once

#include "MedicalTemperatureSensorWithSignal.hpp"
#include "BluetoothMedicalTemperatureSensor.hpp"
#include "MedicalTemperatureSensor.hpp"

class BluetoothMedicalTemperatureSensorWithSignal: public MedicalTemperatureSensorWithSignal, public BluetoothMedicalTemperatureSensor {
public:
	BluetoothMedicalTemperatureSensorWithSignal(std::string id, std::string in_batch_id, double current_temperature, double last_temperatures[], size_t size, size_t capacity, double lower_bound, double higher_bound, double beep_frequency, std::string method): MedicalTemperatureSensor(id, in_batch_id, current_temperature, last_temperatures, size, capacity, lower_bound, higher_bound), MedicalTemperatureSensorWithSignal(id, in_batch_id, current_temperature, last_temperatures, size, capacity, lower_bound, higher_bound, beep_frequency), BluetoothMedicalTemperatureSensor(id, in_batch_id, current_temperature, last_temperatures, size, capacity, lower_bound, higher_bound, method) {
                std::cout << "BluetoothMedicalTemperatureSensorWithSignal constructor called!" << std::endl;
        }
};
