#include "../inc/Harl.hpp"
#include <iostream>

void Harl::debug() {
	std::cout << RED << "DEBUG" << RESET << ": I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << RED << "INFO" << RESET << ": I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << RED << "WARNING" << RESET << ": I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << RED << "ERROR" << RESET << ": This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	if (level == "DEBUG")
		debug();
	else if (level == "INFO")
		info();
	else if (level == "WARNING")
		warning();
	else if (level == "ERROR")
		error();
}
