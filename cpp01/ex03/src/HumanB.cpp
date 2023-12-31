#include "../inc/HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &_name) : _name(_name){}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon *_weapon)
{
	this->_weapon = _weapon;
}
