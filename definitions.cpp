#include "include/SuperInteger.h"

const int max_size = 4096;

template <typename X>
void swap(X& a, X& b) {
	X c = a;
	a = b;
	b = c;
}
Digit::Digit(long a) {
	if (a < 0 || a > 9)
		x = 0;
	else
		x = static_cast<short>(a);
}
Digit::Digit(long double a) {
	if (a < 0 || a > 9)
		x = 0;
	else
		x = static_cast<short>(a);
}
Digit& Digit::operator=(long a) {
	if (a < 0 || a > 9)
		x = 0;
	else
		x = static_cast<short>(a);
}
Digit& Digit::operator=(long double a) {
	if (a < 0 || a > 9)
		x = 0;
	else
		x = static_cast<short>(a);
}
Digit::operator int() {
	return x;
}
void SuperInteger::delbool(SuperInteger s) {
	for (std::deque<SuperInteger>::iterator i = boolset.begin(); i != boolset.end(); ++i)
		if (s == *i)
			boolset.erase(i);
}
SuperInteger::operator bool() {
	for (std::deque<SuperInteger>::iterator i = boolset.begin(); i != boolset.end(); ++i)
		if (*this == *i)
			return false;
	return true;
}
SuperInteger::operator char() {
	if (*this > std::numeric_limits<char>::max() || *this < std::numeric_limits<char>::min())
		return 0;
}
SuperInteger::operator short() {
	if (*this > std::numeric_limits<short>::max() || *this < std::numeric_limits<short>::min())
		return 0;
}
SuperInteger::operator int() {
	if (*this > std::numeric_limits<int>::max() || *this < std::numeric_limits<int>::min())
		return 0;
}
SuperInteger::operator long() {
	if (*this > std::numeric_limits<long>::max() || *this < std::numeric_limits<long>::min())
		return 0;
}
SuperInteger::operator unsigned char() {
	if (*this > std::numeric_limits<unsigned char>::max() || *this < std::numeric_limits<unsigned char>::min())
		return 0;
}
SuperInteger::operator unsigned short() {
	if (*this > std::numeric_limits<unsigned short>::max() || *this < std::numeric_limits<unsigned short>::min())
		return 0;
}
SuperInteger::operator unsigned int() {
	if (*this > std::numeric_limits<unsigned int>::max() || *this < std::numeric_limits<unsigned int>::min())
		return 0;
}
SuperInteger::operator unsigned long() {
	if (*this > std::numeric_limits<unsigned long>::max() || *this < std::numeric_limits<unsigned long>::min())
		return 0;
}
SuperInteger::operator std::string() {
	std::string ret;
	if (!n)
		ret += '-';
	for (int i = digits; i >= 1; --i)
		ret += static_cast<char>(integers.at(i).x + 48);
	return ret;
}
SuperInteger::operator char*() {
	std::string ret;
	if (!n)
		ret += '-';
	for (int i = digits; i >= 1; --i)
		ret += static_cast<char>(integers.at(i).x + 48);
	char* ret2 = ret.c_str();
	return ret2;
}
bool check(char si[]) {
	if (si[0] == '\0')
		return false;
	else if (((si[0] <= '0' || si[0] > '9') && si[0] != '-') || (si[0] == '-' && si[1] <= '0' && si[1] > '9') || si[0] == '0')
		return false;
	else
		for (int i = 1; i < static_cast<int>(sizeof(si)) - 1; i++)
			if (si[i] <= '0' || si[i] > '9')
				return false;
	return true;
}
SuperInteger::SuperInteger() {
	++c;
	push(0);
}
SuperInteger::SuperInteger(std::string si, int a) {
	if (a > 37 || a < 1)
		push(0);
}
SuperInteger::SuperInteger(char si[]) {
	if (!(check(si))
		push(0);
	if (si[0] == '-') {
		digits = static_cast<int>(sizeof(si)) - 2;
		n = true;
	}
	else
		digits = static_cast<int>(sizeof(si)) - 1;
	if (digits > max_size)
		push(0);
	else {
		++c;
		for (short iter = 0; si[iter] != '\0'; ++iter)
			ins(static_cast<short>(si[iter] - 48));
	}
}
SuperInteger::SuperInteger(long int si) {
	++c;
	if (si < 0) {
		n = true;
		si = -si;
	}
	else
		n = false;
	do {
		push(static_cast<short>((static_cast<long double>(si) / 10 - si / 10) * 10));
		si >> 1;
		++digits;
	} while (!si);
}
SuperInteger::SuperInteger(long double sid) {
	long int si = sid;
	++c;
	if (si < 0) {
		n = true;
		si = -si;
	}
	else
		n = false;
	do {
		push(static_cast<short>((static_cast<long double>(si) / 10 - si / 10) * 10));
		si >> 1;
		++digits;
	} while (!si);
}
SuperInteger::~SuperInteger() {
	--c;
}
SuperInteger::SuperInteger(std::string& a) {
	char* si = a.c_str();
	if (!(check(si))
		push(0);
	if (si[0] == '-') {
		digits = static_cast<int>(sizeof(si)) - 2;
		neg = true;
	}
	else
		digits = static_cast<int>(sizeof(si)) - 1;
	if (digits > max_size)
		push(0);
	else {
		++c;
		for (short iter = 0; si[iter] != '\0'; ++iter)
			ins(static_cast<short>(si[iter] - 48));
	}
}
SuperInteger operator-(SuperInteger& a) {
	SuperInteger ret;
	ret = a;
	ret.neg() = !(a.neg());
	return ret;
}
SuperInteger operator^(SuperInteger const& a, SuperInteger const& b) {
	if (b < 0 || b > 256)
		return a;
	SuperInteger ret = 1;
	while (b-- > 0) {
		ret *= a;
		if (ret.digc() > max_size)
			return a;
	}
	return ret;
}
SuperInteger operator+(SuperInteger const& a, SuperInteger const& b) {
	if (a * b < 0)
		return a - b;
	if (a.digc() + 1 > max_size || b.digc() + 1 > max_size)
		return a;
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
	n = b.neg();
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
		if (a.digc() + b > max_size)
			return a;
		else {
			SuperInteger ret = a;
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
		if (a.digc() - b <= 0)
			return a;
		else {
			SuperInteger ret = a;
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
SuperInteger operator&(SuperInteger const& a, SuperInteger const& b) {
	if (a.digc() + b.digc() > max_size)
		return a;
	SuperInteger ret;
	for (short i = 1; i <= a.digc(); ++i)
		ret.push(a[i]);
	for (short i = 1; i <= b.digc(); ++i)
		ret.push(b[i]);
	if (a.neg() && b.neg() || !(a.neg() && b.neg())
		ret.neg() = false;
	else
		ret.neg() = true;
	return ret;
}
SuperInteger& SuperInteger::operator&=(SuperInteger const& b) {
	return *this = (*this) & b;
}
SuperInteger& SuperInteger::operator++() {
	*this += 1;
	if ((*this).digc() > max_size)
		return (*this) -= 1;
	else if (!(*this)) {
		(*this).neg() = false;
		return *this;
	}
}
SuperInteger& SuperInteger::operator++(int) {
	*this += 1;
	if ((*this).digc() > max_size)
		return (*this) -= 1;
	else if (!(*this)) {
		(*this).neg() = false;
		return *this;
	}
}
SuperInteger& SuperInteger::operator--() {
	*this -= 1;
	if ((*this).digc() > max_size)
		return (*this) -= 1;
	else if (*this == -1) {
		(*this).neg() = true;
		return *this;
	}
}
SuperInteger& SuperInteger::operator--(int) {
	*this -= 1;
	if ((*this).digc() > max_size)
		return (*this) -= 1;
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
std::istream& operator>>(std::istream& out, SuperInteger const& si) {
	char* ch;
	out >> ch;
	SuperInteger ret(ch);
	return ret;
}
