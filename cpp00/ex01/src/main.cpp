#include <iostream>
#include "../inc/phone_book.hpp"
#include "../inc/contact.hpp"

int main(void)
{
	std::string	line;
	PhoneBook	phone;
	int i = 1;

	while (42)
	{
		if (i == 1)
		{
			std::cout << "input command# ";
			i = 0;
		}
		std::getline(std::cin, line);
		if (std::cin.eof())
			exit(0);
		else if (line == "ADD")
		{
			phone.add();
		}
		else if (line == "SEARCH")
		{
			phone.search();
		}
		else if (line == "EXIT")
			exit(0);
		else
			std::cout << "input command# ";
	}
}