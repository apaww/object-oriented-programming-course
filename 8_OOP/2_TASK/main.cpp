#include <iostream>
#include "TemperatureSensor.hpp"

int main() {
	double history[10] = {20.5, 21.0, 19.8, 22.3, 20.1, 21.7, 19.5, 20.9, 21.4, 20.0};

	TemperatureSensor<double> original("001", "67", 21.5, history, 10, 10);

	original.printSensor();

	TemperatureSensor<double> copied = original;

	copied.printSensor();

	TemperatureSensor<double> assignment;
	
	assignment.printSensor();

	assignment = original;

	assignment.printSensor();
	
	TemperatureSensor<double> moved = original;

	moved.printSensor();
	original.printSensor();

	TemperatureSensor<double> assignment_moved;
	
	assignment_moved.printSensor();

	assignment_moved = std::move(assignment);

	assignment_moved.printSensor();
	assignment.printSensor();

	original.setCurrentTemperature(-1000);

	return 0;
}
