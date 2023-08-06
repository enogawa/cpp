#ifndef REPLACE_STR_HPP
#define REPLACE_STR_HPP

#include <iostream>
#include <fstream>
#include <string>

class ReplaceStr
{
private:
	std::string _target;
	std::string _new_word;
public:
	ReplaceStr(std::string, std::string);
	ReplaceStr();
	~ReplaceStr();
	void	replace(std::ifstream &in_file, std::ofstream &out_file);
};

#endif
