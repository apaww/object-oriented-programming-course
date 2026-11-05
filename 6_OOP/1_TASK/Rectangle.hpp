#pragma once
#include <iostream>

class Rectangle {

private:
	double side_a;
	double side_b;
public:
	int *values;
	size_t values_size;

private:	
	void normalize() {
		if (side_a < 0.) side_a = 0.;
		if (side_b < 0.) side_b = 0.;
		if (side_a > 1e6) side_a = 1e6;
		if (side_b > 1e6) side_b = 1e6;
	}

	void copyValues(const int* src, int size) {
		values_size = size;
		values = new int[values_size];
		
		for (int i = 0; i < values_size; ++i) {
			values[i] = src[i];
		}
	}

public:
	Rectangle(): side_a(0.), side_b(0.), values(new int[6]), values_size(6) {
		std::cout << "default constructor" << std::endl;
	}

	Rectangle(double side_a, double side_b): side_a(side_a), side_b(side_b), values(nullptr), values_size(0) {
		std::cout << "initialization constructor" << std::endl;
		normalize();
	}

	//Rectangle(int side_a, int side_b) {
	//	this->side_a = side_a;
	//	this->side_b = side_b;
	//	this->values = nullptr;
	//	this->values_size = 0;
	//	
	//	std::cout << "initialization constructor" << std::endl;
	//	normalize();
	//}
	
	Rectangle(const Rectangle& other) {
		this->side_a = other.side_a;
		this->side_b = other.side_b;
		copyValues(other.values, other.values_size);

		std::cout << "copy construct" << std::endl;
	}

	//Rectangle(const Rectangle& other) Rectangle(other.side_a, other.side_b) {
	//	copyValues(other.values, other.values_size);
	//	std::cout << "copy construct" << std::endl;
	//}
	
	Rectangle& operator= (const Rectangle& other) {
		if (this != &other) {
			this->side_a = other.side_a;
			this->side_b = other.side_b;

			delete[] values;
			copyValues(other.values, other.values_size);
		}

		std::cout << "assignment operator" << std::endl;
		return *this;
	}

	~Rectangle() {
		delete[] values;
		values = nullptr;

		std::cout << "destructor" << std::endl;
	}

	void setSideA(int side_a) { this->side_a = side_a; normalize(); }
	void setSideB(int side_b) { this->side_b = side_b; normalize(); }

	double getSideA() { return this->side_a; }
	double getSideB() { return this->side_b; }

	double calcArea() { return this->side_a * this->side_b; }
};
