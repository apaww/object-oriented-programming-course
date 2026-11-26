/*!
 * \file MedicalThermometerWithSignalSupplier.hpp 
 * \brief Contains MedicalThermometerWithSignalSupplier class
*/

#pragma once

#include "ThermometerSupplier.hpp"
#include "MedicalThermometerWithSignal.hpp"

/*!
 * \brief MedicalThermometerWithSignalSupplier class
 * \author apaww
 * \version 1.0.0
 * \date 2026-11-26
 * \warning WIP 
 * \todo add more functions
*/
class MedicalThermometerWithSignalSupplier : public ThermometerSupplier {
        public:
                ///! \brief Default constructor with price 499.99 USD 
                MedicalThermometerWithSignalSupplier(): ThermometerSupplier(499.99) {}
                ///! \brief Constructor with custom thermometer price
                MedicalThermometerWithSignalSupplier(double price): ThermometerSupplier(price) {}
                
                ///! \brief Supplies link to the newly created MedicalThermometerWithSignal class object 
                Thermometer* createThermometer() const override {
                        return new MedicalThermometerWithSignal();
                }
};
