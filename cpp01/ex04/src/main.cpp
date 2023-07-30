#include <iostream>
#include <fstream>
#include "../inc/ReplaceStr.hpp"

int main(int argc, char const **argv)
{
	if (argc != 4)
	{
		std::cout << "[usage]: ./replace filename s1 s2" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::ifstream in_file(filename);
	if (!in_file.is_open())
	{
		std::cout << "could not open file" << std::endl;
		return (1);
	}

	std::ofstream out_file(filename + ".replace");
	if (!out_file.is_open())
	{
		std::cout << "could nou open file" << std::endl;
		in_file.close();
		return (1);
	}

	ReplaceStr replace_str(argv[2], argv[3]);
	replace_str.replace(in_file, out_file);
	in_file.close();
	out_file.close();
	return 0;
}