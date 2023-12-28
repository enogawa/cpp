#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <iterator>

template <typename T >
typename T::iterator	easyfind(T &container, int num)
{
	for (typename T::iterator iter = container.begin(); iter != container.end(); iter++)
		if (*iter == num)
			return (iter);
	return (container.end());
}

#endif