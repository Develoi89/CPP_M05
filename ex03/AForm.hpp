#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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

        class GradeOrSignException: public std::runtime_error
        {
            public:
                GradeOrSignException();
        };

        AForm(const int gs, int ge, std::string const n);
        AForm(AForm const &f);
        AForm &operator = (AForm const &f);
        virtual ~AForm() {};
        std::string getName()const;
        bool getSign()const;
        void setSign(bool m);
        int getGs()const;
        int getGe()const;
        void beSigned(Bureaucrat const &b);
        void execute(Bureaucrat const & e)const;
        virtual void exe()const = 0;
};

std::ostream &operator << ( std::ostream & o, const AForm &f );

#endif