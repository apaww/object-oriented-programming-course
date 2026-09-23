#include <iostream>
#include "Add.hpp"

int main() {
	int a, b;
	double c, d;

	std::cin >> a >> b;
	std::cout << add(a, b) << std::endl;
	std::cin >> c >> d;
	std::cout << add(c, d) << std::endl;

	return 0;
}
