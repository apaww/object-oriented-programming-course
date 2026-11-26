/*!
 * \file MedicalThermometerWithSignal.hpp
 * \brief Contains MedicalThermometer child class with added signaling functionality 
*/

#pragma once

#include "MedicalThermometer.hpp"

/*!
 * \brief Medical thermometer with signal realisation
 * \author apaww
 * \version 1.0.0
 * \date 2026-11-26
 * \warning WIP 
 * \todo add more functions
*/
class MedicalThermometerWithSignal: public MedicalThermometer {
  public:
    /*!
     * \brief Outputs into STDOUT stream current temperature with formatting
    */
    void show_temperature() const override {
      std::cout << "BEEP" << ", temperature: " << temperature << std::endl;
    }
    
    /*!
     * \brief Outputs into STDOUT stream beep signal
    */
    void beep() const {
      std::cout << "BEEP!" << std::endl;
    }
};
