#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animals
{
public:
	Animals();
	Animals(std::string);
	Animals(const Animals &);
	~Animals();

	Animals &operator=(const Animals &);
	
	virtual void makeSound(void) const ;
	std::string getType(void) const;
protected:
	std::string type_;
};

#endif