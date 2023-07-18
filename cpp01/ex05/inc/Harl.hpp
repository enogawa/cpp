#ifndef HARL_HPP
#define HARL_HPP

#define RED     "\033[31m"
#define RESET   "\033[0m"

#include <string>

class Harl {
private:
	void debug();
	void info();
	void warning();
	void error();

public:
	void complain(std::string level);
};

#endif
