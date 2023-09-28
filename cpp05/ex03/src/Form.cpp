#include "../inc/AForm.hpp"

AForm::AForm() : name_("unknown"), is_signed_(false), req_sign_(150), req_exe_(1)
{

}

AForm::AForm(std::string name, const int req_sign, const int req_exe): name_(name), is_signed_(false), req_sign_(req_sign), req_exe_(req_exe)
{
	if (req_sign > 150 || req_exe > 150)
		throw(AForm::GradeTooLowException());
	else if (req_sign < 1 || req_exe < 1)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(const AForm &cp) : req_sign_(cp.req_sign_), req_exe_(cp.req_exe_)
{
	*this = cp;
}

AForm::~AForm()
{

}

AForm	&AForm::operator=(const AForm &cp)
{
	if (this != &cp)
	{
		*this = cp;
	}
	return (*this);
}

std::string AForm::getName(void) const
{
	return name_;
}

bool AForm::getIsSigned(void) const
{
	return is_signed_;
}

int AForm::getReqSign(void) const
{
	return req_sign_;
}

int AForm::getReqExe(void) const
{
	return req_exe_;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("[Exception] Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("[Exception] Grade is too low");
}

const char *AForm::NotSignedException::what() const throw()
{
	return "[Exception] is_signed not true";
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return "this form is already signed";
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > req_sign_)
		throw (AForm::GradeTooLowException());
	else if (is_signed_ == true)
		throw(AForm::AlreadySignedException());
	is_signed_ = true;
}

bool AForm::isSigned(const Bureaucrat &exe) const
{
	if (getIsSigned() == false)
		throw(AForm::NotSignedException());
	else if (exe.getGrade() > getReqExe())
		throw(AForm::GradeTooLowException());
	return true;
}


std::ostream &operator<<(std::ostream &stream, const AForm &F)
{
	stream << F.getName() << " is signed " << F.getIsSigned() << " | req_sign " << F.getReqSign() << " | req_exe " << F.getReqExe();

	return stream;
}



