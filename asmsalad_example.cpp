#include "asmsalad.h"
#include <iostream>

using namespace asmsalad;

// An example usage of the header.

int main(int argc, char const *argv[]) {

	std::cout.precision(10);

	float num;

	std::cout << "Enter a number: ";
	std::cin >> num;
	std::cout << "The inverse square root of " << num << " is: " << invsqrt_fast(num) << std::endl;

	return 0;
}

