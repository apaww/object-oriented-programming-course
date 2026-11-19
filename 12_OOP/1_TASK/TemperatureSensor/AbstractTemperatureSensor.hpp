#pragma once

#include <iostream>

class AbstractTemperatureSensor {
private
    virtual void normalizeTemperature(double&) = 0;
    virtual void normalize() = 0;
    virtual void copyLastTemperatures(const double*, size_t, size_t) = 0;
public:
    virtual ~Sensor() = default;

    virtual void setInBatchId(const std::string&) = 0;
    virtual void setCurrentTemperature(double) = 0;
    virtual void addLastTemperature(double) = 0;

    virtual const std::string& getItemId() const = 0;
    virtual const std::string& getInBatchId() const = 0;
    virtual double getCurrentTemperature() const = 0;
    virtual size_t getSize() const = 0;
    virtual size_t getCapacity() const = 0;
    virtual const double* getLastTemperatures() const = 0;

    virtual double calcAverageLastTemperature() const = 0;
    virtual void printSensor(std::ostream& = std::cout) const = 0;
};

