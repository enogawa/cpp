#include <iostream>
#include "../inc/phone_book.hpp"
#include "../inc/contact.hpp"

PhoneBook::PhoneBook(): index(0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add(void)
{
	contact[index % 8].get_info(index % 8);
	index++;
}

bool isNumeric(std::string const &str)
{
	return !str.empty() && str.find_first_not_of("0123456789") == std::string::npos;
}

void	PhoneBook::search(void)
{
	int i = 0;
	std::string input;
	int idx;

	if (index == 0)
	{
		std::cout << "empty\n";
		return ;
	}
	while (index > i && 8 > i)
	{
		contact[i].put_info();
		i++;
	}
	while (!isNumeric(input))
	{
		std::cout << "index; ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
	}
	idx = std::atoi(input.c_str());
	i = 0;
	while (i < 8)
	{
		if (idx == contact[i].get_idx())
		{
			contact[i].put_info_all();
			return ;
		}
		i++;
	}
}