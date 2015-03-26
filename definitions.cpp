#include <iostream>
#include <cstdlib>
#include "include/SuperInteger.h"

SuperInteger::SuperInteger(char si[]) {
	if (si[0] == '-') {
		digits = static_cast<int>(sizeof(si)) - 2;
		neg = true;
	}
	else
		digits = static_cast<int>(sizeof(si)) - 1;
	if (digits > 4095)
		std::cout << "Too big to input!" << std::endl;
	else {
		++c;
		integers = new Digit[digits];
		for (; iterator < digits; iterator++) {
			integer[iterator]->x = static_cast<unsigned short>(si[iterator] - 48);
		}
	}
}
SuperInteger::SuperInteger(long int si) {
	++c;
	if (si < 0) {
		neg = true;
		si = -si;
	}
	else
		neg = false;
	do {
		integers[iterator++]->x = static_cast<unsigned short>((si / 10 - static_cast<long int>(si / 10)) * 10);
		si = static_cast<long int>(si / 10);
	} while (si != 0);
}
void SuperInteger::introduce(SuperInteger& si) {
	if (!(si.isneg()))
		std::cout << '-';
	for (int i = 0; i < digits; i++)
		std::cout << si.(integers[i]->x);
}
SuperInteger operator-(SuperInteger const& a) {
	a.isneg() = !(a.isneg());
	return a;
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
std::ostream& operator<<(std::ostream& out, SuperInteger const& si) {
	if (!(si.isneg()))
		out << '-';
	for (int i = 0; i < digits; i++)
		out << si.(integers[i]->x);
	return out;
}
