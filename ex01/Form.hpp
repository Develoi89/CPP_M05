#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
    private:
        int const           _gs;
        int const           _ge;
        std::string const   _name;
        bool                _signed;

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
        Form(const int gs, int ge, std::string const n);
        Form(Form const &f);
        Form &operator = (Form const &f);
        ~Form();
        std::string getName()const;
        bool getSign()const;
        int getGs()const;
        int getGe()const;
        void beSigned(Bureaucrat const &b);
};

std::ostream &operator << ( std::ostream & o, const Form &f );

#endif