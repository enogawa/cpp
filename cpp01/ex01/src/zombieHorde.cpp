#include "../inc/Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int num, std::string name) {
	Zombie* horde = new Zombie[num];

	for (int i = 0; i < num; i++) {
		horde[i].put_name(name);
	}

	return horde;
}