#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name_("unknown"), grade_(1)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade): name_(name), grade_(grade)
{
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &cp)
{
	*this = cp;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cp)
{
	this->grade_ = cp.grade_;

	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &instance)
{
	stream << instance.getName() << ", bureaucrat grade" << instance.getGrade() << ".";

	return stream;
}

std::string Bureaucrat::getName(void) const
{
	return this->name_;
}

int Bureaucrat::getGrade(void) const
{
	return this->grade_;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "[Exception] Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "[Exception] Grade is too low";
}

void Bureaucrat::incrementGrade(void)
{
	grade_--;
	if (grade_ > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade_ < 1)
		throw(Bureaucrat::GradeTooHighException());
}

void Bureaucrat::decrementGrade(void)
{
	grade_++;
	if (grade_ > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade_ < 1)
		throw(Bureaucrat::GradeTooHighException());
}

void Bureaucrat::signForm(AForm &F) const
{
	try
	{
		F.beSigned(*this);
		std::cout << this->getName() << " signed " << F.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << F.getName() << " because "  << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << "'" << this->getName() << " executed " << form.getName() << "'." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "'" << this->getName() << "' could not execute form '" << form.getName() << "': " << e.what() << std::endl;
	}
}
