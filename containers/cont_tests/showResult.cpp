#include "testEqual.hpp"

bool showResult(bool originalStl, bool myFt)
{
    std::cout << "\nBool result : \n";
    std::cout << " - ORIGINAL STL : " << (originalStl ? "TRUE" : "FALSE") << std::endl;
    std::cout << " - MY       FT  : " << (myFt ? "TRUE" : "FALSE") << std::endl;

    return (originalStl == myFt);
}