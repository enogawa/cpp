#include "../inc/PmergeMe.hpp"
#include <random>
#include <algorithm>

int main()
{
	std::vector<int>	vec(3000);
	for(size_t i = 0; i < vec.size(); i++)
		vec[i] = i;
	std::random_device	seed_gen;
	std::mt19937		engine(seed_gen());
	std::shuffle(vec.begin(), vec.end(), engine);
	for(size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	vec = mergeInsertionSort(vec, 1);
	for(size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
		std::cout << std::endl;

	std::list<int> lst;
	for (int i = 0; i < 3000; ++i) {
		lst.push_back(i);
	}
	std::srand(unsigned(std::time(0)));
	std::vector<int> temp(lst.begin(), lst.end());
	std::random_shuffle(temp.begin(), temp.end());
	std::copy(temp.begin(), temp.end(), lst.begin());
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	lst = mergeInsertionSort(lst, 1);
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return 0;
}