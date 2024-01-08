#include "../inc/array.hpp"
#include <iostream>

int	main()
{
	try
	{
		{
			Array<int> a(5);
			for (size_t i = 0; i < a.size(); i++)
				a[i] = i;
			for (size_t i = 0; i < a.size(); i++)
				std::cout << a[i];
			std::cout << std::endl << "-----------------------" << std::endl;
			Array<int> b(a);
			for (size_t i = 0; i < b.size(); i++)
				std::cout << b[i];
			std::cout << std::endl << "-----------------------" << std::endl;
			Array<int> c(5);
			c = a;
			for (size_t i = 0; i < c.size(); i++)
				std::cout << c[i];
			std::cout << std::endl << "-----------------------" << std::endl;
			std::cout << a[10] << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}