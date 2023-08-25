#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target): AForm(72, 45, name), _t(false), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & c): AForm(c.getGs(), c.getGe(), c.getName())
{
}

RobotomyRequestForm & RobotomyRequestForm::operator = (RobotomyRequestForm const & c)
{
    setSign(c.getSign());
}

void RobotomyRequestForm::exe()const
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{
}