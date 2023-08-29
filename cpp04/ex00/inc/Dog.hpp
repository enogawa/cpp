#ifndef DOG_HPP
#define DOG_HPP

#include"Animals.hpp"

class Dog : public Animals
{
public:
	Dog();
	Dog(std::string);
	Dog(const Dog &);
	~Dog();

	Dog &operator=(const Dog &);
};

#endif