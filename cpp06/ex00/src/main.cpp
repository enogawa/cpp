#include <../inc/TypeConvert.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		class TypeConvert type(argv[1]);
		type.converter();
	}
	else
		std::cerr << "[Usage] ./convert [numeric or character value]" << std::endl;
	return 0;
}