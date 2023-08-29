#ifndef Cat_HPP
#define Cat_HPP

#include"Animal.hpp"
#include"Brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(std::string);
	Cat(const Cat &);
	~Cat();

	Cat &operator=(const Cat &);
	void makeSound(void) const;
private:
	Brain *brain_;
};

#endif