#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class	AForm;

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
	void	signForm(AForm &) const;
	void	executeForm(AForm const &);
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif