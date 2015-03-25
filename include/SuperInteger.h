#pragma once
class SuperInteger {
	private:
		struct Digit {
			unsigned short x: 4;
		} integer[4096];
		int digits;
		static int c;
		int iterator = 4096;
		bool neg;
	public:
		SuperInteger(char[]);
		SuperInteger(int);
		void introduce(SuperInteger&);
		int& iter() const {return iterator;}
};
SuperInteger operator+(SuperInteger const&, SuperInteger const&);
SuperInteger operator*(SuperInteger const&, SuperInteger const&);
SuperInteger operator-(SuperInteger const&, SuperInteger const&);
SuperInteger operator/(SuperInteger const&, SuperInteger const&);
SuperInteger operator%(SuperInteger const&, SuperInteger const&);
