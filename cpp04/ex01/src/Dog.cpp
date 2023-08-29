#include "../inc/Dog.hpp"

Dog::Dog() 
{
	type_ = "Dog";
	brain_ = new Brain;
	std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(std::string type)
{
	type_ = type;
	brain_ = new Brain;
	std::cout << "Dog: Default constructor called" << std::endl;
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
	this->brain_ = cp.brain_;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Dog is barking" << std::endl;
}
