#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain&);
	~Brain();

	Brain &operator=(const Brain &);

private:
	std::string ideas_[100];
};

#endif