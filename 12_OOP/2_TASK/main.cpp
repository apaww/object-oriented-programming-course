#include <iostream>
#include "Thermometer.hpp"
#include "MedicalThermometer.hpp"
#include "MedicalThermometerWithSignal.hpp"
#include "MedicalThermometerWithSignalAndDataTransfer.hpp"

int main() {
  MedicalThermometer medical;
  MedicalThermometerWithSignal signal;
  MedicalThermometerWithSignalAndDataTransfer data;

  medical.set_temperature(36.6);
  signal.set_temperature(37.5);
  data.set_temperature(38.1);

  Thermometer *thermometers[] = {&medical, &signal, &data};

  for (Thermometer *thermometer : thermometers) {
    thermometer->show_temperature();
  }

  MedicalThermometer medicals[] = {medical, signal, data};

  for (MedicalThermometer medcialT : medicals) {
    medcialT.show_temperature();
  }

  signal.beep();
  data.beep();
  data.transfer_temperature();

	return 0;
}
