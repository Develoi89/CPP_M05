#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:

        std::string const   _name;
        int                 _grade;

    public:

        class GradeTooHighException: public std::runtime_error
        {
            public: 
                GradeTooHighException();
        };

        class GradeTooLowException: public std::runtime_error
        {
            public:
                GradeTooLowException();
        };

        Bureaucrat(int g, std::string const name);
        ~Bureaucrat();

        const std::string getName()const;
        int getGrade()const;
        void upGrade();
        void downGrade();
        void signForm(Form* s);
};

std::ostream &operator << ( std::ostream & o, const Bureaucrat &b );

#endif