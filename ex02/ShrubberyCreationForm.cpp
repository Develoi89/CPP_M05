#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string fname): AForm(145, 137, name), _fname(fname)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & c): AForm(c.getGs(), c.getGe(), c.getName()), _fname(c._fname)
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (ShrubberyCreationForm const & c)
{
    _fname = c._fname;
    setSign(c.getSign());
}

void ShrubberyCreationForm::exe()const
{
    std::ofstream file(_fname);
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
}