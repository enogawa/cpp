#include "../inc/Form.hpp"

Form::Form() : name_("unknown"), is_signed_(false), req_sign_(150), req_exe_(1)
{

}

Form::Form(std::string name, const int req_sign, const int req_exe): name_(name), is_signed_(false), req_sign_(req_sign), req_exe_(req_exe)
{
	if (req_sign > 150 || req_exe > 150)
		throw(Form::GradeTooLowException());
	else if (req_sign < 1 || req_exe < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const Form &cp) : req_sign_(cp.req_sign_), req_exe_(cp.req_exe_)
{
	*this = cp;
}

Form::~Form()
{

}

Form	&Form::operator=(const Form &cp)
{
	if (this != &cp)
	{
		*this = cp;
	}
	return (*this);
}

std::string Form::getName(void) const
{
	return name_;
}

bool Form::getIsSigned(void) const
{
	return is_signed_;
}

int Form::getReqSign(void) const
{
	return req_sign_;
}

int Form::getReqExe(void) const
{
	return req_exe_;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("[Exception] Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("[Exception] Grade is too low");
}

const char *Form::AlreadySignedException::what() const throw()
{
	return "this form is already signed";
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > req_sign_)
		throw (Form::GradeTooLowException());
	else if (is_signed_ == true)
		throw(Form::AlreadySignedException());
	is_signed_ = true;
}


std::ostream &operator<<(std::ostream &stream, const Form &F)
{
	stream << F.getName() << " is signed " << F.getIsSigned() << " | req_sign " << F.getReqSign() << " | req_exe " << F.getReqExe();

	return stream;
}



