#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

class Intern
{
    public:
        Intern();
        ~Intern();

        AForm*	newShrubbery( std::string target );
	    AForm*	newPresi( std::string target );
	    AForm*	newRobo( std::string target );
        AForm *makeForm(std::string nameForm, std::string target);
};


#endif