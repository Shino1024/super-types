#ifndef SUPERINTEGER_H
#define SUPERINTEGER_H

// The Digit structure that holds one digit in four bits of memory.
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

// The actual SuperInteger class.
class SuperInteger {
	private:
		std::deque<Digit> integers; // The container where the ordered Digits are kept in.
		std::deque<SuperInteger>(1) boolset; // The container that holds the "false SuperIntegers".
		int digits = 1; // Number of Digits of the SuperInteger.
		static int c = 0; // Number of SuperIntegers.
		bool n = false; // The negativity sign.

	public:
		// Conversion:
		operator bool();
		operator char();
		operator char*();
		operator short();
		operator int();
		operator long();
		operator unsigned char();
		operator unsigned short();
		operator unsigned int();
		operator unsigned long();
		operator char*();
		operator std::string();

		// Utilities:
		bool& neg() {return n;} // Toggling the negativity.
		friend void setbool(SuperInteger s) {boolset.push_back(s);} // The method for setting the "false SuperIntegers".
		friend void delbool(SuperInteger); // The method for deleting the "false SuperIntegers".
		int digc() {return digits;} // The number of Digits in the SuperInteger.
		std::deque<Digit> returnDeque() const {return integers;} // The function that returns the deque with the Digits of the SuperInteger.
		void ins(Digit a) {integers.push_front(a);} // The method for inserting the Digits on the front of the SuperInteger.
		void push(Digit a) {integers.push_back(a);} // The method for pushing the Digits on the rear of the SuperInteger.
		void pop() {integers.pop_front();} // The method for popping the Digits from the front of the SuperInteger.
		void drop() {integers.pop_back();} // The method for dropping the Digits from the back of the SuperInteger.
		int count() const {return c;} // The number of the SuperIntegers.
		int& operator[](int a) {return integers.at(a - 1).x;} // The subscription operator that returns the ath Digit in the SuperInteger.
		int operator~() {return this->digits;} // The complementary operator that returns the number of digits in the SuperInteger.
		std::deque<Digit> operator+() {return integers;} // The unary-plus operator for returning the deque with the digits.

		// Constructors:
		SuperInteger(std::string&, short);
		SuperInteger(char[]);
		SuperInteger(long int);
		SuperInteger(std::string&);

		// The operator overloads:
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
