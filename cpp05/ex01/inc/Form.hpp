#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <iostream>

class	Bureaucrat;

class Form
{
private:
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class AlreadySignedException : public std::exception
	{
		virtual const char *what() const throw();
	};

	const std::string name_;
	bool is_signed_;
	const int req_sign_;
	const int req_exe_;
public:
	Form();
	Form(std::string, const int, const int);
	Form(const Form &);
	~Form();

	Form &operator=(const Form &cp);

	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getReqSign(void) const;
	int getReqExe(void) const;

	void beSigned(const Bureaucrat &);
};

std::ostream	&operator<<(std::ostream &, const Form &);

#endif