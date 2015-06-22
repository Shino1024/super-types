#include "include/SuperInteger.h"

// The maximal size of a SuperInteger in digits.
const int max_size = 4096;

// The constructor of the Digit class (long).
Digit::Digit(long a) {
	if (a < 0 || a > 9)
		x = 0;
	else
		x = static_cast<short>(a);
}

// The constructor of the Digit class (long double).
Digit::Digit(long double a) {
	if (a < 0 || a > 9)
		x = 0;
	else
		x = static_cast<short>(a);
}

// The assignment operator overload (long).
Digit& Digit::operator=(long a) {
	if (a < 0 || a > 9)
		x = 0;
	else
		x = static_cast<short>(a);
}

// The assignment operator overload (long double).
Digit& Digit::operator=(long double a) {
	if (a < 0 || a > 9)
		x = 0;
	else
		x = static_cast<short>(a);
}

// Digit to int conversion.
Digit::operator int() {
	return x;
}

// Addition operator overload.
Digit operator+(Digit const& a, Digit const& b) {
	Digit ret = a.x + b.x;
	return ret;
}

// Assignment-addition operator overload.
Digit& Digit::operator+=(Digit const& a) {
	return *this = (*this) + a;
}

// The function that deletes the "false" SuperInteger for the deque.
void SuperInteger::delbool(SuperInteger s) {
	for (std::deque<SuperInteger>::iterator i = boolset.begin(); i != boolset.end(); ++i)
		if (s == *i)
			boolset.erase(i);
}

// SuperInteger to bool conversion.
SuperInteger::operator bool() {
	for (std::deque<SuperInteger>::iterator i = boolset.begin(); i != boolset.end(); ++i)
		if (*this == *i)
			return false;
	return true;
}

// SuperInteger to char conversion.
SuperInteger::operator char() {
	if (*this > std::numeric_limits<char>::max() || *this < std::numeric_limits<char>::min())
		return 0;
	else {
		char ret = 0, temp;
		for (std::deque<Digit>::iterator it = integers.begin(), short contr = 0; it != integers.end(); ++it, ++contr) {
			temp = (*it).x;
			for (short it2 = 0; it2 < contr; ++it2)
				temp *= 10;
			ret += temp;
		}
		return ret;
	}
}

// SuperInteger to short conversion.
SuperInteger::operator short() {
	if (*this > std::numeric_limits<short>::max() || *this < std::numeric_limits<short>::min())
		return 0;
	else {
		short ret = 0, temp;
		for (std::deque<Digit>::iterator it = integers.begin(), short contr = 0; it != integers.end(); ++it, ++contr) {
			temp = (*it).x;
			for (short it2 = 0; it2 < contr; ++it2)
				temp *= 10;
			ret += temp;
		}
		return ret;
	}
}

// SuperInteger to int conversion.
SuperInteger::operator int() {
	if (*this > std::numeric_limits<int>::max() || *this < std::numeric_limits<int>::min())
		return 0;
	else {
		int ret = 0, temp;
		for (std::deque<Digit>::iterator it = integers.begin(), short contr = 0; it != integers.end(); ++it, ++contr) {
			temp = (*it).x;
			for (short it2 = 0; it2 < contr; ++it2)
				temp *= 10;
			ret += temp;
		}
		return ret;
	}
}

// SuperInteger to long conversion.
SuperInteger::operator long() {
	if (*this > std::numeric_limits<long>::max() || *this < std::numeric_limits<long>::min())
		return 0;
	else {
		long ret = 0, temp;
		for (std::deque<Digit>::iterator it = integers.begin(), short contr = 0; it != integers.end(); ++it, ++contr) {
			temp = (*it).x;
			for (short it2 = 0; it2 < contr; ++it2)
				temp *= 10;
			ret += temp;
		}
		return ret;
	}
}

// SuperInteger to unsigned char conversion.
SuperInteger::operator unsigned char() {
	if (*this > std::numeric_limits<unsigned char>::max() || *this < std::numeric_limits<unsigned char>::min())
		return 0;
	else {
		unsigned char ret = 0, temp;
		for (std::deque<Digit>::iterator it = integers.begin(), short contr = 0; it != integers.end(); ++it, ++contr) {
			temp = (*it).x;
			for (short it2 = 0; it2 < contr; ++it2)
				temp *= 10;
			ret += temp;
		}
		return ret;
	}
}

// SuperInteger to unsigned short conversion.
SuperInteger::operator unsigned short() {
	if (*this > std::numeric_limits<unsigned short>::max() || *this < std::numeric_limits<unsigned short>::min())
		return 0;
	else {
		unsigned short ret = 0, temp;
		for (std::deque<Digit>::iterator it = integers.begin(), short contr = 0; it != integers.end(); ++it, ++contr) {
			temp = (*it).x;
			for (short it2 = 0; it2 < contr; ++it2)
				temp *= 10;
			ret += temp;
		}
		return ret;
	}
}

// SuperInteger to unsigned int conversion.
SuperInteger::operator unsigned int() {
	if (*this > std::numeric_limits<unsigned int>::max() || *this < std::numeric_limits<unsigned int>::min())
		return 0;
	else {
		unsigned int ret = 0, temp;
		for (std::deque<Digit>::iterator it = integers.begin(), short contr = 0; it != integers.end(); ++it, ++contr) {
			temp = (*it).x;
			for (short it2 = 0; it2 < contr; ++it2)
				temp *= 10;
			ret += temp;
		}
		return ret;
	}
}

// SuperInteger to unsigned long conversion.
SuperInteger::operator unsigned long() {
	if (*this > std::numeric_limits<unsigned long>::max() || *this < std::numeric_limits<unsigned long>::min())
		return 0;
	else {
		unsigned long ret = 0, temp;
		for (std::deque<Digit>::iterator it = integers.begin(), short contr = 0; it != integers.end(); ++it, ++contr) {
			temp = (*it).x;
			for (short it2 = 0; it2 < contr; ++it2)
				temp *= 10;
			ret += temp;
		}
		return ret;
	}
}

// SuperInteger to char* conversion.
SuperInteger::operator char*() {
	std::string ret;
	if (!n)
		ret += '-';
	for (int i = digits; i >= 1; --i)
		ret += static_cast<char>(integers.at(i).x + 48);
	char* ret2 = ret.c_str()
	return ret2;
}

// SuperInteger to std::string conversion.
SuperInteger::operator std::string() {
	std::string ret;
	if (!n)
		ret += '-';
	for (int i = digits; i >= 1; --i)
		ret += static_cast<char>(integers.at(i).x + 48);
	return ret;
}

// Checking the construction of the char array for a normal SuperInteger (decimal).
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

// The empty SuperInteger initializer.
SuperInteger::SuperInteger() {
	++c;
	push(0);
}

// The SuperInteger initializer that takes the string as the number and the short variable that indicates its numeric system.
SuperInteger::SuperInteger(std::string si, short a) {
	if (a > 37 || a < 1)
		push(0);
}

// The char pointer initializer.
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

// The long initializer.
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
		si /= 10;
		++digits;
	} while (!si);
}

// The long double initializer.
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
		si /= 10;
		++digits;
	} while (!si);
}

// The string initializer.
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

// The destructor.
SuperInteger::~SuperInteger() {
	--c;
}

// Minus operator.
SuperInteger operator-(SuperInteger& a) {
	SuperInteger ret;
	ret = a;
	ret.neg() = !(a.neg());
	return ret;
}

// XOR operator that will be used to power the SuperInteger.
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

// Addition operator.
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

// Substraction operator.
SuperInteger operator-(SuperInteger const& a, SuperInteger const& b) {
	
	SuperInteger ret;
}

// Multiplication operator.
SuperInteger operator*(SuperInteger const& a, SuperInteger const& b) {
	SuperInteger ret;
}

// Integer division operator.
SuperInteger operator/(SuperInteger const& a, SuperInteger const& b) {
	SuperInteger ret;
}

// Modulo operator.
SuperInteger operator%(SuperInteger const& a, SuperInteger const& b) {
	SuperInteger ret;
}

// Assignment operator.
SuperInteger& SuperInteger::operator=(SuperInteger const& b) {
	if (this == &b)
		return *this;
	integers = b.returnDeque;
	n = b.neg();
	digits = b.digc();
}

