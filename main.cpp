#include "include/SuperInteger.h"
#include "definitions.cpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
int main(int argc, char** argv) {
	SuperInteger test = "-100000000000000000000";
	test.introduce();
	SuperInteger test2 = test + std::string("-2434230429349342323489");
	std::cout << test * test2 << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}
