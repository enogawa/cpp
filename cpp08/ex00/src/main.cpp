#include "../inc/easyfind.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int>	v(100);
	for (size_t i = 0; i < v.size(); i++)
		v[i] = i;
	std::vector<int>::iterator iter = easyfind(v, 95);
	std::cout << *iter << std::endl;
	std::vector<int>::iterator iter1 = easyfind(v, 150);
	std::cout << *iter1 << std::endl;
}