#include "../inc/Fixed.hpp"

const int Fixed::bits_ = 8;

Fixed::Fixed(void) : val_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int val)
{
	std::cout << "Int constructor called" << std::endl;
	this->val_ = val << bits_;
}

Fixed::Fixed(float val)
{
	std::cout << "Float constructor called" << std::endl;
	this->val_ = roundf(val * (1 << bits_));
}

Fixed::Fixed(const Fixed &cp) : val_(cp.val_)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cp;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &cp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->val_ = cp.getRawBits();
	return (*this);
}

float	Fixed::toFloat(void) const
{
	return (float)val_ / (1 << bits_);
}

int	Fixed::toInt(void) const
{
	return (int)val_ / (1 << bits_);
}

int	Fixed::getRawBits(void) const
{
	return (this->val_);
}

void	Fixed::setRawBits(int const raw)
{
	this->val_ = raw;
}

std::ostream &operator << (std::ostream &stream, const Fixed &fixed_class)
{
	stream << fixed_class.toFloat();
	return (stream);
}
