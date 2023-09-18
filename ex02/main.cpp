#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    AForm *A = new ShrubberyCreationForm("prueba");
    Bureaucrat B(150, "me");
    Bureaucrat C(1, "you");
    try
    {
        A->beSigned(B);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        A->beSigned(C);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    B.executeForm(*A);
    C.executeForm(*A);
    delete A;
    return 0;
}

