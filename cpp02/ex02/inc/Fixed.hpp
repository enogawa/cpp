# ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>
#include <exception>

class Fixed
{
private:
	int	val;
	static const int bits;
	
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	Fixed(const Fixed &num);

	Fixed	&operator=(const Fixed &);
	bool	operator>(const Fixed &);
	bool	operator<(const Fixed &);
	bool	operator>=(const Fixed &);
	bool	operator<=(const Fixed &);
	bool	operator==(const Fixed &);
	bool	operator!=(const Fixed &);
	Fixed	operator+(const Fixed &);
	Fixed	operator-(const Fixed &);
	Fixed	operator*(const Fixed &);
	Fixed	operator/(const Fixed &);
	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	static Fixed&	min(Fixed &, Fixed &);
	static const Fixed&	min(const Fixed &, const Fixed &);
	static Fixed&	max(Fixed &, Fixed &);
	static const Fixed&	max(const Fixed &, const Fixed &);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &, const Fixed &);

#endif