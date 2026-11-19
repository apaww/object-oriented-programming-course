#include <iostream>
#include "TemperatureSensor.hpp"

int main(){
    std::cout << "static values: " << std::endl; 
    TemperatureSensor::print_count();
    std::cout << "classname - " << TemperatureSensor::classname << std::endl << std::endl;


    std::cout << "TemperatureSensor creation: " << std::endl;
    TemperatureSensor my_first_sensor ("id123", "ibid123", 12.34, nullptr, 0, 0);
    my_first_sensor.printSensor();
    my_first_sensor.print_count();     std::cout << my_first_sensor << std::endl;
   
    std::cout << "Second sensor: " << std::endl;
    TemperatureSensor my_second_sensor {my_first_sensor};
    std::cout << my_second_sensor << std::endl;
    my_second_sensor.addLastTemperature(2.22);
    my_first_sensor.addLastTemperature(1.11);
    my_second_sensor.printSensor();


    {
        std::cout << " inside {} " << std::endl;
        TemperatureSensor my_second_sensor {my_first_sensor};
        std::cout << my_second_sensor << std::endl;
        my_second_sensor.addLastTemperature(3.0);
        my_first_sensor.addLastTemperature(4.0);
        my_second_sensor.printSensor();
    }


    std::cout << " outside {} " << std::endl;
    my_second_sensor.printSensor();


    return 0;
}

