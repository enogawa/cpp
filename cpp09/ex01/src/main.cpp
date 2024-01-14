#include "../inc/RPN.hpp"

void	RPN::cal(char c)
{
	if (this->stk.size() < 2)
		throw	std::invalid_argument("ERROR: invalid RPN format");
	int n2 = this->stk.top();
	this->stk.pop();
	int n1 = this->stk.top();
	this->stk.pop();
	if (c == '*')
		stk.push(n1 * n2);
	else if (c == '/')
		stk.push(n1 / n2);
	else if (c == '+')
		stk.push(n1 + n2);
	else if (c == '-')
		stk.push(n1 - n2);
}

void	RPN::parse(std::string const &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (i % 2 == 0)
		{
			if ('0' <= str[i] && str[i] <= '9')
				this->stk.push(str[i] - '0');
			else if(str[i] == '*')
				this->cal('*');
			else if(str[i] == '/')
				this->cal('/');
			else if(str[i] == '+')
				this->cal('+');
			else if(str[i] == '-')
				this->cal('-');
			else
				throw	std::invalid_argument("ERROR: invalid arg");
		}
		else
		{
			if (str[i] != ' ')
				throw	std::invalid_argument("ERROR: should separated by space");
		}
	}
	if (stk.size() == 1)
		std::cout << stk.top() << std::endl;
	else
		throw	std::invalid_argument("ERROR: stk.size() should be one");
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN <expression>" << std::endl;
		return 1;
	}
	RPN	rpn;
	try
	{
		rpn.parse(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return(0);
}