#include "../inc/ScavTrap.hpp"

int main(void)
{
	ScavTrap man_42("man");

	man_42.attack("woman");
	man_42.attack("woman");
	man_42.attack("woman");
	man_42.attack("woman");
	man_42.attack("woman");
	man_42.attack("woman");
	man_42.attack("woman");
	man_42.takeDamage(1000);
	man_42.attack("woman");
	man_42.attack("woman");
	man_42.beRepaired(10);
	man_42.beRepaired(10);
	man_42.beRepaired(10);
	man_42.beRepaired(10);

	return 0;
}