#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
#include <iostream>

class	Bureaucrat;

class AForm
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

	class NotSignedException : public std::exception
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
	AForm();
	AForm(std::string, const int, const int);
	AForm(const AForm &);
	~AForm();

	AForm &operator=(const AForm &cp);

	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getReqSign(void) const;
	int getReqExe(void) const;
	virtual void execute(Bureaucrat const &executor) const = 0;

	void beSigned(const Bureaucrat &);
	bool isSigned(const Bureaucrat &) const ;
};

std::ostream	&operator<<(std::ostream &, const AForm &);

#endif