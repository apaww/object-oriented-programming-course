/*!
 * \file MedicalThermometer.hpp
 * \brief Contains abstract Thermometer class
*/

#pragma once

#include "Thermometer.hpp"

/*!
 * \brief Simple medical thermometer implementation
 * \author apaww
 * \version 1.0.0
 * \date 2026-11-26
 * \warning WIP 
 * \todo add more functions
*/
class MedicalThermometer: public Thermometer {
  protected:
    double temperature = 36.6; ///< protected field contiaing temperature measurement
  public:
    /*!
     * \brief Outputs into STDOUT stream current temperature with formatting
    */
    void show_temperature() const override {
      std::cout << "This medical thermometer shows " << temperature << " degrees!" << std::endl;
    }

    /*!
     * \brief Sets temperature measurement
     * \param temperature
    */
    void set_temperature(double temperature) {
      this->temperature = temperature;
    }
};
