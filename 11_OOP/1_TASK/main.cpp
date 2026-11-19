#include <iostream>
#include "BluetoothMedicalTemperatureSensorWithSignal.hpp"

int main() {
	BluetoothMedicalTemperatureSensorWithSignal sensor = BluetoothMedicalTemperatureSensorWithSignal("id", "ibid", 123., nullptr, 0, 0, 33., 42., 37.8, "wifi");
	sensor.beep();
	sensor.Send_T();
	return 0;
}
