#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm: public AForm
{
    private:
        std::string _fname;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string name, std::string fname);
        ShrubberyCreationForm(ShrubberyCreationForm const & c);
        ShrubberyCreationForm & operator = (ShrubberyCreationForm const & c);
        ~ShrubberyCreationForm();

        void exe()const;
};


#endif