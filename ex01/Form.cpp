#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::GradeTooHighException::GradeTooHighException() : std::runtime_error("Formgrade too high, Form not created or signed."){}
Form::GradeTooLowException::GradeTooLowException() : std::runtime_error("Formgrade too low, Form not created."){}

Form::Form(const int  gs, const int ge, std::string const n): _gs(gs), _ge(ge), _name(n), _signed(false)
{
    if((gs > 0 && gs < 151) && (ge > 0 && ge < 151))
        std::cout << "Form " << getName() << " created." << std::endl;
    else if(gs < 1 && ge < 1)
    {
        throw GradeTooLowException();
    }
    else if(gs > 150 && ge >150)
    {
        throw GradeTooHighException();
    }
}

void Form::beSigned(Bureaucrat const &b)
{
    std::cout << "Bureaucrat " << b.getName() << " try to sign " << getName() << " Form." << std::endl;
    if (_gs > b.getGrade())
    {
        if(_signed == true)
            std::cout << "its already signed." << std::endl;
        else
        {
            _signed = true;
            b.signForm(getSign(), getName());
        }
    }
    else
    {
        throw GradeTooHighException();
    }
}

Form::Form(Form const &f): _gs(f._gs), _ge(f._ge), _name(f._name), _signed(f._signed)
{
}

Form &Form::operator =(Form const& f)
{
    _signed = f._signed;
    return *this;
}

bool Form::getSign()const
{
    return _signed;
}

int Form::getGs()const
{
    return _gs;
}

int Form::getGe()const
{
    return _ge;
}

Form::~Form()
{
    std::cout << "Form " << getName() << " was destroyed." << std::endl;
}

std::string Form::getName()const
{
    return _name;
}

std::ostream &operator << ( std::ostream & o, const Form &f )
{
    o << f.getName() << " form has " << f.getGs() << " grade to sign, "<< f.getGe() << " grade to execute." << std::endl;
    if (f.getSign() == true)
        o << "And is signed." << std::endl;
    else
        o << "And is unsigned." << std::endl;
    return o;
}