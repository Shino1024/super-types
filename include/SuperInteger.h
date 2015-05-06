#pragma once
struct Digit {
	unsigned short x: 4;
	Digit(short);
	Digit(int);
	Digit& operator=(short);
	operator int();
};
class SuperInteger {
	private:
		std::deque<Digit> integers;
		int digits = 1;
		static int c = 0;
		bool n = false;
	public:
		bool& neg() {return n;}
		operator char();
		operator short();
		operator int();
		operator long();
		operator unsigned char();
		operator unsigned short();
		operator unsigned int();
		operator unsigned long();
		operator std::string();
		int digc() {return digits;}
		std::deque<Digit> returnDeque() const {return integers;}
		void ins(Digit a) {integers.push_front(a);}
		void push(Digit a) {integers.push_back(a);}
		void pop() {integers.pop_front();}
		void drop() {integers.pop_back();}
		int count() const {return c;}
		int& operator[](int a) {return integers.at(a - 1).x;}
		int operator~() {return this->digits;}
		SuperInteger operator()(SuperInteger& a) {return (*this) * a;}
		SuperInteger(std::string&, int);
		SuperInteger(char[]);
		SuperInteger(long int);
		SuperInteger(std::string&);
		void introduce(SuperInteger&) const;
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
		friend std::ostream& operator>>(std::ostream&, SuperInteger const&);
};
