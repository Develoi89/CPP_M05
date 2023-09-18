#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class RobotomyRequestForm: public AForm
{
    private:
        bool _t;
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & c);
        RobotomyRequestForm & operator = (RobotomyRequestForm const & c);
        ~RobotomyRequestForm();

        void exe()const;
};


#endif