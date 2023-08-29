#include <Brain.hpp>

Brain::Brain()
{
	std::cout << "Brain: Default Constructor called" << std::endl;
}

Brain::Brain(const Brain& cp)
{
	*this = cp;
	std::cout << "Brain: Copy Constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain& cp)
{
	for (size_t i = 0; i < 100; i++)
		ideas_[i] = cp.ideas_[i];
	return *this;
}
