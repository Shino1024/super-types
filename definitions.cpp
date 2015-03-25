#include <iostream>
#include <cstdlib>
#include "include/SuperInteger.h"

SuperInteger::SuperInteger(char si[]) {
	++c;
	if (static_cast<int>(sizeof(si)) > 4095)
		std::cout << "Too big to fit!" << std::endl;
	else {
		for (int i = 4096 - static_cast<int>(sizeof(si)) - 1, int j = 0; i < 4096; ++i, ++j) {
			integer[i].x = static_cast<unsigned short>(si[j] - 48);
		}
		digits = static_cast<int>(sizeof(si) - 1);	
	}
}
SuperInteger::SuperInteger(long double si) {
	if (si < 0) {
		neg = true;
		si = -si;
	}
	else
		neg = false;
	do {
		++digits;
		integers[--iterator].x = static_cast<unsigned short>((si / 10 - static_cast<long int>(si / 10)) * 10);
		si = static_cast<long int>(si / 10);
	} while (si != 0);
	if (neg)
		integers[--iterator].x = 10;
}
void SuperInteger::introduce(SuperInteger& si) {
	for (int i = 
}
SuperInteger operator+(SuperInteger const& a, SuperInteger const& b) {
	SuperInteger ret;
}
SuperInteger operator-(SuperInteger const& a, SuperInteger const& b) {
	SuperInteger ret;
}
SuperInteger operator*(SuperInteger const& a, SuperInteger const& b) {
	SuperInteger ret;
}
SuperInteger operator/(SuperInteger const& a, SuperInteger const& b) {
	SuperInteger ret;
}
SuperInteger operator%(SuperInteger const& a, SuperInteger const& b) {
	SuperInteger ret;
}
