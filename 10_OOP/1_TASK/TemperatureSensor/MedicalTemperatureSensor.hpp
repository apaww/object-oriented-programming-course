#pragma once

#include "TemperatureSensor.hpp"

class MedicalTemperatureSensor: public TemperatureSensor {
protected:
	void normalizeTemperature(double& temperature) override {                                                            
		if (temperature < 33.) temperature = 33.;
		if (temperature > 43.) temperature = 43.;
	}

public:
	void beep() {
		std::cout << "Beep! \a" << std::endl;
	}
};
