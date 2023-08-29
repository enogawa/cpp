#include "../inc/Animals.hpp"

Animals::Animals(): type_("Animal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animals::Animals(std::string type): type_(type)
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animals::Animals(const Animals &cp)
{
	std::cout << "Animal: copy constructor called" << std::endl;
	*this = cp;
}

Animals::~Animals()
{
	std::cout << "Animal: Default destructor called" << std::endl;
}

Animals &Animals::operator=(const Animals &cp)
{

	type_ = cp.type_;
	return *this;
}

void	Animals::makeSound(void) const
{
	std::cout << type_ << " is making some noise" << std::endl;
}

std::string	Animals::getType() const
{
	return this->type_;
}