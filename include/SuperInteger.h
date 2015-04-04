#pragma once
class SuperInteger {
	private:
		struct Digit {
			unsigned short x: 4;
		};
		std::deque<Digit> integers;
		int digits = 1;
		static int c;
		bool neg;
		bool& isneg() {return neg;}
		int& dig() const {return digits;}
	public:
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
		friend SuperInteger operator+(SuperInteger const&, SuperInteger const&);
		friend SuperInteger& operator+=(SuperInteger const&, SuperInteger const&);
		friend SuperInteger operator-(SuperInteger const&, SuperInteger const&);
		friend SuperInteger& operator-=(SuperInteger const&, SuperInteger const&);
		friend SuperInteger operator*(SuperInteger const&, SuperInteger const&);
		friend SuperInteger& operator*=(SuperInteger const&, SuperInteger const&);
		friend SuperInteger operator/(SuperInteger const&, SuperInteger const&);
		friend SuperInteger& operator/=(SuperInteger const&, SuperInteger const&);
		friend SuperInteger operator%(SuperInteger const&, SuperInteger const&);
		friend SuperInteger& operator%=(SuperInteger const&, SuperInteger const&);
		friend SuperInteger operator<<(SuperInteger const&, SuperInteger const&);
		friend SuperInteger& operator<<=(SuperInteger const&, SuperInteger const&);
		friend SuperInteger operator>>(SuperInteger const&, SuperInteger const&);
		friend SuperInteger& operator>>=(SuperInteger const&, SuperInteger const&);
		friend SuperInteger& operator-(SuperInteger const&);
		friend SuperInteger& operator++(SuperInteger const&);
		friend SuperInteger& operator++(SuperInteger const&, int);
		friend SuperInteger& operator--(SuperInteger const&);
		friend SuperInteger& operator--(SuperInteger const&, int);
		friend bool operator<(SuperInteger const& a, SuperInteger const& b);
		friend bool operator<=(SuperInteger const& a, SuperInteger const& b);
		friend bool operator>(SuperInteger const& a, SuperInteger const& b);
		friend bool operator>=(SuperInteger const& a, SuperInteger const& b);
		friend bool operator==(SuperInteger const& a, SuperInteger const& b);
		friend bool operator!=(SuperInteger const& a, SuperInteger const& b);
		friend std::ostream& operator<<(std::ostream&, SuperInteger const&);
};
