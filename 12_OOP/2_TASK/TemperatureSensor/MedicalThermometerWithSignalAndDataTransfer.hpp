/*!
 * \file MedicalThermometerWithSignalAndDataTransfer.hpp
 * \brief Contains abstract Thermometer class
*/

#pragma once

#include "MedicalThermometerWithSignal.hpp"

/*!
 * \brief Medical thermometer with signal and data transfer implementation
 * \author apaww
 * \version 1.0.0
 * \date 2026-11-26
 * \warning WIP 
 * \todo add more functions
*/
class MedicalThermometerWithSignalAndDataTransfer: public MedicalThermometerWithSignal {
  public:
    /*!
     * \brief Outputs into STDOUT stream current temperature with formatting
    */
    void show_temperature() const override {
      std::cout << "Recieved temperature!" << std::endl << "results: " << temperature << " degrees" << std::endl;
    }

    /*!
     * \brief Transfers temperature measurement
    */
    void transfer_temperature() const {
      std::cout << "Transferring readings..." << std::endl << "Transferred!" << std::endl;
    }
};
