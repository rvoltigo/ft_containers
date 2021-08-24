#include "stack_utils.hpp"

void stack_Default_Constructor()
{
    std::cout<< std::endl << "===================================Default constructor===================================" << std::endl;;
    std::stack<int> stlDefaultConstr;
    ft::stack<int> ftDefaultConstr;

    std::cout << ((showInfoStack(stlDefaultConstr, ftDefaultConstr) == true) ? "[✅]" : "[❌]");
}

void stack_Empty_true()
{
    std::cout<< std::endl << "===================================stack_Empty_true===================================" << std::endl;;
    std::stack<int> stlEmpty;
    ft::stack<int> ftEmpty;

    std::cout << ((showInfoStack(stlEmpty, ftEmpty) == true) ? "[✅]" : "[❌]");
}

void stack_Empty_false()
{
    std::cout<< std::endl << "===================================stack_Empty_false===================================" << std::endl;;
    std::stack<int> stlEmpty;
    ft::stack<int> ftEmpty;

    stlEmpty.push(42);
    ftEmpty.push(42);

    std::cout << ((showInfoStack(stlEmpty, ftEmpty) == true) ? "[✅]" : "[❌]");

}

void stack_Size()
{
    std::cout<< std::endl << "===================================stack_Size===================================" << std::endl;;
    std::stack<int> sizeStlCont;
    ft::stack<int> sizeFtCont;

    for (int i = 0; i < 42; i++)
    {
        sizeStlCont.push(i);
        sizeFtCont.push(i);
    }

    std::cout << ((showInfoStack(sizeStlCont, sizeFtCont) == true) ? "[✅]" : "[❌]");
}

void stack_top()
{
    std::cout<< std::endl << "===================================stack_top===================================" << std::endl;;

    std::stack<int> TopStlCont;
    ft::stack<int> TopFtCont;

    for (int i = 0; i < 42; i++)
    {
        TopStlCont.push(i);
        TopFtCont.push(i);
    }

    std::cout << ((showInfo(TopStlCont.top(), TopFtCont.top()) == true) ? "[✅]" : "[❌]");
    
    TopStlCont.pop();
    TopFtCont.pop();

    std::cout << ((showInfo(TopStlCont.top(), TopFtCont.top()) == true) ? "[✅]" : "[❌]");
}

void stack_Push()
{
    std::cout<< std::endl << "===================================stack_Push===================================" << std::endl;;
    std::stack<int> sizeStlCont;
    ft::stack<int> sizeFtCont;

    for (int i = 0; i < 42; i++)
    {
        sizeStlCont.push(i * 2);
        sizeFtCont.push(i * 2);
    }

    std::cout << ((showInfoStack(sizeStlCont, sizeFtCont) == true) ? "[✅]" : "[❌]");

}

void stack_Pop()
{
    std::cout<< std::endl << "===================================stack_Pop===================================" << std::endl;;
    
    std::stack<int> PopStlCont;
    ft::stack<int> PopFtCont;

    for (int i = 0; i < 42; i++)
    {
        PopStlCont.push(i);
        PopFtCont.push(i);
    }

    std::cout << ((showInfoStack(PopStlCont, PopFtCont) == true) ? "[✅]" : "[❌]");
    
    PopStlCont.pop();
    PopFtCont.pop();

    std::cout << ((showInfoStack(PopStlCont, PopFtCont) == true) ? "[✅]" : "[❌]");
}

void stack_operatorEqualTrue()
{
    std::cout<< std::endl << "===================================operator== ===================================" << std::endl;;
    
    std::stack<int> PopStlContFirst;
    std::stack<int> PopStlContSecond;
    ft::stack<int> PopFtContFirst;
    ft::stack<int> PopFtContSecond;

    for (int i = 0; i < 42; i++)
    {
        PopStlContFirst.push(i);
        PopStlContSecond.push(i);
        PopFtContFirst.push(i);
        PopFtContSecond.push(i);
    }

    showInfoStack(PopStlContFirst, PopFtContFirst);
    showInfoStack(PopStlContSecond, PopFtContSecond);
    
    std::cout << ((showResult((PopStlContFirst == PopStlContSecond), (PopFtContFirst == PopFtContSecond)) == true) ? "[✅]" : "[❌]");
}

void stackOperatorSmallerTrue()
{
    std::cout<< std::endl << "===================================operator < False ===================================" << std::endl;;
    
    std::stack<int> PopStlContFirst;
    std::stack<int> PopStlContSecond;
    ft::stack<int> PopFtContFirst;
    ft::stack<int> PopFtContSecond;

    for (int i = 0; i < 42; i++)
    {
        PopStlContFirst.push(i);
        PopFtContFirst.push(i);
        if (i == 30)
        {
            PopStlContSecond.push(i * 2);
            PopFtContSecond.push(i * 2);
        }
        else
        {
            PopStlContSecond.push(i);
            PopFtContSecond.push(i);
        }
    }

    showInfoStack(PopStlContFirst, PopFtContFirst);
    showInfoStack(PopStlContSecond, PopFtContSecond);
    
    std::cout << ((showResult((PopStlContFirst < PopStlContSecond), (PopFtContFirst < PopFtContSecond)) == true) ? "[✅]" : "[❌]");
}

void stackOperatorNotEqualFalse()
{
    std::cout<< std::endl << "===================================operator != False ===================================" << std::endl;;
    
    std::stack<int> PopStlContFirst;
    std::stack<int> PopStlContSecond;
    ft::stack<int> PopFtContFirst;
    ft::stack<int> PopFtContSecond;

    for (int i = 0; i < 42; i++)
    {
        PopStlContFirst.push(i);
        PopStlContSecond.push(i);
        PopFtContFirst.push(i);
        PopFtContSecond.push(i);
    }
    
    showInfoStack(PopStlContFirst, PopFtContFirst);
    showInfoStack(PopStlContSecond, PopFtContSecond);
    
    std::cout << ((showResult((PopStlContFirst != PopStlContSecond), (PopFtContFirst != PopFtContSecond)) == true) ? "[✅]" : "[❌]");

}

void stackOperatorMoreTrue()
{
    std::cout<< std::endl << "===================================operator > True ===================================" << std::endl;;
    
    std::stack<int> PopStlContFirst;
    std::stack<int> PopStlContSecond;
    ft::stack<int> PopFtContFirst;
    ft::stack<int> PopFtContSecond;

    for (int i = 0; i < 42; i++)
    {
        PopStlContFirst.push(i * 2);
        PopStlContSecond.push(i);
        PopFtContFirst.push(i * 2);
        PopFtContSecond.push(i);
    }

    showInfoStack(PopStlContFirst, PopFtContFirst);
    showInfoStack(PopStlContSecond, PopFtContSecond);
    
    std::cout << ((showResult((PopStlContFirst > PopStlContSecond), (PopFtContFirst > PopFtContSecond)) == true) ? "[✅]" : "[❌]");

}