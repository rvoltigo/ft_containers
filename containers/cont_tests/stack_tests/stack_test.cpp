#include "stack_utils.hpp"

void stack_Default_Constructor()
{
    std::cout<< std::endl << "===================================Default constructor===================================" << std::endl;;
    std::stack<int> stl_default;
    ft::stack<int> ft_default;

    std::cout << ((printStackAttributes(stl_default, ft_default) == true) ? "[OK]" : "[NOP]");
}

void stack_Empty_true()
{
    std::cout<< std::endl << "===================================stack_Empty_true===================================" << std::endl;;
    std::stack<int> stl_empty;
    ft::stack<int> ft_empty;

    std::cout << ((printStackAttributes(stl_empty, ft_empty) == true) ? "[OK]" : "[NOP]");
}

void stack_Empty_false()
{
    std::cout<< std::endl << "===================================stack_Empty_false===================================" << std::endl;;
    std::stack<int> stl_empty;
    ft::stack<int> ft_empty;

    stl_empty.push(42);
    ft_empty.push(42);

    std::cout << ((printStackAttributes(stl_empty, ft_empty) == true) ? "[OK]" : "[NOP]");

}

void stack_Size()
{
    std::cout<< std::endl << "===================================stack_Size===================================" << std::endl;;
    std::stack<int> stl_size;
    ft::stack<int> ft_size;

    for (int i = 0; i < 42; i++)
    {
        stl_size.push(i);
        ft_size.push(i);
    }

    std::cout << ((printStackAttributes(stl_size, ft_size) == true) ? "[OK]" : "[NOP]");
}

void stack_top()
{
    std::cout<< std::endl << "===================================stack_top===================================" << std::endl;;

    std::stack<int> stl_top;
    ft::stack<int> ft_top;

    for (int i = 0; i < 42; i++)
    {
        stl_top.push(i);
        ft_top.push(i);
    }

    std::cout << ((printSingleValue(stl_top.top(), ft_top.top()) == true) ? "[OK]" : "[NOP]");
    
    stl_top.pop();
    ft_top.pop();

    std::cout << ((printSingleValue(stl_top.top(), ft_top.top()) == true) ? "[OK]" : "[NOP]");
}

void stack_Push()
{
    std::cout<< std::endl << "===================================stack_Push===================================" << std::endl;;
    std::stack<int> stl_size;
    ft::stack<int> ft_size;

    for (int i = 0; i < 42; i++)
    {
        stl_size.push(i * 2);
        ft_size.push(i * 2);
    }

    std::cout << ((printStackAttributes(stl_size, ft_size) == true) ? "[OK]" : "[NOP]");

}

void stack_Pop()
{
    std::cout<< std::endl << "===================================stack_Pop===================================" << std::endl;;
    
    std::stack<int> stl_pop;
    ft::stack<int> ft_pop;

    for (int i = 0; i < 42; i++)
    {
        stl_pop.push(i);
        ft_pop.push(i);
    }

    std::cout << ((printStackAttributes(stl_pop, ft_pop) == true) ? "[OK]" : "[NOP]");
    
    stl_pop.pop();
    ft_pop.pop();

    std::cout << ((printStackAttributes(stl_pop, ft_pop) == true) ? "[OK]" : "[NOP]");
}

void stack_operatorEqualTrue()
{
    std::cout<< std::endl << "===================================operator== ===================================" << std::endl;;
    
    std::stack<int> stl_pop_one;
    std::stack<int> stl_pop_two;
    ft::stack<int> ft_pop_one;
    ft::stack<int> ft_pop_two;

    for (int i = 0; i < 42; i++)
    {
        stl_pop_one.push(i);
        stl_pop_two.push(i);
        ft_pop_one.push(i);
        ft_pop_two.push(i);
    }

    printStackAttributes(stl_pop_one, ft_pop_one);
    printStackAttributes(stl_pop_two, ft_pop_two);
    
    std::cout << ((printBoolResult((stl_pop_one == stl_pop_two), (ft_pop_one == ft_pop_two)) == true) ? "[OK]" : "[NOP]");
}

void stackOperatorSmallerTrue()
{
    std::cout<< std::endl << "===================================operator < False ===================================" << std::endl;;
    
    std::stack<int> stl_pop_one;
    std::stack<int> stl_pop_two;
    ft::stack<int> ft_pop_one;
    ft::stack<int> ft_pop_two;

    for (int i = 0; i < 42; i++)
    {
        stl_pop_one.push(i);
        ft_pop_one.push(i);
        if (i == 30)
        {
            stl_pop_two.push(i * 2);
            ft_pop_two.push(i * 2);
        }
        else
        {
            stl_pop_two.push(i);
            ft_pop_two.push(i);
        }
    }

    printStackAttributes(stl_pop_one, ft_pop_one);
    printStackAttributes(stl_pop_two, ft_pop_two);
    
    std::cout << ((printBoolResult((stl_pop_one < stl_pop_two), (ft_pop_one < ft_pop_two)) == true) ? "[OK]" : "[NOP]");
}

void stackOperatorNotEqualFalse()
{
    std::cout<< std::endl << "===================================operator != False ===================================" << std::endl;;
    
    std::stack<int> stl_pop_one;
    std::stack<int> stl_pop_two;
    ft::stack<int> ft_pop_one;
    ft::stack<int> ft_pop_two;

    for (int i = 0; i < 42; i++)
    {
        stl_pop_one.push(i);
        stl_pop_two.push(i);
        ft_pop_one.push(i);
        ft_pop_two.push(i);
    }
    
    printStackAttributes(stl_pop_one, ft_pop_one);
    printStackAttributes(stl_pop_two, ft_pop_two);
    
    std::cout << ((printBoolResult((stl_pop_one != stl_pop_two), (ft_pop_one != ft_pop_two)) == true) ? "[OK]" : "[NOP]");

}

void stackOperatorMoreTrue()
{
    std::cout<< std::endl << "===================================operator > True ===================================" << std::endl;;
    
    std::stack<int> stl_pop_one;
    std::stack<int> stl_pop_two;
    ft::stack<int> ft_pop_one;
    ft::stack<int> ft_pop_two;

    for (int i = 0; i < 42; i++)
    {
        stl_pop_one.push(i * 2);
        stl_pop_two.push(i);
        ft_pop_one.push(i * 2);
        ft_pop_two.push(i);
    }

    printStackAttributes(stl_pop_one, ft_pop_one);
    printStackAttributes(stl_pop_two, ft_pop_two);
    
    std::cout << ((printBoolResult((stl_pop_one > stl_pop_two), (ft_pop_one > ft_pop_two)) == true) ? "[OK]" : "[NOP]");

}