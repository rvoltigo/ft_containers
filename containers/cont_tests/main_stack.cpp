#include <iostream>
#include "head.hpp"

int main()
{
    stack_Default_Constructor();
    std::cin.ignore();
    stack_Empty_true();
    std::cin.ignore();
    stack_Empty_false();
    std::cin.ignore();
    stack_Size();
    std::cin.ignore();
    stack_top();
    std::cin.ignore();
    stack_Push();
    std::cin.ignore();
    stack_Pop();
    std::cin.ignore();
    stack_operatorEqualTrue();
    std::cin.ignore();
    stackOperatorSmallerTrue();
    std::cin.ignore();
    stackOperatorNotEqualFalse();
    std::cin.ignore();
    stackOperatorMoreTrue();
    std::cin.ignore();
    return (0);
}