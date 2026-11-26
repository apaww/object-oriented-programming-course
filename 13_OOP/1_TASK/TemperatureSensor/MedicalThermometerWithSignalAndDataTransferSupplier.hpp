#pragma once

#include "ThermometerSupplier.hpp"
#include "MedicalThermometerWithSignalAndDataTransfer.hpp"

class MedicalThermometerWithSignalAndDataTransferSupplier : public ThermometerSupplier {
        public:
                MedicalThermometerWithSignalAndDataTransferSupplier(): ThermometerSupplier(1034.5) {}
                MedicalThermometerWithSignalAndDataTransferSupplier(double price): ThermometerSupplier(price) {}

                Thermometer* createThermometer() const override {
                        return new MedicalThermometerWithSignalAndDataTransfer();
                }
};
