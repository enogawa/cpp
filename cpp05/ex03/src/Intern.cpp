#include <../inc/Intern.hpp>

const std::string Intern::formTypes_[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

int Intern::getFormIdx(std::string &name)
{
	for (size_t i = 0; i < 3; i++)
	{
		if (name == formTypes_[i])
			return i;
	}
	return -1;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *Aform = NULL;
	int idx = getFormIdx(name);
	switch (idx)
	{
	case 0:
		Aform = new PresidentialPardonForm(target);
		break;
	case 1:
		Aform = new RobotomyRequestForm(target);
		break;
	case 2:
		Aform = new ShrubberyCreationForm(target);
		break;
	default:
		std::cout << "Intern is not creates." << std::endl;
		return NULL;
	}
	std::cout << "Intern creates " << name << "." << std::endl;
	return Aform;
}