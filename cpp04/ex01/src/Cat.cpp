#include "../inc/Cat.hpp"

Cat::Cat()
{
	type_ = "Cat";
	brain_ = new Brain;
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(std::string type)
{
	type_ = type;
	brain_ = new Brain;
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cp)
{
	std::cout << "Cat: copy constructor called" << std::endl;
	*this = cp;
}

Cat::~Cat()
{
	delete brain_;
	std::cout << "Cat: Default destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &cp)
{
	this->brain_ = cp.brain_;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Cat is mewing" << std::endl;
}