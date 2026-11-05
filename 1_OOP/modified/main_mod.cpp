#include <iostream>
#include "Add_mod.hpp"
#include <random>
#include <ctime>

int main() {
	std::srand(std::time(0));

	int a, b;

	std::cin >> a >> b;
	std::cout << add(a, b) << std::endl;

	return 0;
}
