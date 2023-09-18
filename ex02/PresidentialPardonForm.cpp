#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(25, 5, target), _target(target)
{
    std::cout << "PresidentialPardonForm with target " << _target << " created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & c): AForm(c.getGs(), c.getGe(), c.getName()), _target(c._target)
{
    std::cout << "PresidentialPardonForm with target " << _target << " created from ." << c.getName() << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator = (PresidentialPardonForm const & c)
{
    _target = c._target;
    setSign(c.getSign());
    return *this;
}

void PresidentialPardonForm::exe()const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm with target " << _target << " was destroyed." << std::endl;
}