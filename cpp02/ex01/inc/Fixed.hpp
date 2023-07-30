#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int val_;
		static const int bits_;
	public:
		Fixed();
		Fixed(int);
		Fixed(float);
		Fixed(const Fixed &);
		~Fixed();

		Fixed &operator=(const Fixed &);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
std::ostream &operator<<(std::ostream &, const Fixed &);

#endif