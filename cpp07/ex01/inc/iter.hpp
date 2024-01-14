#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template	<typename t, typename v>
void	iter(t *array, size_t len, void (*func)(const v num))
{
	if (!array || !len || !func)
		return ;
	for (size_t i = 0; i < len; i++)
		(*func)(array[i]);
}

#endif