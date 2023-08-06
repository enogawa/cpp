#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name) : name(name){}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Destroying zombie: " << name << std::endl;
}