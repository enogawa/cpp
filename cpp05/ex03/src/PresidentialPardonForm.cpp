#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5), target_(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	(void)other;
	return *this;
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return this->target_;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (isSigned(executor))
		std::cout << "Zaphod Beeblebrox forgave " << this->target_ << "." << std::endl;
}
