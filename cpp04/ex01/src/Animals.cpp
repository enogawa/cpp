#include "../inc/Animal.hpp"

Animal::Animal(): type_("Animal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(std::string type): type_(type)
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const Animal &cp)
{
	std::cout << "Animal: copy constructor called" << std::endl;
	*this = cp;
}

Animal::~Animal()
{
	std::cout << "Animal: Default destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &cp)
{

	type_ = cp.type_;
	return *this;
}

void	Animal::makeSound(void) const
{
	std::cout << type_ << " is making some noise" << std::endl;
}

std::string	Animal::getType() const
{
	return this->type_;
}