#include <iomanip>
#include <iostream>
#include <limits>
#include <typeinfo>
#include <random>

#include "Add.hpp"

int main() {
	std::srand(std::time(0));

	int a, b;
	std::cin >> a >> b;
	std::cout << typeid(normal::add<int, int>(a, b)).name() << std::endl;
	std::cout << typeid(normal::add<float, int>(a, b)).name() << std::endl;
	std::cout << typeid(modded::add<int, int>(a, b)).name() << std::endl;
	std::cout << typeid(modded::add<double, int>(a, b)).name() << std::endl;

	return 0;
}
