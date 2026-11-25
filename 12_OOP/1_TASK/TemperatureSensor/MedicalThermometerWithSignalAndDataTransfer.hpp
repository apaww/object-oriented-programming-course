#pragma once

#include "MedicalThermometerWithSignal.hpp"

class MedicalThermometerWithSignalAndDataTransfer: public MedicalThermometerWithSignal {
  public:
    void show_temperature() const override {
      std::cout << "Recieved temperature!" << std::endl << "results: " << temperature << " degrees" << std::endl;
    }

    void transfer_temperature() const {
      std::cout << "Transferring readings..." << std::endl << "Transferred!" << std::endl;
    }
};
