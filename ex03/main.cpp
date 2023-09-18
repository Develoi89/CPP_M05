#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern  someRandomIntern;
    AForm*  rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm*  scf;
    scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    AForm*  ppf;
    ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
    AForm*  error;
    error = someRandomIntern.makeForm("error", "Bender");
    return 0;
}
