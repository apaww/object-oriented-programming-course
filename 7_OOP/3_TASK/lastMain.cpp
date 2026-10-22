#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "TemperatureSensor.hpp"

int main(){
    std::cout << "vector: " << std::endl;
    std::vector<TemperatureSensor> vec;
    vec.push_back(TemperatureSensor("id1", "b1", 1.1, nullptr, 0, 0));
    vec.push_back(TemperatureSensor("id2", "b2", 2.2, nullptr, 0, 0));
    vec.push_back(TemperatureSensor("id3", "b3", 3.3, nullptr, 0, 0));
    vec.push_back(TemperatureSensor("id4", "b4", 4.4, nullptr, 0, 0));
    std::cout << "vector size = " << vec.size() << std::endl;
    vec.clear();
    std::cout << std::endl;

    std::cout << "list: " << std::endl;
    std::list<TemperatureSensor> lst;
    lst.push_back(TemperatureSensor("id5", "b5", 5.5, nullptr, 0, 0));
    lst.push_back(TemperatureSensor("id6", "b6", 6.6, nullptr, 0, 0));
    lst.push_back(TemperatureSensor("id7", "b7", 7.7, nullptr, 0, 0));
    lst.push_back(TemperatureSensor("id8", "b8", 8.8, nullptr, 0, 0));
    std::cout << "list size = " << lst.size() << std::endl;
    lst.clear();
    std::cout << std::endl;

    std::cout << "set: " << std::endl;
    std::set<TemperatureSensor> st;
    st.insert(TemperatureSensor("id9",  "b9",  9.9,  nullptr, 0, 0));
    st.insert(TemperatureSensor("id10", "b10", 10.1, nullptr, 0, 0));
    st.insert(TemperatureSensor("id11", "b11", 11.1, nullptr, 0, 0));
    st.insert(TemperatureSensor("id12", "b12", 12.1, nullptr, 0, 0));
    std::cout << "set size = " << st.size() << std::endl;
    st.clear();
    std::cout << std::endl;

    return 0;
}
