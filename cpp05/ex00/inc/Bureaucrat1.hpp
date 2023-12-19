# ifndef BUREAUCRAT1_HPP
# define BUREAUCRAT1_HPP

#include <iostream>
#include <exception>

class Bureaucrat1
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

	const std::string name_;
	int grade_;

public:
	Bureaucrat1();
	Bureaucrat1(std::string, int);
	Bureaucrat1(const Bureaucrat1 &cp);
	~Bureaucrat1();
	Bureaucrat1	&operator=(const Bureaucrat1 &cp);

	void	incrementGade();
	void	decrementGrade();
	std::string	getName() const;
	int	getGrade() const;
};

std::ostream &operator<<(std::ostream &, const Bureaucrat1 &);

#endif