// Left bit shift operator. It simply multiplies by 10.
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

// Right bit shift operator. It simply divides by 10.
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

// The AND operator for concatenation.
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

// Addition-assignment operator.
SuperInteger& SuperInteger::operator+=(SuperInteger const& b) {
	return *this = (*this) + b;
}

// Substraction-assignment operator.
SuperInteger& SuperInteger::operator-=(SuperInteger const& b) {
	return *this = (*this) - b;
}

// Multiplication-assignment operator.
SuperInteger& SuperInteger::operator*=(SuperInteger const& b) {
	return *this = (*this) * b;
}

// Division-assignment operator.
SuperInteger& SuperInteger::operator/=(SuperInteger const& b) {
	return *this = (*this) / b;
}

// Modulo-assignment operator.
SuperInteger& SuperInteger::operator%=(SuperInteger const& b) {
	return *this = (*this) % b;
}

// Left-bit-shift-assignment operator.
SuperInteger& SuperInteger::operator<<=(SuperInteger const& b) {
	return *this = (*this) << b;
}

// Right-bit-shift-assignment operator.
SuperInteger& SuperInteger::operator>>=(SuperInteger const& b) {
	return *this = (*this) >> b;
}

// XOR-assignment operator.
SuperInteger& SuperInteger::operator^=(SuperInteger const& b) {
	return *this = (*this) ^ b;
}

// The AND-assignment operator.
SuperInteger& SuperInteger::operator&=(SuperInteger const& b) {
	return *this = (*this) & b;
}

// The less-than operator.
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

// The greater-than operator.
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

// The less-than-or-equal operator.
bool operator<=(SuperInteger const& a, SuperInteger const& b) {
	if (a == b || a < b)
		return true;
	return false;
}

// The greater-than-or-equal operator.
bool operator>=(SuperInteger const& a, SuperInteger const& b) {
	if (a == b || a > b)
		return true;
	return false;
}

// The equality operator.
bool operator==(SuperInteger const& a, SuperInteger const& b) {
	if (a.digc() != b.digc() || a.neg() != b.neg())
		return false;
	else
		for (int iter = 1; iter <= a.digc() ++iter)
			if (a[iter] != b[iter])
				return false;
	return true;
}

// The difference operator.
bool operator!=(SuperInteger const& a, SuperInteger const& b) {
	if (a.digc() != b.digc() || a.neg() != b.neg())
		return true;
	else
		for (int iter = 1; iter <= a.digc() ++iter)
			if (a[iter] == b[iter])
				return false;
	return true;
}

// The preincrementation operator.
SuperInteger& SuperInteger::operator++() {
	*this += 1;
	if ((*this).digc() > max_size)
		return (*this) -= 1;
	else if (!(*this)) {
		(*this).neg() = false;
		return *this;
	}
}

// The postincrementation operator.
SuperInteger& SuperInteger::operator++(int) {
	*this += 1;
	if ((*this).digc() > max_size)
		return (*this) -= 1;
	else if (!(*this)) {
		(*this).neg() = false;
		return *this;
	}
}

// The predecrementation operator.
SuperInteger& SuperInteger::operator--() {
	*this -= 1;
	if ((*this).digc() > max_size)
		return (*this) -= 1;
	else if (*this == -1) {
		(*this).neg() = true;
		return *this;
	}
}

// The postdecrementation operator.
SuperInteger& SuperInteger::operator--(int) {
	*this -= 1;
	if ((*this).digc() > max_size)
		return (*this) -= 1;
	else if (*this == -1) {
		(*this).neg() = true;
		return *this;
	}
}

// The bool negation operator.
bool operator!(SuperInteger const& a) {
	if (a == 0)
		return true;
	return false;
}

// The std::ostream operator overload for printing out the SuperIntegers.
std::ostream& operator<<(std::ostream& out, SuperInteger const& si) {
	if (si.neg())
		out << '-';
	for (int i = 1; i <= digits; i++)
		out << si[i];
	return out;
}

// The std::istream operator overload for reading to the SuperIntegers.
std::istream& operator>>(std::istream& out, SuperInteger const& si) {
	char* ch;
	out >> ch;
	SuperInteger ret(ch);
	return ret;
}
