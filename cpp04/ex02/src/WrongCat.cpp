#include "../inc/WrongCat.hpp"

WrongCat::WrongCat()
{
	type_ = "WrongCat";
	std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
	type_ = type;
	std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cp)
{
	std::cout << "WrongCat: copy constructor called" << std::endl;
	*this = cp;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Default destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &cp)
{
	this->type_ = cp.type_;
	return (*this);
}