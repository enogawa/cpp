#include "../inc/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>

bool	checkValidDay(int year, int month, int day)
{
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return (1 <= day && day <= 31);
		case 2:
			if ((year % 400 == 0) || (year % 4 == 0 && year % 100) )
				return (1 <= day && day <= 29);
			else
				return (1 <= day && day <= 28);
		case 4:
		case 6:
		case 9:
		case 11:
			return (1 <= day && day <= 30);
		default:
			return (false);
	}
}

bool	checkDateFormat(std::string const date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < 4; i++)
	{
		std::string tmp = date.substr(0, 4);
		if (!std::isdigit(tmp[i]))
			return (false);
	}
	std::istringstream iss_year(date.substr(0, 4));
	int year;
	iss_year >> year;
	if (iss_year.fail())
		throw	std::invalid_argument("ERROR: invalid value format!");
	for (size_t i = 0; i < 2; i++)
	{
		std::string tmp = date.substr(5, 2);
		if (!std::isdigit(tmp[i]))
			return (false);
	}
	std::istringstream iss_month(date.substr(5, 2));
	int month;
	iss_month >> month;
	if (iss_month.fail())
		throw	std::invalid_argument("ERROR: invalid value format!");
	for (size_t i = 0; i < 2; i++)
	{
		std::string tmp = date.substr(8, 2);
		if (!std::isdigit(tmp[i]))
			return (false);
	}
	std::istringstream iss_day(date.substr(8, 2));
	int day;
	iss_day >> day;
	if (iss_day.fail())
		throw	std::invalid_argument("ERROR: invalid value format!");
	return (checkValidDay(year, month, day));
}

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
	if (line.find("date | value") == std::string::npos)
	{
		std::cerr << "Error: input.txt must start with [date | value] !" << std::endl;
		return 1;
	}
	size_t i = 0;
	while(std::getline(ifs_input, line))
	{
		try
		{
			std::cout << "----------"<< std::endl;
			size_t	n = line.find(" | ");
			if (n == std::string::npos)
				throw	std::invalid_argument("ERROR: invalid format!");
			std::string	date = line.substr(0, n);
			if (!checkDateFormat(date))
				throw	std::invalid_argument("ERROR: invalid date format!");
			std::istringstream iss(line.substr(n+3));
			double value;
			iss >> value;
			if (iss.fail())
				throw	std::invalid_argument("ERROR: invalid value format!");
			if (value < 0)
				throw	std::invalid_argument("ERROR: not a positive nummber!");
			else if(value > 1000)
				throw	std::invalid_argument("ERROR: too large number!");
			double	db_rate = db.search(date);
			double	btc_value = db_rate * value;
			std::cout << date << " => " << value << " = " << btc_value << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		i++;
	}
	if (i == 0)
	{
		std::cout << "No data in the input.txt!" << std::endl;
		return (1);
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
		std::istringstream iss_data(line_data.substr(n_data+1));
		double rate;
		iss_data >> rate;
		if (iss_data.fail())
			throw	std::invalid_argument("ERROR: invalid rate format!");
		mp.insert(std::make_pair(date, rate));
	}
}

double	database::search(std::string	data)
{
	std::map<std::string, double>::iterator iter = mp.lower_bound(data);
	if (data < mp.begin()->first)
		throw	std::invalid_argument("Error: no date!");
	if (data != iter->first)
		return (--iter)->second;
	return iter->second;
}