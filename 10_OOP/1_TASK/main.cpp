#include <iostream>
#include "TemperatureSensor.hpp"

int main() {
	double history[10] = {20.5, 21.0, 19.8, 22.3, 20.1, 21.7, 19.5, 20.9, 21.4, 20.0};

	TemperatureSensor original("001", "67", 21.5, history, 10, 10);

	TemperatureSensor copied = original;

	TemperatureSensor assignment;
	assignment = original;

	try {
		original.setCurrentTemperature(-1000);
	} catch (const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}	

	std::cout << "Enter new ibid and current temp: ";
	std::cin >> original;
	original.printSensor();
	return 0;
}
