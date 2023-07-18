#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact
{
private:
	std::string		info[5];
	int	index;
	enum
	{
		FirstName,
		LastName,
		NickName,
		PhoneNumber,
		DarkestSecret
	};

public:
	Contact();
	~Contact();
	void	get_info(int index);
	void	put_info(void);
	void	put_info_all(void);
	int		get_idx();
	std::string check_len(std::string str);
	std::string	get_name(int i);
};

#endif