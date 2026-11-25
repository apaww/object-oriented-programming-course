#pragma once

#include "Thermometer.hpp"

class MedicalThermometer: public Thermometer {
  protected:
    double temperature;
  public:
    void show_temperature() const override {
      std::cout << "This medical thermometer shows " << temperature << " degrees!" << std::endl;
    }

    void set_temperature(double temperature) {
      this->temperature = temperature;
    }
};
