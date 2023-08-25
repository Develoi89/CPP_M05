#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

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
        void signForm(bool s, std::string const n)const;
        void executeForm(AForm const & form)const;
};

std::ostream &operator << ( std::ostream & o, const Bureaucrat &b );

#endif