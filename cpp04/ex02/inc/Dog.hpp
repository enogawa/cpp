#ifndef DOG_HPP
#define DOG_HPP

#include"Animal.hpp"
#include"Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(std::string);
	Dog(const Dog &);
	~Dog();

	Dog &operator=(const Dog &);
	void makeSound(void);
private:
	Brain *brain_;
};

#endif