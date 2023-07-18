#include "../inc/Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main() {
	int numZombies = 5;
	Zombie* zom = zombieHorde(numZombies, "Tom");

	for (int i = 0; i < numZombies; i++) {
		zom[i].announce();
	}

	delete[] zom;
	return 0;
}
