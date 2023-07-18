#include "../inc/Fixed.hpp"
#include <iostream>

const int Fixed::bits = 8;

Fixed::Fixed(void) : val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cp):val(cp.val)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cp;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &cp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->val = cp.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->val;
}

void Fixed::setRawBits(int const raw)
{
	this->val = raw;
}
