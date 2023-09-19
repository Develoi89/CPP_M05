#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
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
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        AForm *A = new RobotomyRequestForm("prueba2");
        Bureaucrat B(150, "me");
        Bureaucrat C(1, "you");
        try
        {
            B.signForm(A);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            C.signForm(A);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        B.executeForm(*A);
        C.executeForm(*A);
        C.executeForm(*A);
        C.executeForm(*A);
        C.executeForm(*A);
        delete A;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        AForm *A = new PresidentialPardonForm("prueba3");
        Bureaucrat B(150, "me");
        Bureaucrat C(1, "you");
        try
        {
            B.signForm(A);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            C.signForm(A);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        B.executeForm(*A);
        C.executeForm(*A);
        delete A;
    }
    return 0;
}
