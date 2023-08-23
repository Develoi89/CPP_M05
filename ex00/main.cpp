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

    try
    {
        Bureaucrat First(150, "first");
        std::cout << First;
        std::cout << "upgrading First bureaucrat." << std::endl;
        First.upGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}