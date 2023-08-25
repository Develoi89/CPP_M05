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

void Bureaucrat::signForm(bool s, std::string const n)const
{
    if(s == true)
        std::cout << _name << " signed " << n << "." << std::endl;
    else
        std::cout << _name << " couldn’t sign " << n << " because the grade's bureaucrat is not enough." << std::endl;
}

void Bureaucrat::executeForm(AForm const & form)const
{
    try
    {
        std::cout << getName() << " trying to execute " << form.getName() << std::endl;
        form.execute(*this);
        std::cout << getName() << " exacuted " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

std::ostream &operator << ( std::ostream & o, const Bureaucrat&b )
{
    o << b.getName();
    o << " bureaucrat grade " << b.getGrade() << "." << std::endl;
    return (o);
}