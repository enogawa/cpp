#ifndef DOG_HPP
#define DOG_HPP

#include"Animals.hpp"
#include"Brain.hpp"

class Dog : public Animals
{
public:
	Dog();
	Dog(std::string);
	Dog(const Dog &);
	~Dog();

	Dog &operator=(const Dog &);
	void makeSound(void) const;
private:
	Brain *brain_;
};

#endif