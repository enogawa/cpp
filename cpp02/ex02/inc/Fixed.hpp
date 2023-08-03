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
	Fixed(const int num);
	Fixed(const float num);
	Fixed();
	~Fixed();
	Fixed(const Fixed &num);
	Fixed	&operator=(const Fixed &rhs);
	bool	operator>(const Fixed &rhs)		const;
	bool	operator<(const Fixed &rhs)		const;
	bool	operator<=(const Fixed &rhs)	const;
	bool	operator>=(const Fixed &rhs)	const;
	bool	operator==(const Fixed &rhs)	const;
	bool	operator!=(const Fixed &rhs)	const;
	Fixed	operator+(const Fixed &rhs)		const;
	Fixed	operator-(const Fixed &rhs)		const;
	Fixed	operator*(const Fixed &rhs)		const;
	Fixed	operator/(const Fixed &rhs)		const;
	Fixed	operator++(void);

};

Fixed::Fixed(/* args */)
{
}

Fixed::~Fixed()
{
}




#endif