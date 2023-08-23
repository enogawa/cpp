#include "../inc/Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(void) : val(0){}

Fixed::Fixed(int num)
{
	this->val = num * (1 << bits);
}

Fixed::Fixed(float num)
{
	this->val = roundf(num * (1 << bits));
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const Fixed &cp)
{
	*this = cp;
}

Fixed	&Fixed::operator=(const Fixed &cp)
{
	this->val = cp.val;
	return (*this);
}

bool	Fixed::operator>(const Fixed &cp)
{
	return(this->val > cp.val);
}

bool	Fixed::operator<(const Fixed &cp)
{
	return (this->val < cp.val);
}

bool	Fixed::operator>=(const Fixed &cp)
{
	return (this->val >= cp.val);
}

bool	Fixed::operator<=(const Fixed &cp)
{
	return (this->val <= cp.val);
}

bool	Fixed::operator==(const Fixed &cp)
{
	return (this->val == cp.val);
}

bool	Fixed::operator!=(const Fixed &cp)
{
	return (this->val != cp.val);
}

Fixed	Fixed::operator+(const Fixed &cp)
{
	Fixed	ans;

	ans.val = (this->val + cp.val);
	return (ans);
}

Fixed	Fixed::operator-(const Fixed &cp)
{
	Fixed	ans;

	ans.val = (this->val - cp.val);
	return (ans);
}

Fixed	Fixed::operator*(const Fixed &cp)
{
	Fixed	ans;

	ans.val = (this->val * cp.val);
	return (ans);
}

Fixed	Fixed::operator/(const Fixed &cp)
{
	Fixed	ans;

	ans.val = (this->val * cp.val);
	return (ans);
}

Fixed	&Fixed::operator++(void)
{
	this->val++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	ans(*this);

	this->val++;
	return (ans);
}

Fixed	&Fixed::operator--(void)
{
	this->val--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ans(*this);

	this->val--;
	return(ans);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return b;
	else
		return a;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if ((Fixed &)a > (Fixed &)b)
		return (b);
	else
		return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if ((Fixed &)a < (Fixed &)b)
		return (b);
	else
		return (a);
}

float	Fixed::toFloat(void) const
{
	return (float)val / (1 << bits);
}

int	Fixed::toInt(void) const
{
	return (int)val / (1 << bits);
}

int	Fixed::getRawBits(void) const
{
	return (this->val);
}

void	Fixed::setRawBits(int const raw)
{
	this->val = raw;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed_class)
{
	stream << fixed_class.toFloat();

	return stream;
}
