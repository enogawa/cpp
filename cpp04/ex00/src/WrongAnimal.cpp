#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal")
{
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type_(type)
{
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cp)
{
	std::cout << "WrongAnimal: copy constructor called" << std::endl;
	*this = cp;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor is called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &cp)
{
	type_ = cp.type_;
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << type_ << " is making some wrong noise" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->type_;
}
