#include "../inc/Cat.hpp"

Cat::Cat()
{
	type_ = "Cat";
	std::cout << "Cat: Default constructor called" << std::endl;
	brain_ = new Brain;
}

Cat::Cat(std::string type)
{
	type_ = type;
	std::cout << "Cat: Default constructor called" << std::endl;
	brain_ = new Brain;
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
	type_ = cp.type_;
	brain_ = new Brain(*cp.brain_);
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Cat is mewing" << std::endl;
}