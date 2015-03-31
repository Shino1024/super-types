#pragma once
class SuperInteger {
	private:
		struct Digit {
			unsigned short x: 4;
		};
		std::vector<Digit> integers;
		int digits;
		static int c;
		bool neg;
	public:
		void resize(int a);
		int& operator[](int a) {return integers.at(a - 1).x;}
		friend SuperInteger(char[]);
		friend SuperInteger(long int);
		void introduce(SuperInteger&) const;
		bool& isneg() {return neg;}
		int& dig() const {return digits;}
		bool check(char[]);
		friend std::ostream& operator<<(std::ostream&, SuperInteger const&);
};
