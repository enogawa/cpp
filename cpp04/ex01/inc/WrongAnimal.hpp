#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string);
	WrongAnimal(const WrongAnimal &);
	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &);
	void makeSound(void) const;
	std::string getType(void) const;
protected:
	std::string type_;
};

#endif