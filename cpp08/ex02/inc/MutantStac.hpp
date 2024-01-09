#ifndef	MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <deque>

template <typename T>
class	MutantStack : public std::deque<T>
{
	public:
		T		top();
		void	push(T num);
		void	pop();
};

template <typename T>
T		MutantStack<T>::top()
{
	return ((*this)[0]);
}

template <typename T>
void	MutantStack<T>::push(T num)
{
	this->push_front(num);
}

template <typename T>
void	MutantStack<T>::pop()
{
	this->pop_front();
}

#endif