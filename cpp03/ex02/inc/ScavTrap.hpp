#ifndef SCAVCRAP_HPP
#define SCAVCRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public  ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string);
	ScavTrap(const ScavTrap &);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &);

	void attack(const std::string &target);
	void guardGate(void);
};

#endif