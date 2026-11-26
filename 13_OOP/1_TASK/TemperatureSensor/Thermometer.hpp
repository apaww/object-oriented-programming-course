/*!
 * \file Thermometer.hpp 
 * \brief Contains abstract Thermometer class
*/

#pragma once

#include <iostream>

/*!
 * \brief Abstract Thermometer class
 * \author apaww
 * \version 1.0.0
 * \date 2026-11-26
 * \warning WIP 
 * \todo add more functions
*/
class Thermometer {
  public:
    virtual void show_temperature() const = 0; ///< virtual prototype for show_temperature function
};
