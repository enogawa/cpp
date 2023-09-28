#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main(void)
{
	try
	{
		Form formA("formA", 141, 100);
		Bureaucrat A("A", 130);
		Bureaucrat B("B", 101);

		std::cout << formA << std::endl;
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << "-------------------------\n";
		A.signForm(formA);
		std::cout << formA << std::endl;
		std::cout << "-------------------------\n";
		B.signForm(formA);
		std::cout << formA << std::endl;
		std::cout << B << std::endl;
	}
	catch(const std::exception& error)
	{
		std::cerr << error.what() << '\n';
	}
	return 0;
}