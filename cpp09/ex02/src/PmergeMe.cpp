#include "../inc/PmergeMe.hpp"

size_t	binarySearch(std::vector<int> main_chain, int	sub_num, size_t count, size_t step)
{
	size_t	left = 0;
	size_t	right = count;

	if (sub_num < main_chain[0])
		return (0);
	while (right - left > 1)
	{
		size_t mid = (right + left) / 2;
		if (main_chain[mid * step] < sub_num)
			left = mid;
		else
			right = mid;
	}
	return (right * step);
}

void	insertSubIntoMain(std::vector<int> &main_chain, std::vector<int> &sub_chain, size_t step)
{
	size_t	count = 0;
	for (size_t i = 0; i < sub_chain.size(); i+=step)
	{
		size_t index = binarySearch(main_chain, sub_chain[i], count, step);
		for (size_t j = 0; j < step; j++)
		{
			main_chain.insert(main_chain.begin() + index + j, sub_chain[i + j]);
		}	
		count += 2;
	}
}

void	splitIntoMainSub(std::vector<int> vec, std::vector<int> &main_chain, std::vector<int> &sub_chain, size_t step)
{
	std::vector<int>	tmp_chain = sub_chain;

	sub_chain.clear();
	for (size_t i = 0; i < vec.size(); i++)
	{
		if ((i / step) % 2 == 0)
			main_chain.push_back(vec[i]);
		else
			sub_chain.push_back(vec[i]);
	}
	for (size_t i = 0; i < tmp_chain.size(); i++)
		sub_chain.push_back(tmp_chain[i]);
}

void	swapVec(std::vector<int> &vec, size_t index, std::size_t step)
{
	for (size_t i = index; i < index + step; i++)
	{
		std::swap(vec[i], vec[i + step]);
	}
}

std::vector<int>	mergeInsertionSort(std::vector<int> vec, std::size_t step)
{
	std::vector<int> main_chain, sub_chain;
	size_t	pair_size = step * 2;
	if (vec.size() <= step)
		return (vec);
	size_t i = 0;
	while(i + pair_size <= vec.size())
	{
		if (vec[i] < vec[i + step])
			swapVec(vec, i, step);
		i += pair_size;
	}
	if (vec.size() % pair_size)
	{
		for (;i < vec.size(); i++)
		{
			sub_chain.push_back(vec[i]);
		}
		vec.resize((vec.size() / pair_size) * pair_size);
	}
	vec = mergeInsertionSort(vec, step * 2);
	splitIntoMainSub(vec, main_chain, sub_chain, step);
	insertSubIntoMain(main_chain, sub_chain, step);
	return (main_chain);
}