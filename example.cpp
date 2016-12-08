#include "asmsalad.h"
#include <iostream>

using namespace asmsalad;

// An example usage of the functions.

int main(int argc, char const *argv[]) {

	std::cout.precision(10);

	float num;

	std::cin >> num;
	std::cout << "The square root of 2 is " << invsqrt_fast(num) << std::endl;

	return 0;
}

