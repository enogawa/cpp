#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <string>
#include <stack>

class RPN
{
private:
	std::stack<double>	stk;
public:
	void	parse(std::string const &str);
	void	cal(char c);
};

#endif