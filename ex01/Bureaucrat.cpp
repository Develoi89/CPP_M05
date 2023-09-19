#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::runtime_error("grade too high, class not created or upgraded."){}
Bureaucrat::GradeTooLowException::GradeTooLowException() : std::runtime_error("grade too low, class not created or downgraded."){}

Bureaucrat::Bureaucrat(int g, std::string const name): _name(name)
{
    if(g > 0 && g < 151)
        _grade = g;
    else if(g < 1)
    {
        throw GradeTooLowException();
    }
    else if(g > 150)
    {
        throw GradeTooHighException();
    }
    std::cout << "Bureaucrat " << getName() << " created." << std::endl;
}

const std::string Bureaucrat::getName()const
{
    return _name;
}

int Bureaucrat::getGrade()const
{
    return _grade;
}

void Bureaucrat::upGrade()
{
    _grade++;
    if(_grade > 150)
    {
        std::cout << this->_name;
        throw GradeTooHighException();
    }
}

void Bureaucrat::downGrade()
{
    _grade--;
    if(_grade < 1)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << getName() << " destroyed." << std::endl;
}

void Bureaucrat::signForm(Form *s)
{
    if(s->getSign() == false)
    {
        s->beSigned(*this);
        std::cout << _name << " signed " << s->getName() << "." << std::endl;
    }
    else
        std::cout << _name << " couldn't sign " << s->getName() << " because the Form its already signed." << std::endl;
}

std::ostream &operator << ( std::ostream & o, const Bureaucrat&b )
{
    o << b.getName();
    o << " bureaucrat grade " << b.getGrade() << "." << std::endl;
    return (o);
}