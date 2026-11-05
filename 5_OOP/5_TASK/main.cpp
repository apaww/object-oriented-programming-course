#include <iostream>
#include <random>
#include <ctime>
#include "./add/add.hpp"

int main() {
	std::srand(std::time(0));
	
	int a, b;
	std::cin >> a >> b;

	std::cout << normal::add<int, int>(a, b) << std::endl << modded::add<int,int>(a, b) << std::endl;
	
	return EXIT_SUCCESS;
}
