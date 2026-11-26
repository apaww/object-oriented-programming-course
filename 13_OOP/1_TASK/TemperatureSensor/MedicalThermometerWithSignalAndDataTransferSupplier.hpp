/*!
 * \file MedicalThermometerWithSignalAndDataTransferSupplier.hpp 
 * \brief Contains MedicalThermometerWithSignalAndDataTransferSupplierclass
*/

#pragma once

#include "ThermometerSupplier.hpp"
#include "MedicalThermometerWithSignalAndDataTransfer.hpp"

/*!
 * \brief MedicalThermometerWithSignalAndDataTransferSupplier class
 * \author apaww
 * \version 1.0.0
 * \date 2026-11-26
 * \warning WIP 
 * \todo add more functions
*/
class MedicalThermometerWithSignalAndDataTransferSupplier : public ThermometerSupplier {
        public:
                ///! \brief Default constructor with price 1034.5 USD 
                MedicalThermometerWithSignalAndDataTransferSupplier(): ThermometerSupplier(1034.5) {}
                //! \brief Constructor with custom thermometer price
                MedicalThermometerWithSignalAndDataTransferSupplier(double price): ThermometerSupplier(price) {}

                ///! \brief Supplies link to the newly created MedicalThermometer class object
                Thermometer* createThermometer() const override {
                        return new MedicalThermometerWithSignalAndDataTransfer();
                }
};
