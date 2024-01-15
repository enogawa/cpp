#include "../inc/PmergeMe.hpp"
#include <random>
#include <algorithm>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "input must be at least 2!" << std::endl;
		return (1);
	}
	argv++;
	std::vector<int>	vec(argc - 1);
	for(size_t i = 0; i < vec.size(); i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (!std::isdigit(argv[i][j]))
			{
				std::cout << "input must be positive integer!" << std::endl;
				return (1);
			}
		}
		std::istringstream iss(argv[i]);
		double num;
		iss >> num;
		if (iss.fail())
			return (1);
		if (num > INT_MAX)
		{
			std::cout << "Do not input over INT_MAX!" << std::endl;
			return (1);
		}
		std::istringstream iss_tmp(argv[i]);
		int tmp;
		iss_tmp >> tmp;
		if (iss_tmp.fail())
		{
			std::cout << "Do not input over INT_MAX!" << std::endl;
			return (1);
		}
		std::vector<int>::iterator ite = std::find(vec.begin(), vec.end(), tmp);
		if (ite != vec.end())
		{
			std::cout << "Do not input same number! [" << *ite << "]" << std::endl;
			return (1);
		}
		vec[i] = tmp;
		if (vec[i] <= 0)
		{
			std::cout << "input must be positive integer!" << std::endl;
			return (1);
		}
	}
	std::cout << "-------vector sort-------" << std::endl;
	std::cout << "before: ";
	for(size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	clock_t	sort_start;
	clock_t	sort_end;
	sort_start = std::clock();
	vec = mergeInsertionSort(vec, 1);
	sort_end = std::clock();
	std::cout << std::endl << "after: ";
	for(size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	double sort_time = static_cast<double>(sort_end - sort_start) / CLOCKS_PER_SEC;
	double microsec = sort_time * 1e6;
	std::cout << std::endl << std::endl << "Time to process a range of " << vec.size() <<
	" elements with [std::vector] : " << std::fixed << std::setprecision(5) << microsec << " us" << std::endl;

	std::list<int> lst;
	for (int i = 0; i < argc - 1; ++i)
	{
		std::istringstream iss_tmp(argv[i]);
		int tmp;
		iss_tmp >> tmp;
		if (iss_tmp.fail())
		{
			std::cout << "invalid number!" << std::endl;
			return (1);
		}
		lst.push_back(tmp);
	}
	std::cout << std::endl << std::endl << "-------list sort-------" << std::endl;
	std::cout << "before: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	sort_start = std::clock();
	lst = mergeInsertionSort(lst, 1);
	sort_end = std::clock();
	std::cout << std::endl << "after: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << " ";
	}
	sort_time = static_cast<double>(sort_end - sort_start) / CLOCKS_PER_SEC;
	microsec = sort_time * 1e6;
	std::cout << std::endl << std::endl << "Time to process a range of " << vec.size() <<
	" elements with [std::list] : " << std::fixed << std::setprecision(5) << microsec << " us" << std::endl;
	return 0;
}