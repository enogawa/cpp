#include "../inc/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: argc must be 2!" << std::endl;
		return 1;
	}
	std::ifstream ifs_data("data.csv");
	std::ifstream ifs_input(argv[1]);
	if (!ifs_data || !ifs_input)
	{
		std::cerr << "Error: no file!" << std::endl;
		return 1;
	}
	database db("data.csv");
	std::string	line;
	std::getline(ifs_input, line);
	while(std::getline(ifs_input, line))
	{
		int	n = line.find("|");
		std::string	data = line.substr(0, n-1);
		float	value = std::stof(line.substr(n+2));
		float	db_rate = db.search(data);
		float	btc_value = db_rate * value;
		std::cout << data << " => " << value << " = " << btc_value << std::endl;
	}
}

database::database(std::string file_name)
{
	std::ifstream ifs_data(file_name);
	std::string	line_data;
	std::getline(ifs_data, line_data);
	while (std::getline(ifs_data, line_data))
	{
		int n_data = line_data.find(",");
		std::string	date = line_data.substr(0, n_data);
		float	rate = std::stof(line_data.substr(n_data+1));
		mp.insert(std::make_pair(date, rate));

	}
}

float	database::search(std::string	data)
{
	std::map<std::string, float>::iterator iter = mp.lower_bound(data);
	if (data < mp.begin()->first)
		throw	std::invalid_argument("Error: no date!");
	if (data != iter->first)
		return (--iter)->second;
	return iter->second;
}