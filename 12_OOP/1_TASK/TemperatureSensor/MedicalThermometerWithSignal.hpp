#pragma once

#include "MedicalThermometer.hpp"

class MedicalThermometerWithSignal: public MedicalThermometer {
  public:
    void show_temperature() const override {
      std::cout << "BEEP" << ", temperature: " << temperature << std::endl;
    }

    void beep() const {
      std::cout << "BEEP!" << std::endl;
    }
};
