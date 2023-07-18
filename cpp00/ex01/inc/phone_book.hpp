#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(); 
		~PhoneBook();
		void add();
		void search();
	private:
		Contact contact[8];
		int index;
};
#endif