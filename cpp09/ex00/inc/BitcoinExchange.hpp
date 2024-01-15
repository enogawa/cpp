#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class database
{
	public:
		database(std::string file_name);
		double	search(std::string data);
	private:
		std::map<std::string, double> mp;
};


#endif

