#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string	name_;
	int hp_;
	int ep_;
	int ad_;
public:
	ClapTrap();
	ClapTrap(std::string);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif