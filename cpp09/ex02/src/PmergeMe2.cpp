#include "../inc/PmergeMe.hpp"

std::list<int>::iterator	advanceIte(size_t	num, std::list<int>::iterator ite)
{
	for (size_t i = 0; i < num; i++)
		ite++;
	return (ite);
}

size_t	binarySearch(std::list<int> main_chain, int	sub_num, size_t count, size_t step)
{
	size_t	left = 0;
	size_t	right = count;

	if (sub_num < *main_chain.begin())
		return (0);
	while (right - left > 1)
	{
		size_t mid = (right + left) / 2;
		if (*advanceIte(mid*step, main_chain.begin()) < sub_num)
			left = mid;
		else
			right = mid;
	}
	return (right * step);
}

void	insertSubIntoMain(std::list<int> &main_chain, std::list<int> &sub_chain, size_t step)
{
	size_t	count = 0;
	for (size_t i = 0; i < sub_chain.size(); i+=step)
	{
		size_t index = binarySearch(main_chain, *advanceIte(i, sub_chain.begin()), count, step);
		for (size_t j = 0; j < step; j++)
		{
			main_chain.insert(advanceIte(index+j, main_chain.begin()), *advanceIte(i+j, sub_chain.begin()));
		}	
		count += 2;
	}
}

void	splitIntoMainSub(std::list<int> lst, std::list<int> &main_chain, std::list<int> &sub_chain, size_t step)
{
	std::list<int>	tmp_chain = sub_chain;

	sub_chain.clear();
	for (size_t i = 0; i < lst.size(); i++)
	{
		if ((i / step) % 2 == 0)
			main_chain.push_back(*advanceIte(i, lst.begin()));
		else
			sub_chain.push_back(*advanceIte(i, lst.begin()));
	}
	for (size_t i = 0; i < tmp_chain.size(); i++)
		sub_chain.push_back(*advanceIte(i, tmp_chain.begin()));
}

void	swaplst(std::list<int> &lst, size_t index, std::size_t step)
{
	for (size_t i = index; i < index + step; i++)
	{
		std::swap(*advanceIte(i, lst.begin()), *advanceIte(i + step, lst.begin()));
	}
}

std::list<int>	mergeInsertionSort(std::list<int> lst, std::size_t step)
{
	std::list<int> main_chain, sub_chain;
	size_t	pair_size = step * 2;
	if (lst.size() <= step)
		return (lst);
	size_t i = 0;
	std::list<int>::iterator ite = lst.begin();
	while(i + pair_size <= lst.size())
	{
		if (*ite < *advanceIte(i + step, lst.begin()))
			swaplst(lst, i, step);
		i += pair_size;
		ite = advanceIte(i, lst.begin());
	}
	if (lst.size() % pair_size)
	{
		for (;i < lst.size(); i++)
		{
			sub_chain.push_back(*advanceIte(i, lst.begin()));
		}
		lst.resize((lst.size() / pair_size) * pair_size);
	}
	lst = mergeInsertionSort(lst, step * 2);
	splitIntoMainSub(lst, main_chain, sub_chain, step);
	insertSubIntoMain(main_chain, sub_chain, step);
	return (main_chain);
}