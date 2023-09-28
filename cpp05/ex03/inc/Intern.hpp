#ifndef INTERN_HPP
#define INTERN_HPP

#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

class Intern
{
public:
	Intern();
	Intern(const Intern &);
	~Intern();

	Intern &operator=(const Intern &);

	int getFormIdx(std::string &);
	AForm *makeForm(std::string, std::string);

private:
	static const std::string formTypes_[3];
};

#endif