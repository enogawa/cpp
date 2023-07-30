#include <iostream>

int main(int argc, char **argv)
{
	int i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" ;
		return 0;
	}
	while (argc > i)
	{
		int j = 0;
		while (argv[i][j])
		{
			std::cout << (char)std::toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	std::cout << "\n";
	return 0;
}