#ifndef MERGEME_HPP
#define MERGEME_HPP

#include <iostream>
#include <cstddef>
#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>

std::vector<int>	mergeInsertionSort(std::vector<int> vec, std::size_t step);
std::list<int>	mergeInsertionSort(std::list<int> lst, std::size_t step);

#endif