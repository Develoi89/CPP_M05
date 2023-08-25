#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string fname): AForm(145, 137, name), _fname(fname)
{
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