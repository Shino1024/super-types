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
		void introduce(SuperInteger&) const;
		bool& isneg() {return neg;}
		int dig() const {return digits;}
		int dig(int x) const {return integers[x - 1]->x;}
		bool check(char[]);
		friend std::ostream& operator<<(std::ostream&, SuperInteger const&);
};
