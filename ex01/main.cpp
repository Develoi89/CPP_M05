#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat First(150, "first");
        std::cout << First;
        Bureaucrat Second(160, "second");
    }
    catch (std::exception & e) 
    {
        std::cout << e.what() << std::endl;
    }
std::cout << std::endl;
std::cout << std::endl;
    try
    {
        Bureaucrat First(1, "first");
        std::cout << First;
        std::cout << "upgrading First bureaucrat." << std::endl;
        First.upGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
std::cout << std::endl;
std::cout << std::endl;
    try
    {
        Bureaucrat First(150, "first");
        std::cout << First;
        std::cout << "downgrading First bureaucrat." << std::endl;
        First.downGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
std::cout << std::endl;
std::cout << std::endl;    
    try
    {
        Bureaucrat First(1, "first");
        Form A(40, 50, "a");
        A.beSigned(First);
        std::cout << A;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
std::cout << std::endl;
std::cout << std::endl;
    try
    {
        Bureaucrat First(60, "first");
        Form A(40, 50, "a");
        std::cout << A;
        A.beSigned(First);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}