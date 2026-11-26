/*!
 * \file MedicalThermometerSupplier.hpp 
 * \brief Contains MedicalThermometerSupplier class
*/

#pragma once

#include "ThermometerSupplier.hpp"
#include "MedicalThermometer.hpp"

/*!
 * \brief MedicalThermometerSupplier class
 * \author apaww
 * \version 1.0.0
 * \date 2026-11-26
 * \warning WIP 
 * \todo add more functions
*/
class MedicalThermometerSupplier : public ThermometerSupplier {
        public:
    ///! \brief Default constructor with price 34.5 USD 
		MedicalThermometerSupplier(): ThermometerSupplier(34.5) {}
                ///! \brief Constructor with custom thermometer price
                MedicalThermometerSupplier(double price): ThermometerSupplier(price) {}
                
                ///! \brief Supplies link to the newly created MedicalThermometer class object 
                Thermometer* createThermometer() const override {
                        return new MedicalThermometer();
                }
};
