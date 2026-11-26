#pragma once

#include "ThermometerSupplier.hpp"
#include "MedicalThermometer.hpp"

class MedicalThermometerSupplier : public ThermometerSupplier {
        public:
		MedicalThermometerSupplier(): ThermometerSupplier(34.5) {}
                MedicalThermometerSupplier(double price): ThermometerSupplier(price) {}

                Thermometer* createThermometer() const override {
                        return new MedicalThermometer();
                }
};
