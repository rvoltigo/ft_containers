#include "test.hpp"

bool printBoolResult(bool stl_bool, bool ft_bool)
{
    std::cout << "\nBool result : \n";
    std::cout << " - STL : " << (stl_bool ? "true" : "false") << std::endl;
    std::cout << " - FT  : " << (ft_bool ? "true" : "false") << std::endl;

    return (stl_bool == ft_bool);
}