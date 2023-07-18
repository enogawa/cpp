#include <iostream>
#include "../inc/phone_book.hpp"
#include "../inc/contact.hpp"

Contact::Contact()
{
	index = 0;
}

Contact::~Contact()
{
}

std::string Contact::get_name(int i)
{
	if (i == FirstName)
		return ("First Name");
	else if (i == LastName)
		return ("Last Name");
	else if (i == NickName)
		return ("Nick Name");
	else if (i == PhoneNumber)
		return ("Phone number");
	else if (i == DarkestSecret)
		return ("Darkest secret");
	else
		return (NULL);
}

void	Contact::get_info(int idx)
{
	int i = 0;
	index = idx + 1;

	while (5 > i)
	{
		std::cout << get_name(i) << ": ";
		std::cin >> info[i];
		if (std::cin.eof())
			exit(1);
		i++;
	}
}

int		Contact::get_idx()
{
	return (index);
}

void	Contact::put_info_all(void)
{
	int i = 0;

	while (i != 5)
	{
		std::cout << get_name(i) << "; ";
		std::cout << info[i] << std::endl;
		i++;
	}
}

std::string Contact::check_len(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::put_info(void)
{
	std::cout << "|" << "     " << index;
	std::cout << "|" << "     " << check_len(info[FirstName]);
	std::cout << "|" << "     " << check_len(info[LastName]);
	std::cout << "|" << "     " << check_len(info[NickName])
			<< "|"<< std::endl;
}