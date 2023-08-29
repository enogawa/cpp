#ifndef Cat_HPP
#define Cat_HPP

#include"Animals.hpp"

class Cat : public Animals
{
public:
	Cat();
	Cat(std::string);
	Cat(const Cat &);
	~Cat();

	Cat &operator=(const Cat &);
};

#endif