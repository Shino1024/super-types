#pragma once
class SuperInteger {
	private:
		struct Digit {
			unsigned short x: 4;
		};
		Digit* integers;
		int digits;
		static int c;
		int iterator = 0;
		bool neg;
	public:
		friend SuperInteger(char[]);
		friend SuperInteger(long int);
		void introduce(SuperInteger&);
		bool& isneg() {return neg;}
		friend std::ostream& operator<<(std::ostream&, SuperInteger const&);
};
