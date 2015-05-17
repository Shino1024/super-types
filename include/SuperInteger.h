#ifndef SUPERINTEGER_H
#define SUPERINTEGER_H
#include <string>
#include <limits>
#include <iostream>

struct Digit {
	unsigned short x: 4;
	Digit(short);
	Digit(int);
	Digit& operator=(short);
	friend Digit operator+(Digit const&, Digit const&);
	friend Digit operator-(Digit const&, Digit const&);
	Digit& operator+=(Digit const&);
	Digit& operator-=(Digit const&);
	operator int();
};
class SuperInteger {
	private:
		std::deque<Digit> integers;
		std::deque<SuperInteger>(1) boolset;
		int digits = 1;
		static int c = 0;
		bool n = false;
	public:
		bool& neg() {return n;}
		operator bool();
		operator char();
		operaotr char*();
		operator short();
		operator int();
		operator long();
		operator unsigned char();
		operator unsigned short();
		operator unsigned int();
		operator unsigned long();
		operator char*();
		operator std::string();
		friend void setbool(SuperInteger s) {boolset.push_back(s);}
		friend void delbool(SuperInteger);
		int digc() {return digits;}
		std::deque<Digit> returnDeque() const {return integers;}
		void ins(Digit a) {integers.push_front(a);}
		void push(Digit a) {integers.push_back(a);}
		void pop() {integers.pop_front();}
		void drop() {integers.pop_back();}
		int count() const {return c;}
		int& operator[](int a) {return integers.at(a - 1).x;}
		int operator~() {return this->digits;}
		SuperInteger(std::string&, int);
		SuperInteger(char[]);
		SuperInteger(long int);
		SuperInteger(std::string&);
		SuperInteger& operator=(SuperInteger const&);
		friend SuperInteger operator+(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator+=(SuperInteger const&);
		friend SuperInteger operator-(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator-=(SuperInteger const&);
		friend SuperInteger operator*(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator*=(SuperInteger const&);
		friend SuperInteger operator/(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator/=(SuperInteger const&);
		friend SuperInteger operator%(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator%=(SuperInteger const&);
		friend SuperInteger operator<<(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator<<=(SuperInteger const&);
		friend SuperInteger operator>>(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator>>=(SuperInteger const&);
		friend SuperInteger operator^(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator^=(SuperInteger const&);
		friend SuperInteger operator-(SuperInteger const&);
		friend SuperInteger operator&(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator&=(SuperInteger const&);
		SuperInteger& operator++();
		SuperInteger& operator++(int);
		SuperInteger& operator--();
		SuperInteger& operator--(int);
		friend bool operator<(SuperInteger const&, SuperInteger const&) const;
		friend bool operator<=(SuperInteger const&, SuperInteger const&) const;
		friend bool operator>(SuperInteger const&, SuperInteger const&) const;
		friend bool operator>=(SuperInteger const&, SuperInteger const&) const;
		friend bool operator==(SuperInteger const&, SuperInteger const&) const;
		friend bool operator!=(SuperInteger const&, SuperInteger const&) const;
		friend bool operator!(SuperInteger const&) const;
		friend std::ostream& operator<<(std::ostream&, SuperInteger const&);
		friend std::istream& operator>>(std::istream&, SuperInteger const&);
};
#endif
