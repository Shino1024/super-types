#pragma once
class SuperInteger {
	private:
		struct Digit {
			unsigned short x: 4;
		};
		std::vector<Digit> integers;
		int digits = 0;
		static int c;
		bool neg;
	public:
		int& operator[](int a) {return integers.at(a - 1).x;}
		SuperInteger(char[]);
		SuperInteger(long int);
		void introduce(SuperInteger&) const;
		bool& isneg() {return neg;}
		int& dig() const {return digits;}
		bool check(char[]);
		friend std::ostream& operator<<(std::ostream&, SuperInteger const&);
};
