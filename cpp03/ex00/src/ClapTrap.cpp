#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name_(""), hp_(10), ep_(10), ad_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name_(name), hp_(10), ep_(10), ad_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cp)
{
	(void)cp;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (hp_ <= 0)
	{
		std::cout << name_ << " has already died" << std::endl;
		return ;
	}
	else if (ep_ <= 0)
	{
		std::cout << name_ << " does not have any points!" << std::endl;
		return ;
	}
	ep_--;
	std::cout << name_ << " attacks " << target  << " " << ad_ << " damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hp_ <= 0)
	{
		std::cout << name_ << " has already died" << std::endl;
		return ;
	}
	hp_ -= amount;
	std::cout << name_ << " has taken " << amount << " of damage" << std::endl;
	if (hp_ <= 0)
	{
		std::cout << name_ << " has just died" << std::endl;
		return ;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hp_ <= 0)
	{
		std::cout << name_ << " has already died" << std::endl;
		return ;
	}
	else if (ep_ <= 0)
	{
		std::cout << name_ << " does not have any points!" << std::endl;
		return ;
	}
	ep_--;
	hp_ = amount;
	std::cout << name_ << " is repaired " << amount << " of points"<< std::endl;
}



