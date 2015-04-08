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
		std::cerr << "Empty string." << std::endl;
		return false;
	}
	else if (((si[0] <= '0' || si[0] > '9') && si[0] != '-') || (si[0] == '-' && si[1] <= '0' && si[1] > '9') || si[0] == '0') {
		std::cerr << "Inappropriate SuperInteger, creation terminated." << std::endl;
		return false;
	}
	else {
		for (int i = 1; i < static_cast<int>(sizeof(si)) - 1; i++)
			if (si[i] <= '0' || si[i] > '9') {
				std::cerr << "Wrong character found, creation of the new SuperInteger terminated." << std::endl;
				return false;
			}
	}
}
SuperInteger::SuperInteger() {
	++c;
	Digit helper;
	helper.x = 0;
	push(helper);
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
		std::cerr << "Too big to input!" << std::endl;
	else {
		++c;
		Digit next;
		for (short iter = 0; si[iter] != '\0'; ++iter) {
			next.x = static_cast<unsigned short>(si[iter] - 48);
			ins(next);
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
	long int copy = si;
	Digit next;
	do {
		next.x = static_cast<unsigned short>((si / 10 - static_cast<long int>(si / 10)) * 10);
		copy /= 10;
		push(next);
		++digits;
	} while (si != 0);
}
SuperInteger::SuperInteger(long double sid) {
	long int si = sid;
	++c;
	if (si < 0) {
		neg = true;
		si = -si;
	}
	else
		neg = false;
	long int copy = si;
	Digit next;
	do {
		next.x = static_cast<unsigned short>((si / 10 - static_cast<long int>(si / 10)) * 10);
		copy /= 10;
		push(next);
		++digits;
	} while (si != 0);
}
SuperInteger::~SuperInteger() {
	--c;
}
void SuperInteger::introduce(SuperInteger& si) {
	if (si.isneg())
		std::cout << '-';
	for (int i = 1; i <= digits; i++)
		std::cout << si[i];
}
SuperInteger operator-(SuperInteger& a) {
	SuperInteger ret;
	ret = a;
	ret.isneg() = !(a.isneg());
	return ret;
}
SuperInteger operator+(SuperInteger const& a, SuperInteger const& b) {
	if (a.dig() + 1 > max_size || b.dig() + 1 > max_size) {
		std::cerr << "Further addition impossible, the upper bound is reached." << std::endl;
		return a;
	}
	SuperInteger ret;
	Digit helper;
	short add = 0;
	if (!(a.isneg()) && !(b.isneg()))
		if (a >= b) {
			for (short n = 1; n <= b.dig(); ++n) {
				helper.x = a[n] + b[n] + add;
				ret.push(helper);
				add = 0;
				if (ret[n] > 9) {
					add = 1;
					ret[n] -= 10;
				}
			}
			ret.dig();
			if (a[a.dig()] + add > 9) {
				helper.x = 1 + a[a.dig()] - 10;
				ret.push(helper);
				helper.x = 1;
				ret.push(helper);
				++(ret.dig());
			}
			return ret;
		}
		else if (a.isneg() && b.isneg()) {
			for (short n = 1; n <= a.dig(); ++n) {
				helper.x = a[n] + b[n] + add;
				ret.push(helper);
				add = 0;
				if (ret[n] > 9) {
					add = 1;
					ret[n] -= 10;
				}
			}
			ret.dig() = b.dig();
			if (b[b.dig()] + add > 9) {
				helper.x = 1 + b[b.dig()] - 10;
				ret.push(helper);
				helper.x = 1;
				ret.push(helper);
				++(ret.dig());
			}
			ret.isneg() = true;
			return ret;
		}
		else
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
SuperInteger& SuperInteger::operator=(SuperInteger const& b) {
	if (this == &rhs)
		return *this;
	integers = b.returnDeque;
	neg = b.isneg();
	digits = b.dig();
}
SuperInteger& SuperInteger::operator+=(SuperInteger const& b) {
	return *this = (*this) + b;
}
SuperInteger& SuperInteger::operator-=(SuperInteger const& b) {
	return *this = (*this) - b;
}
SuperInteger& SuperInteger::operator*=(SuperInteger const& b) {
	return *this = (*this) * b;
}
SuperInteger& SuperInteger::operator/=(SuperInteger const& b) {
	return *this = (*this) / b;
}
SuperInteger& SuperInteger::operator%=(SuperInteger const& b) {
	return *this = (*this) % b;
}
SuperInteger operator<<(SuperInteger const& a, SuperInteger const& b) {
	if (b < 0)
		return a >> -b;
	else {
		if (a.dig() + b > max_size) {
			std::cerr << "Can't go past the bound." << std::endl;
			return a;
		}
		else {
			SuperInteger ret;
			ret = a;
			Digit helper;
			helper.x = 0;
			for (; b != 0; --b)
				ret.push(helper);
		}
		return ret;
	}
}
SuperInteger operator>>(SuperInteger const& a, SuperInteger const& b) {
	if (b < 0)
		return a << -b;
	else {
		if (a.dig() - b <= 0) {
			std::cerr << "There aren't as many digits as in the left SuperInteger." << std::endl;
			return a;
		}
		else {
			SuperInteger ret;
			ret = a;
			for (; b != 0; --b)
				ret.pop();
		}
		return ret;
	}
}
SuperInteger& SuperInteger::operator<<=(SuperInteger const& b) {
	return *this = (*this) << b;
}
SuperInteger& SuperInteger::operator>>=(SuperInteger const& b) {
	return *this = (*this) >> b;
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
	return false;
}
bool operator>=(SuperInteger const& a, SuperInteger const& b) {
	if (a == b || a > b)
		return true;
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
	if (a.dig() != b.dig() || a.isneg() != b.isneg())
		return true;
	else
		for (int iter = 1; iter <= a.dig() ++iter)
			if (a[iter] == b[iter])
				return false;
	return true;
}
SuperInteger& SuperInteger::operator++() {
	*this += 1;
	if ((*this).dig() > max_size) {
		std::cerr << "Can't increment more." << std::endl;
		return (*this) -= 1;
	}
	else if (!(*this)) {
		(*this).isneg() = false;
		return *this;
	}
}
SuperInteger& SuperInteger::operator++(int) {
	*this += 1;
	if ((*this).dig() > max_size) {
		std::cerr << "Can't increment more." << std::endl;
		return (*this) -= 1;
	}
	else if (!(*this)) {
		(*this).isneg() = false;
		return *this;
	}
}
SuperInteger& SuperInteger::operator--() {
	*this -= 1;
	if ((*this).dig() > max_size) {
		std::cerr << "Can't increment more." << std::endl;
		return (*this) += 1;
	}
	else if (*this == -1) {
		(*this).isneg() = true;
		return *this;
	}
}
SuperInteger& SuperInteger::operator--(int) {
	*this -= 1;
	if ((*this).dig() > max_size) {
		std::cerr << "Can't increment more." << std::endl;
		return (*this) += 1;
	}
	else if (*this == -1) {
		(*this).isneg() = true;
		return *this;
	}
}
bool operator!(SuperInteger const& a) {
	if (a == 0)
		return true;
	return false;
}
std::ostream& operator<<(std::ostream& out, SuperInteger const& si) {
	if (si.isneg())
		out << '-';
	for (int i = 1; i <= digits; i++)
		out << si[i];
	return out;
}
SuperInteger operator^(SuperInteger const& a, SuperInteger const b) {
	if (b < 0) {
		std::cerr << "Can power only to natural exponents." << std::endl;
		return a;
	}
	SuperInteger ret = 1;
	while (b > 0) {
		ret *= a;
		--b;
		if (ret.dig() > max_size) {
			std::cerr << "Went past the bound, returning the original value." << std::endl;
			return a;
		}
	}
	return ret;
}
