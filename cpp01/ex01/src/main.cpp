#include "../inc/Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main() {
	int	numZombies = 5;
	int	i = 0;

	Zombie* zom = zombieHorde(numZombies, "Tom");

	while (i < numZombies)
	{
		zom[i].announce();
		i++;
	}
	delete[] zom;
	return 0;
}
