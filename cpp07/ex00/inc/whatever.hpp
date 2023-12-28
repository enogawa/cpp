#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template	<typename t>
void	swap(t &a, t &b)
{
	t	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template	<typename t>
t	const &min(t const &a, t const &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template	<typename t>
t	const &max(t const &a, t const &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif