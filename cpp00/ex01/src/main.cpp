#include <iostream>
#include "../inc/phone_book.hpp"
#include "../inc/contact.hpp"

int main(void)
{
	std::string	line;
	PhoneBook	phone;

	while (42)
	{
		std::cout << "input command# ";
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
	}
}