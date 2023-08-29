#ifndef WRONCAT_HPP
#define WRONCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(std::string);
	WrongCat(const WrongCat &);
	~WrongCat();

	WrongCat &operator=(const WrongCat &);
};

#endif