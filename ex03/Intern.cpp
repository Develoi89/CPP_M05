#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern " << "created." << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern was destroyed." << std::endl;
}

AForm* Intern::newShrubbery(std::string target)
{
    AForm *I = new ShrubberyCreationForm(target);
    return I;
}
AForm* Intern::newRobo(std::string target)
{
    AForm *I = new RobotomyRequestForm(target);
    return I; 
}
AForm* Intern::newPresi(std::string target)
{
    AForm *I = new PresidentialPardonForm(target);
    return I;
}

AForm * Intern::makeForm(std::string nameForm, std::string target)
{
    std::string	s[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*p[3])(std::string) = {&Intern::newShrubbery, &Intern::newRobo, &Intern::newPresi};
	int i = 0;

	while (i < 4 && s[i].compare(nameForm) != 0)
		i++;
	if (i < 3)
	{
		std::cout << "Intern creates " << s[i] << std::endl;
		return((this->*p[i])(target));
	}
	else
		std::cout << nameForm << " is not a valid name for a form!" << std::endl;
	return (NULL);
}