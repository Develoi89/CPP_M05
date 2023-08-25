#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::GradeTooHighException::GradeTooHighException() : std::runtime_error("Formgrade too high, Form not created or signed."){}
AForm::GradeTooLowException::GradeTooLowException() : std::runtime_error("Formgrade too low, Form not created."){}
AForm::GradeOrSignException::GradeOrSignException() : std::runtime_error("Bureaucratgrade too low or Form not signed."){}

AForm::AForm(const int  gs, const int ge, std::string const n): _gs(gs), _ge(ge), _name(n), _signed(false)
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

void AForm::beSigned(Bureaucrat const &b)
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
        throw GradeTooHighException();
}

void AForm::execute(Bureaucrat const & e)const
{
    if (e.getGrade() < _ge && _signed == true)
        exe();
    else
        throw GradeOrSignException();
}

AForm::AForm(AForm const &f): _gs(f._gs), _ge(f._ge), _name(f._name), _signed(f._signed)
{
}

AForm &AForm::operator =(AForm const& f)
{
    _signed = f._signed;
    return *this;
}

bool AForm::getSign()const
{
    return _signed;
}

void AForm::setSign(bool m)
{
    _signed = m;
}

int AForm::getGs()const
{
    return _gs;
}

int AForm::getGe()const
{
    return _ge;
}

AForm::~AForm()
{
    std::cout << "Form " << getName() << " was destroyed." << std::endl;
}

std::string AForm::getName()const
{
    return _name;
}

std::ostream &operator << ( std::ostream & o, const AForm &f )
{
    o << f.getName() << " form has " << f.getGs() << " grade to sign, "<< f.getGe() << " grade to execute." << std::endl;
    if (f.getSign() == true)
        o << "And is signed." << std::endl;
    else
        o << "And is unsigned." << std::endl;
    return o;
}