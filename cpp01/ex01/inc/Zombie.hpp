#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
	Zombie(std::string name);
	void	put_name(const std::string &name);
	void announce();
	Zombie();
	~Zombie();
;

private:
	std::string _name;
};


#endif
