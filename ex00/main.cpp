#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat First(150, "first");
        std::cout << First;
        Bureaucrat Second(160, "second");
        std::cout << Second << std::endl;
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
    return 0;
}