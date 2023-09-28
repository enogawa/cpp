#include <../inc/Bureaucrat.hpp>
#include <../inc/ShrubberyCreationForm.hpp>
#include <../inc/RobotomyRequestForm.hpp>
#include <../inc/PresidentialPardonForm.hpp>
#include <../inc/Intern.hpp>
#include <../inc/AForm.hpp>
#include <cstdlib>
#include <iostream>

int main(void)
{
	try
	{
		std::cout << "## TEST 1 ##" << std::endl;

		Intern intern;

		intern.makeForm("", "me");
		intern.makeForm("abdsfsd", "me");
		intern.makeForm("creation shrubbery", "home");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n## TEST 2 ##\n" << std::endl;
		std::cout << "---------------robotomy test--------------" << std::endl;
		Intern intern;
		Bureaucrat bureaucrate("Steve", 1);
		AForm *Aform;

		Aform = intern.makeForm("robotomy request", "eiki");
		bureaucrate.signForm(*Aform);
		bureaucrate.executeForm(*Aform);
		delete Aform;

		std::cout << "\n--------------presidential test---------------" << std::endl;
		Aform = intern.makeForm("presidential pardon", "eiki");
		bureaucrate.signForm(*Aform);
		bureaucrate.executeForm(*Aform);
		delete Aform;

		std::cout << "\n-------------shrubbery test----------------" << std::endl;
		Aform = intern.makeForm("shrubbery creation", "eiki");
		bureaucrate.signForm(*Aform);
		bureaucrate.executeForm(*Aform);
		delete Aform;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
