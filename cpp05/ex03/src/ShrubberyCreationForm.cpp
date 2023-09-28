#include <ShrubberyCreationForm.hpp>

const char *ShrubberyCreationForm::asciiTree =
	"		    *\n"
	"		   *-*\n"
	"		  *---*\n"
	"		 *-----*\n"
	"		*-------*\n"
	"	   *---------*\n"
	"		   |||\n";

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Surubbery", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Surubbery", 145, 137), target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	(void)other;
	return *this;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->target_;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (isSigned(executor))
	{
		std::ofstream file((getTarget() + "_shrubbery").c_str());
		if (file.is_open())
		{
			file << asciiTree << std::endl;
			file.close();
		}
		else
			std::cerr << "Unable to open file" << std::endl;
	}
}
