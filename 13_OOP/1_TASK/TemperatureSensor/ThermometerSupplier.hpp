/*!
 * \file ThermometerSupplier.hpp 
 * \brief Contains abstract ThermometerSupplier class
*/

#pragma once

#include "Thermometer.hpp"

/*!
 * \brief Abstract ThermometerSupplier class
 * \author apaww
 * \version 1.0.0
 * \date 2026-11-26
 * \warning WIP 
 * \todo add more functions
*/
class ThermometerSupplier {
	protected:
		 double price; ///< contains thermometer's price in USD
	public:
     ///! \brief Default constructor
		 ThermometerSupplier(): price(99.8) {}
     ///! \brief Constructor with setting price
		 ThermometerSupplier(double price): price(price) {}
		
     ///! \brief Default destructor
		 virtual ~ThermometerSupplier() = default;

     ///! \brief Virtual createThermometer function interface
		 virtual Thermometer* createThermometer() const = 0;

     ///! \brief Returns price of thermometer
		 double get_price() const {
			 return price;
		 }
};

