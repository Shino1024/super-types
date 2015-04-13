#pragma once
struct Digit {
	unsigned short x: 4;
	Digit(short);
	short& operator=(short);
};
class SuperInteger {
	private:
		std::deque<Digit> integers;
		int digits = 1;
		static int c;
		bool n = false;
		bool& neg() {return n;}
		int& digc() {return digits;}
	public:
		bool isneg() {return n;}
		int dig() {return digits;}
		std::deque<Digit> returnDeque() const {return integers;}
		void ins(Digit a) {integers.push_front(a);}
		void push(Digit a) {integers.push_back(a);}
		void pop() {integers.pop_front();}
		void drop() {integers.pop_back();}
		int count() const {return c;}
		int& operator[](int a) {return integers.at(a - 1).x;}
		SuperInteger(char[]);
		SuperInteger(long int);
		SuperInteger(std::string&);
		void introduce(SuperInteger&) const;
		bool check(char[]);
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
		SuperInteger& operator++();
		SuperInteger& operator++(int);
		SuperInteger& operator--();
		SuperInteger& operator--(int);
		friend bool operator<(SuperInteger const&, SuperInteger const&);
		friend bool operator<=(SuperInteger const&, SuperInteger const&);
		friend bool operator>(SuperInteger const&, SuperInteger const&);
		friend bool operator>=(SuperInteger const&, SuperInteger const&);
		friend bool operator==(SuperInteger const&, SuperInteger const&);
		friend bool operator!=(SuperInteger const&, SuperInteger const&);
		friend bool operator!(SuperInteger const&);
		friend std::ostream& operator<<(std::ostream&, SuperInteger const&);
};
