#include "../inc/Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {}

void	Zombie::put_name(const std::string &name)
{
	this->_name = name;
}

Zombie::~Zombie(void) {
	std::cout << _name << " died!" << std::endl;
}

void Zombie::announce() {
	std::cout << _name << " Braiiiiiiinnnssss..." << std::endl;
}
Zombie::Zombie() {}
