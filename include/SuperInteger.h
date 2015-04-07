#pragma once
struct Digit {
	unsigned short x: 4;
};
class SuperInteger {
	private:
		std::deque<Digit> integers;
		int digits = 1;
		static int c;
		bool neg;
		bool& isneg() {return neg;}
		int& dig() const {return digits;}
	public:
		std::deque<Digit> returnDeque() const {return integers;}
		void ins(Digit a) const {integers.push_front(a);}
		void push(Digit a) const {integers.push_back(a);}
		void pop() const {integers.pop_front();}
		void drop() const {integers.pop_back();}
		int count() const {return c;}
		int& operator[](int a) {return integers.at(a - 1).x;}
		SuperInteger(char[]);
		SuperInteger(long int);
		void introduce(SuperInteger&) const;
		bool check(char[]);
		SuperInteger& operator=(SuperInteger&, SuperInteger const&);
		friend SuperInteger operator+(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator+=(SuperInteger&, SuperInteger const&);
		friend SuperInteger operator-(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator-=(SuperInteger&, SuperInteger const&);
		friend SuperInteger operator*(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator*=(SuperInteger&, SuperInteger const&);
		friend SuperInteger operator/(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator/=(SuperInteger&, SuperInteger const&);
		friend SuperInteger operator%(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator%=(SuperInteger&, SuperInteger const&);
		friend SuperInteger operator<<(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator<<=(SuperInteger&, SuperInteger const&);
		friend SuperInteger operator>>(SuperInteger const&, SuperInteger const&);
		SuperInteger& operator>>=(SuperInteger&, SuperInteger const&);
		friend SuperInteger& operator-(SuperInteger const&);
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
