#include <iostream>
#include <fstream>
#include "../inc/ReplaceStr.hpp"

ReplaceStr::ReplaceStr(std::string target, std::string new_word) : _target(target), _new_word(new_word){}

ReplaceStr::ReplaceStr(){}

ReplaceStr::~ReplaceStr(){}

void ReplaceStr::replace(std::ifstream &in_file, std::ofstream &out_file)
{
	std::string	line;
	std::size_t	index = 0;

	while (std::getline(in_file, line))
	{
		while ((index = line.find(_target)) != std::string::npos)
		{
			line.erase(index, _target.length());
			line.insert(index, _new_word);
		}
		out_file << line;
		out_file << std::endl;
	}
}