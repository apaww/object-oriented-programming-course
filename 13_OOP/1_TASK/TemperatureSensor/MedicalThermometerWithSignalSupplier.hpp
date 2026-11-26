#pragma once

#include "ThermometerSupplier.hpp"
#include "MedicalThermometerWithSignal.hpp"

class MedicalThermometerWithSignalSupplier : public ThermometerSupplier {
        public:
                MedicalThermometerWithSignalSupplier(): ThermometerSupplier(499.99) {}
                MedicalThermometerWithSignalSupplier(double price): ThermometerSupplier(price) {}

                Thermometer* createThermometer() const override {
                        return new MedicalThermometerWithSignal();
                }
};
