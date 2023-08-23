#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	name_ = "";
	hp_ = 100;
	ep_ = 50;
	ad_ = 20;
	std::cout << "[ST] Default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	name_ = name;
	hp_ = 100;
	ep_ = 50;
	ad_ = 20;
	std::cout << "[ST] Default constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cp)
{
	*this = cp;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ST] Destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &cp)
{
	(void)cp;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (ep_ <= 0)
	{
		std::cout << name_ << " does not have any points to attack" << std::endl;
		return ;
	}
	else if (hp_ <= 0)
	{
		std::cout << name_ << " has already died" << std::endl;
		return ;
	}
	ep_--;
	std::cout << name_ << " attacks " << target << " for " << ad_ << " damages" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (hp_ <= 0)
	{
		std::cout << name_ << "has already died" << std::endl;
		return ;
	}
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}