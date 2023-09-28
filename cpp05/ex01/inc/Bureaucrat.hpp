#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class	Form;

class Bureaucrat
{
private:
	class GradeTooHighException : public std::exception {
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	const std::string name_;
	int grade_;

public:
	Bureaucrat();
	Bureaucrat(std::string, int);
	Bureaucrat(const Bureaucrat &cp);
	~Bureaucrat();
	Bureaucrat	&operator=(const Bureaucrat &cp);

	void	incrementGrade();
	void	decrementGrade();
	std::string	getName() const;
	int	getGrade() const;
	void signForm(Form &) const;
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif