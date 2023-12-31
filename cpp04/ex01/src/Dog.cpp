#include "../inc/Dog.hpp"

Dog::Dog() 
{
	type_ = "Dog";
	std::cout << "Dog: Default constructor called" << std::endl;
	brain_ = new Brain;
}

Dog::Dog(std::string type)
{
	type_ = type;
	std::cout << "Dog: Default constructor called" << std::endl;
	brain_ = new Brain;
}

Dog::Dog(const Dog &cp)
{
	std::cout << "Dog: copy constructor called" << std::endl;
	*this = cp;
}

Dog::~Dog()
{
	delete brain_;
	std::cout << "Dog: Default destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &cp)
{
	type_ = cp.type_;
	brain_ = new Brain(*cp.brain_);
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Dog is barking" << std::endl;
}
