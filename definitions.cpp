#include <iostream>
#include <cstdlib>
#include <vector>
#include "include/SuperInteger.h"

const int max_size = 4096;

template <typename X>
void swap(X a, X b) {
	X c = a;
	a = b;
	b = c;
}
bool SuperInteger::check(char si[]) {
	if (si[0] == '\0') {
		std::cout << "Empty string." << std::endl;
		return false;
	}
	else if (((si[0] <= '0' || si[0] > '9') && si[0] != '-') || (si[0] == '-' && si[1] <= '0' && si[1] > '9') || si[0] == '0') {
		std::cout << "Inappropriate SuperInteger, creation terminated." << std::endl;
		return false;
	}
	else {
		for (int i = 1; i < static_cast<int>(sizeof(si)) - 1; i++)
			if (si[i] <= '0' || si[i] > '9') {
				std::cout << "Wrong character found, creation of the new SuperInteger terminated." << std::endl;
				return false;
			}
	}
}
SuperInteger::SuperInteger(char si[]) {
	if (!(check(si))
		throw std::cerr << "Inappropriate number!" << std::endl;
	if (si[0] == '-') {
		digits = static_cast<int>(sizeof(si)) - 2;
		neg = true;
	}
	else
		digits = static_cast<int>(sizeof(si)) - 1;
	if (digits > max_size)
		std::cout << "Too big to input!" << std::endl;
	else {
		++c;
		Digit next;
		for (short iter = 0; si[iter] != '\0'; ++iter) {
			next.x = static_cast<unsigned short>(si[iter] - 48);
			integers.insert(next);
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
	int iter = 0, length = 0;
	long int copy = si;
	do {
		copy /= 10;
		++length;
	} while (copy != 0);
	Digit next;
	do {
		next.x = static_cast<unsigned short>((si / 10 - static_cast<long int>(si / 10)) * 10);
		si /= 10;
		integers.push_back(next);
	} while (si != 0);
}
void SuperInteger::introduce(SuperInteger& si) {
	if (si.isneg())
		std::cout << '-';
	for (int i = 1; i <= digits; i++)
		std::cout << si[i];
}
SuperInteger operator-(SuperInteger const& a) {
	SuperInteger ret;
	a.isneg() = !(a.isneg());
	return a;
}
SuperInteger operator+(SuperInteger const& a, SuperInteger const& b) {
	if (a.dig() + 1 > max_size) {
		std::cout << "Further addition impossible, the upper bound is reached." << std::endl;
		return a;
	}
	SuperInteger ret;
	Digit helper;
	if (!(a.isneg()) && !(b.isneg()) && a > b)
		if (!(a.isneg()) && !(b.isneg())) {
			for (int n = 1; n <= b.dig(); ++n) {
				helper.x = a[n] + b[n];
				ret.push_back(helper);
				if (ret[n] > 9) {
					helper.x = 1;
					ret.push_back(helper);
					ret[n] -= 10;
				}
			}
			ret.dig() = a.dig();
			if (ret[ret.dig()] > 9) {
				ret[n] -= 10;
				helper.x = 1;
				ret.push_back(helper);
				++(ret.dig());
			}
			return ret;
		}
		else if (a.isneg() && b.isneg()) {
			for (int n = 1; n <= b.dig(); ++n) {
				helper.x = a[n] + b[n];
				ret.push_back(helper);
				if (ret[n] > 9) {
					helper.x = 1;
					ret.push_back(helper);
					ret[n] -= 10;
				}
			}
			ret.dig() = a.dig();
			if (ret[ret.dig()] > 9) {
				ret[n] -= 10;
				helper.x = 1;
				ret.push_back(helper);
				++(ret.dig());
			}
			return ret;
		}
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
SuperInteger operator+=(SuperInteger const& a, SuperInteger const& b) {
	return a + b;
}
SuperInteger operator-=(SuperInteger const& a, SuperInteger const& b) {
	return a - b;
}
SuperInteger operator*=(SuperInteger const& a, SuperInteger const& b) {
	return a * b;
}
SuperInteger operator/=(SuperInteger const& a, SuperInteger const& b) {
	return a / b;
}
SuperInteger operator%=(SuperInteger const& a, SuperInteger const& b) {
	return a % b;
}
SuperInteger operator<<(SuperInteger const& a, SuperInteger const& b) {
	SuperInteger ret;
}
SuperInteger operator>>(SuperInteger const& a, SuperInteger const& b) {
	SuperInteger ret;
}
bool operator<(SuperInteger const& a, SuperInteger const& b) {
	if (a.isneg() && !(b.isneg())
		return true;
	else if (!(a.isneg()) && b.isneg())
		return false;
	else if (a.dig() > b.dig() && a.isneg() && b.isneg())
		return true;
	else if (a.dig() > b.dig() && !(a.isneg()) && !(b.isneg()))
		return false;
	else if (a.dig() < b.dig() && a.isneg() && b.isneg())
		return false;
	else if (a.dig() < b.dig() && !(a.isneg()) && !(b.isneg()))
		return true;
	else
		for (int iter = 0; iter < a.dig(); ++iter)
			if (a[iter] < b[iter])
				return true;
			else if (a[iter] > b[iter])
				return false;
			else
				continue;
	return false;
}
bool operator>(SuperInteger const& a, SuperInteger const& b) {
	if (a.isneg() && !(b.isneg())
		return false;
	else if (!(a.isneg()) && b.isneg())
		return true;
	else if (a.dig() > b.dig() && a.isneg() && b.isneg())
		return false;
	else if (a.dig() > b.dig() && !(a.isneg()) && !(b.isneg()))
		return true;
	else if (a.dig() < b.dig() && a.isneg() && b.isneg())
		return true;
	else if (a.dig() < b.dig() && !(a.isneg()) && !(b.isneg()))
		return false;
	else
		for (int iter = 0; iter < a.dig(); ++iter)
			if (a[iter] < b[iter])
				return false;
			else if (a[iter] > b[iter])
				return true;
			else
				continue;
	return false;
}
bool operator<=(SuperInteger const& a, SuperInteger const& b) {
	if (a == b || a < b)
		return true;
	else
		return false;
}
bool operator>=(SuperInteger const& a, SuperInteger const& b) {
	if (a == b || a > b)
		return true;
	else
		return false;
}
bool operator==(SuperInteger const& a, SuperInteger const& b) {
	if (a.dig() != b.dig() || a.isneg() != b.isneg())
		return false;
	else
		for (int iter = 1; iter <= a.dig() ++iter)
			if (a[iter] != b[iter])
				return false;
	return true;
}
bool operator!=(SuperInteger const& a, SuperInteger const& b) {
	if (a == b)
		return false;
	else
		return true;
}
std::ostream& operator<<(std::ostream& out, SuperInteger const& si) {
	if (si.isneg())
		out << '-';
	for (int i = 1; i <= digits; i++)
		out << si[i];
	return out;
}
