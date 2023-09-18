#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(145, 137, target), _target(target)
{
    std::cout << "ShrubberyForm with target " << _target << " created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & c): AForm(c.getGs(), c.getGe(), c.getName()), _target(c._target)
{
    std::cout << "ShrubberyForm with target " << _target << " created from ." << c.getName() << std::endl; 
}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (ShrubberyCreationForm const & c)
{
    _target = c._target;
    setSign(c.getSign());
    return *this;
}

void ShrubberyCreationForm::exe()const
{
    std::ofstream file(_target);
    if (file.is_open())
    {
    file << "      *            *            *      " << std::endl;
    file << "     ***          ***          ***     " << std::endl;
    file << "    *****        *****        *****    " << std::endl;
    file << "   *******      *******      *******   " << std::endl;
    file << "  *********    *********    *********  " << std::endl;
    file << " ***********  ***********  *********** " << std::endl;
    file << "     |||          |||          |||     " << std::endl;
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyForm with target " << _target << " was destroyed." << std::endl;
}
