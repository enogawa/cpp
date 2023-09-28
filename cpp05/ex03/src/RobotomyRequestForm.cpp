#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	(void)other;
	return *this;
}

std::string RobotomyRequestForm::getTarget(void) const {
	return this->target_;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (isSigned(executor))
	{
		std::cout << "Making some drilling noises" << std::endl;
		srand(time(NULL));
		if (rand() % 2 == 0)
			std::cout << target_ << " has been robotomized" << std::endl;
		else
			std::cout << "robotomy has failed !" << std::endl;
	}
}
