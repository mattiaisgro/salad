#include "asmsalad.h"
#include <iostream>

using namespace salad;

// An example usage of the header.

int main(int argc, char const *argv[]) {

	std::cout.precision(10);

	float num;

	std::cout << "Enter a number: ";
	std::cin >> num;
	std::cout << f2xm1(num) << std::endl;

	return 0;
}

