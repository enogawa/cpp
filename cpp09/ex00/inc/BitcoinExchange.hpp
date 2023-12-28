#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>

class database
{
	public:
		database(std::string file_name);
		float	search(std::string data);

	private:
		std::map<std::string, float> mp;
	


};


#endif

