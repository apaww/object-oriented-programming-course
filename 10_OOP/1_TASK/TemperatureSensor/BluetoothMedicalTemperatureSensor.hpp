#pragma once

#include "MedicalTemperatureSensor.hpp"

class BluetoothMedicalTemperatureSensor final: private MedicalTemperatureSensor {
public:
	void Send_T() {
		std::cout << "Temperatures sent!" << std::endl;
	}

	using MedicalTemperatureSensor::beep;
};
