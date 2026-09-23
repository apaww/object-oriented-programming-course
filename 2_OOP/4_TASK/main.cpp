#include <iostream>
#include "Add.hpp"

int main() {
	int a, b;
	double c, d;

	std::cin >> a >> b;
	std::cout << normal::add<int>(a, b) << std::endl;
	std::cin >> c >> d;
	std::cout << normal::add<double>(c, d) << std::endl;

	std::cin >> a >> b;
	std::cout << random::add<int>(a, b) << std::endl;
	std::cin >> c >> d;
	std::cout << random::add<double>(c, d) << std::endl;

	return 0;
}
