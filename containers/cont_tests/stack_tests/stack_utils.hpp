#ifndef STACK_UTILS_HPP
#define STACK_UTILS_HPP

#include "../testEqual.hpp"
#include "../../stack.hpp"
#include <stack>


template <class T>
std::string equalContent(
    std::stack<T> stl_stack,
    ft::stack<T> ft_stack
)
{
    while (42)
    {
        if (stl_stack.size() == 0 || ft_stack.size() == 0)
            break;
        if (ft_stack.top() != stl_stack.top())
            return ("✘");
        ft_stack.pop();
        stl_stack.pop();
    }
    return ("✔");
}

template <class T>
bool showInfoStack(
    std::stack<T> stl_stack,
    ft::stack<T> ft_stack
)
{
    std::string stl_empty = ((stl_stack.empty() == 1) ? "true" : "false");
    size_t stl_size = stl_stack.size();

    std::string ft_empty = ((ft_stack.empty() == 1) ? "true" : "false");
    size_t ft_size = ft_stack.size();

    bool empty = equalbool(ft_empty, stl_empty);
    bool size = equalbool(ft_size, stl_size);
    std::string content = equalContent(stl_stack, ft_stack);
    
    std::cout << "\n══════════════════════════════════════════════════════════════\n";
    std::cout << "stacks attributes : \n";
    std::cout << "STL : \n";
    std::cout << "Empty       : " << stl_empty  << std::endl;
    std::cout << "Size        : " << stl_size  << std::endl;
    std::cout << "Content     : [";

    while (42)
    {
        if (stl_stack.size() == 0)
            break;
        std::cout << stl_stack.top();
        stl_stack.pop();
        if (stl_stack.size() != 0)
            std::cout << ", ";
    }

    std::cout << "]\n";

    std::cout << std::endl;

    std::cout << "FT : \n";
    std::cout << "Empty    [" << equal(ft_empty, stl_empty) << "]: " << ft_empty  << std::endl;
    std::cout << "Size     [" << equal(ft_size, stl_size) << "]: " << ft_size  << std::endl;

    std::cout << "Content  [" << content << "]: [";

    while (42)
    {
        if (ft_stack.size() == 0)
            break;
        std::cout << ft_stack.top();
        ft_stack.pop();
        if (ft_stack.size() != 0)
            std::cout << ", ";
    }
    std::cout << "]\n";

    std::cout << "══════════════════════════════════════════════════════════════\n";

    if (empty == false)
        return (false);
    else if (size == false)
        return (false);
    else if (content == "✘")
        return (false);
    return (true);
};

void stack_Default_Constructor();
void stack_Empty_true();
void stack_Empty_false();
void stack_Size();
void stack_top();
void stack_Push();
void stack_Pop();
void stack_operatorEqualTrue();
void stackOperatorSmallerTrue();
void stackOperatorNotEqualFalse();
void stackOperatorMoreTrue();

#endif