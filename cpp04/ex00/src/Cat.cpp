#include "../inc/Cat.hpp"

Cat::Cat()
{
	type_ = "Cat";
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(std::string type)
{
	type_ = type;
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cp)
{
	std::cout << "Cat: copy constructor called" << std::endl;
	*this = cp;
}

Cat::~Cat()
{
	std::cout << "Cat: Default destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &cp)
{
	this->type_ = cp.type_;
	return (*this);
}