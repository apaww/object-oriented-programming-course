#pragma once

#include "Thermometer.hpp"

class ThermometerSupplier {
	protected:
		 double price;
	public:
		 ThermometerSupplier(): price(99.8) {}
		 ThermometerSupplier(double price): price(price) {}
		
		 virtual ~ThermometerSupplier() = default;

		 virtual Thermometer* createThermometer() const = 0;

		 double get_price() const {
			 return price;
		 }
};

