#include "include/SuperInteger.h"

const int max_size = 4096;

template <typename X>
void swap(X a, X b) {
	X c = a;
	a = b;
	b = c;
}
Digit::Digit(short a) {
	x = a;
}
Digit& Digit::operator=(short a) {
	this->x = a;
	return *this;
}
SuperInteger::operator char() {

}
SuperInteger::operator short() {
	
}
SuperInteger::operator int() {
}
SuperInteger::operator long() {
}
SuperInteger::operator unsigned char() {
}
SuperInteger::operator unsigned short() {
}
SuperInteger::operator unsigned int() {
}
SuperInteger::operator unsigned long() {
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
	push(0);
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
			next = static_cast<short>(si[iter] - 48);
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
		next = static_cast<short>((si / 10 - static_cast<long int>(si / 10)) * 10);
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
		next = static_cast<short>((si / 10 - static_cast<long int>(si / 10)) * 10);
		copy /= 10;
		push(next);
		++digits;
	} while (si != 0);
}
SuperInteger::~SuperInteger() {
	--c;
}
SuperInteger::SuperInteger(std::string& a) {
	char* si = a.c_str();
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
			next = static_cast<short>(si[iter] - 48);
			ins(next);
		}
	}
}
void SuperInteger::introduce(SuperInteger& si) const {
	if (si.neg())
		std::cout << '-';
	for (int i = 1; i <= digits; i++)
		std::cout << si[i];
}
SuperInteger operator-(SuperInteger& a) {
	SuperInteger ret;
	ret = a;
	ret.neg() = !(a.neg());
	return ret;
}
SuperInteger operator^(SuperInteger const& a, SuperInteger const b) {
	if (b < 0) {
		std::cerr << "Can power only to natural exponents." << std::endl;
		return a;
	}
	if (b > 256) {
		std::cerr << "Can't power to more than 256." << std::endl;
		return a;
	}
	SuperInteger ret = 1;
	while (b > 0) {
		ret *= a;
		--b;
		if (ret.digc() > max_size) {
			std::cerr << "Went past the bound, returning the original value." << std::endl;
			return a;
		}
	}
	return ret;
}
SuperInteger operator+(SuperInteger const& a, SuperInteger const& b) {
	if (a.digc() + 1 > max_size || b.digc() + 1 > max_size) {
		std::cerr << "Further addition impossible, the upper bound is reached." << std::endl;
		return a;
	}
	SuperInteger ret;
	Digit helper;
	short add = 0;
	if (!(a.neg()) && !(b.neg()))
		if (a >= b) {
			for (short n = 1; n <= b.digc(); ++n) {
				helper = a[n] + b[n] + add;
				ret.push(helper);
				add = 0;
				if (ret[n] > 9) {
					add = 1;
					ret[n] -= 10;
				}
			}
			ret.digc();
			if (a[a.digc()] + add > 9) {
				helper.x = 1 + a[a.digc()] - 10;
				ret.push(helper);
				helper.x = 1;
				ret.push(helper);
				++(ret.digc());
			}
			return ret;
		}
		else if (a.neg() && b.neg()) {
			for (short n = 1; n <= a.digc(); ++n) {
				helper.x = a[n] + b[n] + add;
				ret.push(helper);
				add = 0;
				if (ret[n] > 9) {
					add = 1;
					ret[n] -= 10;
				}
			}
			ret.digc() = b.digc();
			if (b[b.digc()] + add > 9) {
				helper.x = 1 + b[b.digc()] - 10;
				ret.push(helper);
				helper.x = 1;
				ret.push(helper);
				++(ret.digc());
			}
			ret.neg() = true;
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
	if (this == &b)
		return *this;
	integers = b.returnDeque;
	neg = b.neg();
	digits = b.digc();
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
		if (a.digc() + b > max_size) {
			std::cerr << "Can't go past the bound." << std::endl;
			return a;
		}
		else {
			SuperInteger ret;
			ret = a;
			Digit helper;
			helper = 0;
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
		if (a.digc() - b <= 0) {
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
SuperInteger& SuperInteger::operator^=(SuperInteger const& b) {
	return *this = (*this) ^ b;
}
bool operator<(SuperInteger const& a, SuperInteger const& b) {
	if (a.neg() && !(b.neg())
		return true;
	else if (!(a.neg()) && b.neg())
		return false;
	else if (a.digc() > b.digc() && a.neg() && b.neg())
		return true;
	else if (a.digc() > b.digc() && !(a.neg()) && !(b.neg()))
		return false;
	else if (a.digc() < b.digc() && a.neg() && b.neg())
		return false;
	else if (a.digc() < b.digc() && !(a.neg()) && !(b.neg()))
		return true;
	else
		for (int iter = 0; iter < a.digc(); ++iter)
			if (a[iter] < b[iter])
				return true;
			else if (a[iter] > b[iter])
				return false;
			else
				continue;
	return false;
}
bool operator>(SuperInteger const& a, SuperInteger const& b) {
	if (a.neg() && !(b.neg())
		return false;
	else if (!(a.neg()) && b.neg())
		return true;
	else if (a.digc() > b.digc() && a.neg() && b.neg())
		return false;
	else if (a.digc() > b.digc() && !(a.neg()) && !(b.neg()))
		return true;
	else if (a.digc() < b.digc() && a.neg() && b.neg())
		return true;
	else if (a.digc() < b.digc() && !(a.neg()) && !(b.neg()))
		return false;
	else
		for (int iter = 0; iter < a.digc(); ++iter)
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
	if (a.digc() != b.digc() || a.neg() != b.neg())
		return false;
	else
		for (int iter = 1; iter <= a.digc() ++iter)
			if (a[iter] != b[iter])
				return false;
	return true;
}
bool operator!=(SuperInteger const& a, SuperInteger const& b) {
	if (a.digc() != b.digc() || a.neg() != b.neg())
		return true;
	else
		for (int iter = 1; iter <= a.digc() ++iter)
			if (a[iter] == b[iter])
				return false;
	return true;
}
SuperInteger& SuperInteger::operator++() {
	*this += 1;
	if ((*this).digc() > max_size) {
		std::cerr << "Can't increment more." << std::endl;
		return (*this) -= 1;
	}
	else if (!(*this)) {
		(*this).neg() = false;
		return *this;
	}
}
SuperInteger& SuperInteger::operator++(int) {
	*this += 1;
	if ((*this).digc() > max_size) {
		std::cerr << "Can't increment more." << std::endl;
		return (*this) -= 1;
	}
	else if (!(*this)) {
		(*this).neg() = false;
		return *this;
	}
}
SuperInteger& SuperInteger::operator--() {
	*this -= 1;
	if ((*this).digc() > max_size) {
		std::cerr << "Can't increment more." << std::endl;
		return (*this) += 1;
	}
	else if (*this == -1) {
		(*this).neg() = true;
		return *this;
	}
}
SuperInteger& SuperInteger::operator--(int) {
	*this -= 1;
	if ((*this).digc() > max_size) {
		std::cerr << "Can't increment more." << std::endl;
		return (*this) += 1;
	}
	else if (*this == -1) {
		(*this).neg() = true;
		return *this;
	}
}
bool operator!(SuperInteger const& a) {
	if (a == 0)
		return true;
	return false;
}
std::ostream& operator<<(std::ostream& out, SuperInteger const& si) {
	if (si.neg())
		out << '-';
	for (int i = 1; i <= digits; i++)
		out << si[i];
	return out;
}
