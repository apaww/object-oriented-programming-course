#pragma once

#include <iostream>
#include <string>

class TemperatureSensor {

private:
    static unsigned int fallback_id;
    static unsigned int object_count;

    const std::string item_id;
    std::string in_batch_id;
    double current_temperature;
    double* last_temperatures;
    size_t size;
    size_t capacity;

    static const size_t DEFAULT_CAPACITY = 10;

    static std::string makeItemId(const std::string& id) {
        return id.empty() ? "DEFAULT" + std::to_string(fallback_id++) : id;
    }

    void normalizeTemperature(double& temperature) {
        if (temperature < -273.) throw std::invalid_argument("Invalid temperature provided, it should be above -273C!");
        if (temperature > 1000.) throw std::invalid_argument("Invalid temperature provided it should be below 1000C!");
    }

    void normalize() {
        if (in_batch_id.empty()) in_batch_id = std::to_string(fallback_id);
        
	normalizeTemperature(current_temperature);
        
	for (size_t i = 0; i < size; ++i) normalizeTemperature(last_temperatures[i]);
    }

    void copyLastTemperatures(const double* src, size_t src_size, size_t src_capacity) {
        capacity = src_capacity;
        size = src_size;
	last_temperatures = new double[capacity];
	for (size_t i = 0; i < size; ++i) last_temperatures[i] = src[i];
    }

public:
    static const std::string classname;

    TemperatureSensor(): item_id(makeItemId("")), in_batch_id(std::to_string(fallback_id)), current_temperature(0.), last_temperatures(new double[DEFAULT_CAPACITY]), size(DEFAULT_CAPACITY), capacity(DEFAULT_CAPACITY) {
        for (size_t i = 0; i < size; ++i) last_temperatures[i] = 0.;
        object_count++;
	std::cout << classname << " object called default constructor initialization, object count: " << object_count << std::endl;
    }

    TemperatureSensor(const std::string& item_id, const std::string& in_batch_id, double current_temperature, const double* last_temperatures, size_t last_size, size_t last_capacity): item_id(makeItemId(item_id)), in_batch_id(in_batch_id), current_temperature(current_temperature), last_temperatures(nullptr), size(0), capacity(0) {
        object_count++;
	    
	std::cout << classname << " object called initialization constructor, object count: " << object_count << std::endl;
        
	if (last_temperatures == nullptr || last_size == 0) {
            capacity = DEFAULT_CAPACITY;
            size = DEFAULT_CAPACITY;
            this->last_temperatures = new double[capacity];
            for (size_t i = 0; i < size; ++i) this->last_temperatures[i] = 0.;
        } else {
            copyLastTemperatures(last_temperatures, last_size, last_capacity);
        }

        normalize();
    }

    TemperatureSensor(const TemperatureSensor& other): item_id(other.item_id), in_batch_id(other.in_batch_id), current_temperature(other.current_temperature), last_temperatures(nullptr), size(0), capacity(0) {
        copyLastTemperatures(other.last_temperatures, other.size, other.capacity);
	object_count++;
        std::cout << classname << " object called copy construct initialization, object count: " << object_count << std::endl;
    }

    TemperatureSensor& operator=(const TemperatureSensor& other) {
        if (this != &other) {
            in_batch_id = other.in_batch_id;
            current_temperature = other.current_temperature;
            delete[] last_temperatures;
            copyLastTemperatures(other.last_temperatures, other.size, other.capacity);
        }
        
	std::cout << classname << " object called assignment operator, object count: " << object_count << std::endl;
        return *this;
    }

    ~TemperatureSensor() {
        delete[] last_temperatures;
        last_temperatures = nullptr;
	object_count--;
        
	std::cout << classname << " object called destructor, object count: " << object_count << std::endl;
    }

    void setInBatchId(const std::string& in_batch_id) {
        this->in_batch_id = in_batch_id;
        normalize();
    }

    void setCurrentTemperature(double current_temperature) {
        this->current_temperature = current_temperature;
        normalize();
    }

    void addLastTemperature(double value) {
        normalizeTemperature(value);
        
	if (size < capacity) {
            last_temperatures[size++] = value;
        } else if (capacity > 0) {
            for (size_t i = 1; i < capacity; ++i) last_temperatures[i - 1] = last_temperatures[i];
            last_temperatures[capacity - 1] = value;
        }
    }

    const std::string& getItemId() const { return item_id; }
    const std::string& getInBatchId() const { return in_batch_id; }
    double getCurrentTemperature() const { return current_temperature; }
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    const double* getLastTemperatures() const { return last_temperatures; }

    double calcAverageLastTemperature() const {
        if (size == 0) return 0.;
       
	double sum = 0.;
        for (size_t i = 0; i < size; ++i) sum += last_temperatures[i];
        return sum / (size * 1.0);
    }

    static void print_count() {
	    std::cout << classname << " objects count equals " << object_count << std::endl;
    }

    void printSensor(std::ostream& os = std::cout) const {
	    os << "id = " << item_id << ", inBatchId = " << in_batch_id << ", current temperature = " << current_temperature << std::endl << "Last " << size << " temperatures:" << std::endl;
	    for (int i = 0; i < size; ++i) {
		    os << "i | " << last_temperatures[i] << std::endl;
	    }
    }

    bool operator<(const TemperatureSensor& other) const {
	    return item_id < other.item_id;
    }

    friend std::ostream& operator<<(std::ostream& os, const TemperatureSensor& ts);
};

std::ostream& operator<<(std::ostream& os, const TemperatureSensor& ts);
