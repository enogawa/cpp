#include "../inc/Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat A("eiki", 2);
		std::cout << A << std::endl;
		std::cout << A.getName() << std::endl;
		std::cout << A.getGrade() << std::endl;
		std::cout << "--------------------------------\n";
		A.incrementGrade();
		std::cout << A << std::endl;
		A.decrementGrade();
		std::cout << A << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "--------------------------------\n";
	}
	return 0;
}
