#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(72, 45, target), _t(false), _target(target)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << "RobotomyRequestForm with target " << _target << " created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & c): AForm(c.getGs(), c.getGe(), c.getName()), _t(false), _target(c._target)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << "RobotomyRequestForm with target " << _target << " created from ." << c.getName() << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator = (RobotomyRequestForm const & c)
{
    _target = c._target;
    setSign(c.getSign());
    return *this;
}

void RobotomyRequestForm::exe()const
{
    int random = std::rand() % 2;
    if(random)
        std::cout << "RRRrrrrrRRRRrRRrRRR " << _target << " has been robotomized" << std::endl;
    else
        std::cout << "RRRrrrrrRRRRrRRrRRR " << _target << " robotomy failed" << std::endl;

}

RobotomyRequestForm::~RobotomyRequestForm()
{
}