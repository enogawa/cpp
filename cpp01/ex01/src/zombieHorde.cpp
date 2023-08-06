#include "../inc/Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int num, std::string name)
{
	Zombie* horde = new Zombie[num];
	int i = 0;

	while(i < num)
	{
		horde[i].put_name(name);
		i++;
	}
	return horde;
}