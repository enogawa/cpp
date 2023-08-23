#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hp_ = 100;
	ep_ = 100;
	ad_ = 30;
	std::cout << "[FT] Default constructor is called" << std::endl;
}

FragTrap::FragTrap(std::string name ) : ClapTrap(name)
{
	hp_ = 100;
	ep_ = 100;
	ad_ = 30;
	std::cout << "[FT] Default constructor is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &cp)
{
	*this = cp;
	std::cout << "[FT] Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FT] Destructor is called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &cp)
{
	(void)cp;
	(void)cp.ep_;
	(void)cp.ad_;

	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (hp_ <= 0)
	{
		std::cout << "ClapTrap " << name_ << " is died" << std::endl;
		return;
	}
	std::cout << "FragTrap " << name_ << " is trying to high-fives." << std::endl;
}
