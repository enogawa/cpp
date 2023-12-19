#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <cstdlib>
#include <iostream>

int main(void)
{
	try
	{
		ShrubberyCreationForm AForm("garden");
		Bureaucrat bob("Bob", 130);

		std::cout << AForm << std::endl;
		std::cout << bob << std::endl;
		bob.signForm(AForm);
		bob.executeForm(AForm);
		std::cout << "Incrementing " << bob.getName() << "'s grade" << std::endl;
		bob.incrementGrade();
		bob.executeForm(AForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "----------------------------------" << std::endl;
	try
	{
		RobotomyRequestForm AForm("target2");
		Bureaucrat jim("Jim", 30);

		jim.signForm(AForm);
		jim.executeForm(AForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "----------------------------------" << std::endl;
	try
	{
		PresidentialPardonForm AForm("target3");
		Bureaucrat tom("Tom", 2);

		tom.signForm(AForm);
		tom.executeForm(AForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
