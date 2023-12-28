#include <../inc/TypeConvert.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 2)
		TypeConvert::converter(argv[1]);
	else
		std::cerr << "[Usage] ./convert [numeric or character value]" << std::endl;
	return 0;
}