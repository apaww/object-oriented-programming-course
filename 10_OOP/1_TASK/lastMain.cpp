#include <iostream>
#include "MedicalTemperatureSensor.hpp"
#include "BluetoothMedicalTemperatureSensor.hpp"

int main(){
	MedicalTemperatureSensor test;
	test.setCurrentTemperature(32.);
	test.printSensor();
	
	test.beep();
	
	BluetoothMedicalTemperatureSensor bluetest;
	bluetest.Send_T();
	bluetest.beep();

	return 0;
}
