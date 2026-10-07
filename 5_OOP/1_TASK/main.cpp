#include <iostream>
#include "add.hpp"

int main() {
	int a, b;
	std::cin >> a >> b;

	std::cout << normal::add(a, b) << std::endl << modded::add(a, b) << std::endl;
}
