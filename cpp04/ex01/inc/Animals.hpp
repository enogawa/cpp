#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal();
	Animal(std::string);
	Animal(const Animal &);
	virtual ~Animal();

	Animal &operator=(const Animal &);
	
	virtual void makeSound(void) const;
	std::string getType(void) const;
protected:
	std::string type_;
};

#endif