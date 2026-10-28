#include "TemperatureSensor.hpp"
#include <typeinfo>

template <typename T>
unsigned int TemperatureSensor<T>::fallback_id = 0;
template <typename T>
unsigned int TemperatureSensor<T>::object_count = 0;
template <typename T>
const std::string TemperatureSensor<T>::classname = std::string("TemperatureSensor_") + typeid(T).name();

template <typename T>
std::ostream& operator<<(std::ostream& os, const TemperatureSensor<T>& ts) {
	ts.printSensor();
	return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, TemperatureSensor<T>& ts) {
	is >> ts.in_batch_id >> ts.current_temperature;
	return is;
}

template class TemperatureSensor<double>;
template class TemperatureSensor<float>;
template class TemperatureSensor<int>;

template std::ostream& operator<<(std::ostream&, const TemperatureSensor<double>&);
template std::ostream& operator<<(std::ostream&, const TemperatureSensor<float>&);
template std::ostream& operator<<(std::ostream&, const TemperatureSensor<int>&);

template std::istream& operator>>(std::istream&, TemperatureSensor<double>&);
template std::istream& operator>>(std::istream&, TemperatureSensor<float>&);
template std::istream& operator>>(std::istream&, TemperatureSensor<int>&);
