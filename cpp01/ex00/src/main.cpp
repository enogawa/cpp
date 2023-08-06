#include "../inc/Zombie.hpp"

int main()
{
	randomChump("Stack Zombie");
	Zombie* heapZombie = newZombie("Heap Zombie");
	heapZombie->announce();
	delete heapZombie;
	return 0;
}
