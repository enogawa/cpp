#include "../inc/Dog.hpp"

Dog::Dog()
{
	type_ = "Dog";
	std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(std::string type)
{
	type_ = type;
	std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(const Dog &cp)
{
	std::cout << "Dog: copy constructor called" << std::endl;
	*this = cp;
}

Dog::~Dog()
{
	std::cout << "Dog: Default destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &cp)
{
	this->type_ = cp.type_;
	return (*this);
}
