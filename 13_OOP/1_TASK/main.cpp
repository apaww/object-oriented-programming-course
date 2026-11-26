#include <iostream>
#include "Thermometer.hpp"
#include "ThermometerSupplier.hpp"
#include "MedicalThermometerSupplier.hpp"
#include "MedicalThermometerWithSignalSupplier.hpp"
#include "MedicalThermometerWithSignalAndDataTransferSupplier.hpp"

int main() {
	MedicalThermometerSupplier medical;
	MedicalThermometerWithSignalSupplier signal;
	MedicalThermometerWithSignalAndDataTransferSupplier data;

	ThermometerSupplier* suppliers[] = {&medical, &signal, &data};

	for (ThermometerSupplier* supplier : suppliers) {
		std::cout << std::endl << std::endl << "------------------------------" << std::endl << std::endl;
		std::cout << supplier->get_price() << std::endl;
		Thermometer* thermometer = supplier->createThermometer();
		thermometer->show_temperature();
		free(thermometer);
	}

	return 0;
}
