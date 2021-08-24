#include "vector_utils.hpp"
#include <iostream>

void vector_Default_constructor()
{
    std::cout<< std::endl << "===================================Default constructor===================================" << std::endl;
    
    std::vector<int> stlDefaultConstr;
    ft::vector<int> ftDefaultConstr;

    std::cout << ((showInfoVector(stlDefaultConstr, ftDefaultConstr) == true) ? "[✅]" : "[❌]");
}

void vector_FillConstructor()
{
    std::cout<< std::endl << "===================================Fill constructor===================================" << std::endl;
    std::vector<int> stlFillConstr(0);
    ft::vector<int> ftFillConstr(0);

    std::cout << ((showInfoVector(stlFillConstr, ftFillConstr) == true) ? "[✅]" : "[❌]");
    
}

void vector_FillConstructorSizedValue()
{
    std::cout<< std::endl << "===================================FillConstructorSizedValue===================================" << std::endl;
    std::vector<int> stlFillConstr_sized(19, 42);
    ft::vector<int> ftFillConstr_sized(19, 42);

    std::cout << ((showInfoVector(stlFillConstr_sized, ftFillConstr_sized) == true) ? "[✅]" : "[❌]");
}

void vector_RangeConstructor()
{
    std::cout<< std::endl << "===================================RangeConstructor===================================" << std::endl;
    int array[] = { 45, 87846, 12, 965, 5 };

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();;

    std::vector<int> stl_range_vector(stlIterator, stlIterator + 5);
    ft::vector<int> ft_range_vector(ftIterator, ftIterator + 5);

    std::cout << ((showInfoVector(stl_range_vector, ft_range_vector) == true) ? "[✅]" : "[❌]");
    
}

void vector_CopyConstructor()
{
    std::cout<< std::endl << "===================================CopyConstructor===================================" << std::endl;
    int array[] = { -89, 561, 874, 7777 , 987, -6 };
    
    std::vector<int> stvct;
    ft::vector<int> vct;

    for (int i = 0; i < 6; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_range_vector(stlIterator, stlIterator + 6);
    ft::vector<int> ft_range_vector(ftIterator, ftIterator + 6);

    std::vector<int> stl_copy_vector(stl_range_vector);
    ft::vector<int> ft_copy_vector(ft_range_vector);

    std::cout << ((showInfoVector(stl_copy_vector, ft_copy_vector) == true) ? "[✅]" : "[❌]");
    
}

void vectorAssignOperator()
{
    std::cout<< std::endl << "===================================vectorAssignOperator===================================" << std::endl;
    int array[] = { 74, 569, -8822, 8515, 5 };

    std::vector<int> stvct;
    ft::vector<int> vct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_range_vector(stlIterator, stlIterator + 5);
    ft::vector<int> ft_range_vector(ftIterator, ftIterator + 5);

    std::vector<int> stl_assign_vector = stl_range_vector;
    ft::vector<int> ft_assign_vector = ft_range_vector;

    std::cout << ((showInfoVector(stl_assign_vector, ft_assign_vector) == true) ? "[✅]" : "[❌]");
}

void vectorIteratorBegin()
{
    std::cout<< std::endl << "===================================vectorIteratorBegin===================================" << std::endl;
    
    int array[] = { 87, 92, -5, 8984, 96 };

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_range_vector(stlIterator, stlIterator + 5);
    ft::vector<int> ft_range_vector(ftIterator, ftIterator + 5);

    int from_stl = *(stl_range_vector.begin());
    int from_ft = *(ft_range_vector.begin());

    std::cout << ((showInfo(from_stl, from_ft) == true) ? "[✅]" : "[❌]");
}

void vectorConstIteratorBegin()
{
    std::cout<< std::endl << "===================================vectorConstIteratorBegin===================================" << std::endl;
    int array[] = { 87, 92, -5, 8984, 96 };

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_range_vector(stlIterator, stlIterator + 5);
    ft::vector<int> ft_range_vector(ftIterator, ftIterator + 5);

    std::vector<int>::const_iterator stl_const_it = stl_range_vector.begin();
    ft::vector<int>::const_iterator ft_const_it = ft_range_vector.begin();
    const int from_stl = *(stl_const_it);
    const int from_ft = *(ft_const_it);

    std::cout << ((showInfo(from_stl, from_ft) == true) ? "[✅]" : "[❌]");
}

void vectorIteratorEnd()
{
    std::cout<< std::endl << "===================================vectorIteratorEnd===================================" << std::endl;

    int array[] = { 48, 967, 52, -45, -9, 956551, 44};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 7; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_range_vector(stlIterator, stlIterator + 7);
    ft::vector<int> ft_range_vector(ftIterator, ftIterator + 7);

    int from_stl = *(stl_range_vector.end() - 1);
    int from_ft = *(ft_range_vector.end() - 1);

    std::cout << ((showInfo(from_stl, from_ft) == true) ? "[✅]" : "[❌]");

}

void vectorConstIteratorEnd()
{
    std::cout<< std::endl << "===================================vectorConstIteratorEnd===================================" << std::endl;

    int array[] = { 95, 89, -6121, 48, 5 };

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_range_vector(stlIterator, stlIterator + 5);
    ft::vector<int> ft_range_vector(ftIterator, ftIterator + 5);

    std::vector<int>::const_iterator stl_const_it = stl_range_vector.end() - 1;
    ft::vector<int>::const_iterator ft_const_it = ft_range_vector.end() - 1;
    const int from_stl = *(stl_const_it);
    const int from_ft = *(ft_const_it);

    std::cout << ((showInfo(from_stl, from_ft) == true) ? "[✅]" : "[❌]");
}

void vectorIteratorRbegin()
{
    std::cout<< std::endl << "===================================vectorIteratorRbegin===================================" << std::endl;

    int array[] = {250, -1200, -98657, 2, 34};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_range_vector(stlIterator, stlIterator + 5);
    ft::vector<int> ft_range_vector(ftIterator, ftIterator + 5);

    int from_stl = *(stl_range_vector.rbegin());
    int from_ft = *(ft_range_vector.rbegin());

    std::cout << ((showInfo(from_stl, from_ft) == true) ? "[✅]" : "[❌]");
}

void vectorConstIteratorRbegin()
{
    std::cout<< std::endl << "===================================vectorConstIteratorRbegin===================================" << std::endl;
    int array[] = { 958, -561, 54, 789, -8};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_range_vector(stlIterator, stlIterator + 5);
    ft::vector<int> ft_range_vector(ftIterator, ftIterator + 5);
 
    std::vector<int>::const_reverse_iterator stl_const_it = stl_range_vector.rbegin();
    ft::vector<int>::const_reverse_iterator ft_const_it = ft_range_vector.rbegin();
    const int from_stl = *(stl_const_it);
    const int from_ft = *(ft_const_it);

    std::cout << ((showInfo(from_stl, from_ft) == true) ? "[✅]" : "[❌]");
    
}

void vectorIteratorRend()
{
    std::cout<< std::endl << "===================================vectorIteratorRend===================================" << std::endl;

    int array[] = {78, -951, 562, 8, 745, 51236, 6987};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 7; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_range_vector(stlIterator, stlIterator + 7);
    ft::vector<int> ft_range_vector(ftIterator, ftIterator + 7);

    int from_stl = *(stl_range_vector.rend() - 1);
    int from_ft = *(ft_range_vector.rend() - 1);

    std::cout << ((showInfo(from_stl, from_ft) == true) ? "[✅]" : "[❌]");
}
 
void vectorConstIteratorRend()
{
    std::cout<< std::endl << "===================================vectorConstIteratorRend===================================" << std::endl;
    
    int array[] = { 8, -5615, 412, 89, 475};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_range_vector(stlIterator, stlIterator + 5);
    ft::vector<int> ft_range_vector(ftIterator, ftIterator + 5);

    std::vector<int>::const_reverse_iterator stl_const_it = stl_range_vector.rend() - 1;
    ft::vector<int>::const_reverse_iterator ft_const_it = ft_range_vector.rend() - 1;
    const int from_stl = *(stl_const_it);
    const int from_ft = *(ft_const_it);

    std::cout << ((showInfo(from_stl, from_ft) == true) ? "[✅]" : "[❌]");
}

void vecotSizeMaximum()
{
    std::cout<< std::endl << "===================================vecotSizeMaximum===================================" << std::endl;
   
    std::vector<int> stl_base;
    ft::vector<int> ft_base;

    std::cout << ((showInfoVector(stl_base, ft_base) == true) ? "[✅]" : "[❌]");
}

void vectorResize()
{
    std::cout<< std::endl << "===================================vectorResize===================================" << std::endl;
   
    std::vector<int> stl_base(40);
    ft::vector<int> ft_base(40);

    stl_base.resize(85);
    ft_base.resize(85);

    std::cout << ((showInfoVector(stl_base, ft_base) == true) ? "[✅]" : "[❌]");       
}

void vectorEmtyTrue()
{
    std::cout<< std::endl << "===================================vectorEmtyTrue===================================" << std::endl;
   
    std::vector<int> stl_base;
    ft::vector<int> ft_base;
    std::cout << ((showInfoVector(stl_base, ft_base) == true) ? "[✅]" : "[❌]");
}

void vectorEmtyFalse()
{
    std::cout<< std::endl << "===================================vectorEmtyFalse===================================" << std::endl;
   
    std::vector<int> stl_base(5);
    ft::vector<int> ft_base(5);

    std::cout << ((showInfoVector(stl_base, ft_base) == true) ? "[✅]" : "[❌]");
}

void vectorOperator()
{
    std::cout<< std::endl << "===================================vectorOperator===================================" << std::endl;
    int array[] = { 8, -5615, 412, 89, 475};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_operator(stlIterator, stlIterator + 5);
    ft::vector<int> ft_operator(ftIterator, ftIterator + 5);
    std::cout << ((showInfo(stl_operator[1], ft_operator[1]) == true) ? "[✅]" : "[❌]");
}

void vectorConstOperator()
{
    std::cout<< std::endl << "===================================vectorConstOperator===================================" << std::endl;

    int array[] = {8, -98, 541, 53361, 9};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_operator(stlIterator, stlIterator + 5);
    ft::vector<int> ft_operator(ftIterator, ftIterator + 5);

    const int stl_const = stl_operator[1];
    const int ft_const = ft_operator[1];
    
    std::cout << ((showInfo(stl_const, ft_const) == true) ? "[✅]" : "[❌]");
}

void vectorAt()
{
    std::cout<< std::endl << "===================================vectorAt===================================" << std::endl;
    int array[] = {8, -986, -8, 66, 7};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_at(stlIterator, stlIterator + 5);
    ft::vector<int> ft_at(ftIterator, ftIterator + 5);
    std::cout << ((showInfo(stl_at.at(3), ft_at.at(3)) == true) ? "[✅]" : "[❌]");
}

void vectorConstAt()
{
    std::cout<< std::endl << "===================================vectorConstAt===================================" << std::endl;

    int array[] = {845, -9, 47, 4, -825};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_at(stlIterator, stlIterator + 5);
    ft::vector<int> ft_at(ftIterator, ftIterator + 5);

    const int stl_const = stl_at.at(4);
    const int ft_const = ft_at.at(4);
    std::cout << ((showInfo(stl_const, ft_const) == true) ? "[✅]" : "[❌]");
}

void vectorFront()
{
    std::cout<< std::endl << "===================================vectorFront===================================" << std::endl;

    int array[] = {2, 0, 982, -9, 87};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_front(stlIterator, stlIterator + 5);
    ft::vector<int> ft_front(ftIterator, ftIterator + 5);
    std::cout << ((showInfo(stl_front.front(), ft_front.front()) == true) ? "[✅]" : "[❌]");
}

void vectorConstFront()
{
    std::cout<< std::endl << "===================================vectorConstFront===================================" << std::endl;

    int array[] = {5589, -97, -98, -63, 8};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_front(stlIterator, stlIterator + 5);
    ft::vector<int> ft_front(ftIterator, ftIterator + 5);

    const int stl_const = stl_front.front();
    const int ft_const = ft_front.front();
    std::cout << ((showInfo(stl_const, ft_const) == true) ? "[✅]" : "[❌]");
}

void vectorBack()
{
    std::cout<< std::endl << "===================================vectorBack===================================" << std::endl;
    int array[] = {2, 0, 982, -9, 87};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_back(stlIterator, stlIterator + 5);
    ft::vector<int> ft_back(ftIterator, ftIterator + 5);
    std::cout << ((showInfo(stl_back.back(), ft_back.back()) == true) ? "[✅]" : "[❌]");
}

void vectorConstBack()
{
    std::cout<< std::endl << "===================================vectorConstBack===================================" << std::endl;
    int array[] = {5589, -97, -98, -63, 8};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_back(stlIterator, stlIterator + 5);
    ft::vector<int> ft_back(ftIterator, ftIterator + 5);

    const int stl_const = stl_back.back();
    const int ft_const = ft_back.back();
    std::cout << ((showInfo(stl_const, ft_const) == true) ? "[✅]" : "[❌]");   
}

void vectorAssignRange()
{
    std::cout<< std::endl << "===================================vectorAssignRange===================================" << std::endl;
    
    int array[] = {84, 522, -654, -7623, 4};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_assign;
    ft::vector<int> ft_assign;

    stl_assign.assign(stlIterator, stlIterator + 5);
    ft_assign.assign(ftIterator, ftIterator + 5);
    std::cout << ((showInfoVector(stl_assign, ft_assign) == true) ? "[✅]" : "[❌]");
}

void vectorPushBackEmpty()
{
    std::cout<< std::endl << "===================================vectorPushBackEmpty===================================" << std::endl;
    
    std::vector<int> stl_pushback;
    ft::vector<int> ft_pushback;

    stl_pushback.push_back(42);
    ft_pushback.push_back(42);

    std::cout << ((showInfoVector(stl_pushback, ft_pushback) == true) ? "[✅]" : "[❌]");
}

void vectorPushBack()
{
    std::cout<< std::endl << "===================================vectorPushBack===================================" << std::endl;
    std::vector<int> stl_pushback(7);
    ft::vector<int> ft_pushback(7);

    stl_pushback.push_back(42);
    ft_pushback.push_back(42);
    
    std::cout << ((showInfoVector(stl_pushback, ft_pushback) == true) ? "[✅]" : "[❌]");
}

void vectorPopBack()
{
    std::cout<< std::endl << "===================================vectorPopBack===================================" << std::endl;
    int array[] = {547, 98, -6, 0, 47};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_popback(stlIterator, stlIterator + 5);
    ft::vector<int> ft_popback(ftIterator, ftIterator + 5);

    stl_popback.pop_back();
    ft_popback.pop_back();
    
    std::cout << ((showInfoVector(stl_popback, ft_popback) == true) ? "[✅]" : "[❌]");
}

void vectorInsertSingleElement()
{
    std::cout<< std::endl << "===================================vectorInsertSingleElement===================================" << std::endl;
    
    int array[] = {478, 87, -85, 44, 7};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_insert(stlIterator, stlIterator + 5);
    ft::vector<int> ft_insert(ftIterator, ftIterator + 5);

    stl_insert.insert(stl_insert.begin() + 2, 9999);
    ft_insert.insert(ft_insert.begin() + 2, 9999);

    std::cout << ((showInfoVector(stl_insert, ft_insert) == true) ? "[✅]" : "[❌]");
}

void vectorInsertFill()
{
    std::cout<< std::endl << "===================================vectorInsertFill===================================" << std::endl;
    int array[] = {47, 152, -325, 9, 14444};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_insert(stlIterator, stlIterator + 5);
    ft::vector<int> ft_insert(ftIterator, ftIterator + 5);

    stl_insert.insert(stl_insert.begin() + 2, 6, 4269);
    ft_insert.insert(ft_insert.begin() + 2, 6, 4269);

    std::cout << ((showInfoVector(stl_insert, ft_insert) == true) ? "[✅]" : "[❌]");      
}

void vectorEraseSingleElement()
{
    std::cout<< std::endl << "===================================vectorEraseSingleElement===================================" << std::endl;
    int array[] = {47, 152, -325, 9, 14444};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_erase(stlIterator, stlIterator + 5);
    ft::vector<int> ft_erase(ftIterator, ftIterator + 5);

    stl_erase.erase(stl_erase.begin() + 2);
    ft_erase.erase(ft_erase.begin() + 2);

    std::cout << ((showInfoVector(stl_erase, ft_erase) == true) ? "[✅]" : "[❌]");
}

void vectorEraseRange()
{
    std::cout<< std::endl << "===================================vectorEraseRange===================================" << std::endl;
    int array[] = {1458, -98, 745, 62, 9};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();

    std::vector<int> stl_erase(stlIterator, stlIterator + 5);
    ft::vector<int> ft_erase(ftIterator, ftIterator + 5);

    stl_erase.erase(stl_erase.begin() + 1, stl_erase.end() - 2);
    ft_erase.erase(ft_erase.begin() + 1, ft_erase.end() - 2);

    std::cout << ((showInfoVector(stl_erase, ft_erase) == true) ? "[✅]" : "[❌]");
}

void vectorSwap()
{
    std::cout<< std::endl << "===================================vectorSwap===================================" << std::endl;
    int array_one[] = {1458, -98, 745, 62, 9};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array_one[i]);
        stvct.push_back(array_one[i]);
    }

    std::vector<int>::iterator stlIteratorFirst = stvct.begin();
    ft::vector<int>::iterator ftIteratorFirst = vct.begin();
    
    ft::vector<int>::iterator ftIteratorSecond = vct.begin();
    std::vector<int>::iterator stlIteratorSecond = stvct.begin();

    std::vector<int> stl_swap_one(stlIteratorFirst, stlIteratorFirst + 5);
    std::vector<int> stl_swap_two(stlIteratorSecond, stlIteratorSecond + 5);
    ft::vector<int> ft_swap_one(ftIteratorFirst, ftIteratorFirst + 5);
    ft::vector<int> ft_swap_two(ftIteratorSecond, ftIteratorSecond + 5);

    stl_swap_one.swap(stl_swap_two);
    ft_swap_one.swap(ft_swap_two);

    std::cout << ((showInfoVector(stl_swap_one, ft_swap_one) == true) ? "[✅]" : "[❌]");
    std::cout << ((showInfoVector(stl_swap_two, ft_swap_two) == true) ? "[✅]" : "[❌]");
}

void vectorClear()
{
    std::cout<< std::endl << "===================================vectorClear===================================" << std::endl;
    int array[] = {-455, 2, 1347, 75, 945};

    ft::vector<int> vct;
    std::vector<int> stvct;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array[i]);
        stvct.push_back(array[i]);
    }

    std::vector<int>::iterator stlIterator = stvct.begin();
    ft::vector<int>::iterator ftIterator = vct.begin();


    std::vector<int> stl_clear(stlIterator, stlIterator + 5);
    ft::vector<int> ft_clear(ftIterator, ftIterator + 5);

    stl_clear.clear();
    ft_clear.clear();

    std::cout << ((showInfoVector(stl_clear, ft_clear) == true) ? "[✅]" : "[❌]");
}

void vectorRealationEqualTrue()
{
    std::cout<< std::endl << "===================================vectorRealationEqualTrue===================================" << std::endl;
    int array_one[] = {1458, -98, 745, 62, 9};
    int array_two[] = {1458, -98, 745, 62, 9};

    ft::vector<int> vct;
    std::vector<int> stvct;


    ft::vector<int> vct2;
    std::vector<int> stvct2;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array_one[i]);
        stvct.push_back(array_one[i]);

        vct2.push_back(array_two[i]);
        stvct2.push_back(array_two[i]);
    }

    std::vector<int>::iterator stlIteratorFirst = stvct.begin();
    ft::vector<int>::iterator ftIteratorFirst = vct.begin();
    
    ft::vector<int>::iterator ftIteratorSecond = vct2.begin();
    std::vector<int>::iterator stlIteratorSecond = stvct2.begin();

    std::vector<int> stl_equal_one(stlIteratorFirst, stlIteratorFirst + 5);
    std::vector<int> stl_equal_two(stlIteratorSecond, stlIteratorSecond + 5);
    ft::vector<int> ft_equal_one(ftIteratorFirst, ftIteratorFirst + 5);
    ft::vector<int> ft_equal_two(ftIteratorSecond, ftIteratorSecond + 5);

    showInfoVector(stl_equal_one, ft_equal_one);
    showInfoVector(stl_equal_two, ft_equal_two);

    std::cout << ((printBoolResult((stl_equal_one == stl_equal_two), (ft_equal_one == ft_equal_two))) ? "[✅]" : "[❌]");
}

void vectorRealationEqualFalse()
{
    std::cout<< std::endl << "===================================vectorRealationEqualFalse===================================" << std::endl;
    int array_one[] = {1458, -98, 745, 62, 9};
    int array_two[] = {1458, -98, 31, 62, 9};

    ft::vector<int> vct;
    std::vector<int> stvct;


    ft::vector<int> vct2;
    std::vector<int> stvct2;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array_one[i]);
        stvct.push_back(array_one[i]);

        vct2.push_back(array_two[i]);
        stvct2.push_back(array_two[i]);
    }

    std::vector<int>::iterator stlIteratorFirst = stvct.begin();
    ft::vector<int>::iterator ftIteratorFirst = vct.begin();
    
    ft::vector<int>::iterator ftIteratorSecond = vct2.begin();
    std::vector<int>::iterator stlIteratorSecond = stvct2.begin();

    std::vector<int> stl_equal_one(stlIteratorFirst, stlIteratorFirst + 5);
    std::vector<int> stl_equal_two(stlIteratorSecond, stlIteratorSecond + 5);
    ft::vector<int> ft_equal_one(ftIteratorFirst, ftIteratorFirst + 5);
    ft::vector<int> ft_equal_two(ftIteratorSecond, ftIteratorSecond + 5);

    showInfoVector(stl_equal_one, ft_equal_one);
    showInfoVector(stl_equal_two, ft_equal_two);

    std::cout << ((printBoolResult((stl_equal_one == stl_equal_two), (ft_equal_one == ft_equal_two))) ? "[✅]" : "[❌]");
}

void vectorRealationNotEqualTrue()
{
    std::cout<< std::endl << "===================================vectorRealationNotEqualTrue===================================" << std::endl;
 
    int array_one[] = {1458, -98, 745, 62, 9};
    int array_two[] = {1458, -98, 1, 62, 9};

    ft::vector<int> vct;
    std::vector<int> stvct;


    ft::vector<int> vct2;
    std::vector<int> stvct2;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array_one[i]);
        stvct.push_back(array_one[i]);

        vct2.push_back(array_two[i]);
        stvct2.push_back(array_two[i]);
    }

    std::vector<int>::iterator stlIteratorFirst = stvct.begin();
    ft::vector<int>::iterator ftIteratorFirst = vct.begin();
    
    ft::vector<int>::iterator ftIteratorSecond = vct2.begin();
    std::vector<int>::iterator stlIteratorSecond = stvct2.begin();

    std::vector<int> stlOperatorFirst(stlIteratorFirst, stlIteratorFirst + 5);
    std::vector<int> stlOperatorSecond(stlIteratorSecond, stlIteratorSecond + 5);
    ft::vector<int> ftOperatorOne(ftIteratorFirst, ftIteratorFirst + 5);
    ft::vector<int> ftOperatorSecond(ftIteratorSecond, ftIteratorSecond + 5);

    showInfoVector(stlOperatorFirst, ftOperatorOne);
    showInfoVector(stlOperatorSecond, ftOperatorSecond);

    std::cout << ((printBoolResult((stlOperatorFirst != stlOperatorSecond), (ftOperatorOne != ftOperatorSecond))) ? "[✅]" : "[❌]");
}

void vectorRealationNotEqualFalse()
{
    std::cout<< std::endl << "===================================vectorRealationNotEqualFalse===================================" << std::endl;
    int array_one[] = {1458, -98, 745, 62, 9};
    int array_two[] = {1458, -98, 745, 62, 9};

    ft::vector<int> vct;
    std::vector<int> stvct;


    ft::vector<int> vct2;
    std::vector<int> stvct2;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array_one[i]);
        stvct.push_back(array_one[i]);

        vct2.push_back(array_two[i]);
        stvct2.push_back(array_two[i]);
    }

    std::vector<int>::iterator stlIteratorFirst = stvct.begin();
    ft::vector<int>::iterator ftIteratorFirst = vct.begin();
    
    ft::vector<int>::iterator ftIteratorSecond = vct2.begin();
    std::vector<int>::iterator stlIteratorSecond = stvct2.begin();

    std::vector<int> stlOperatorFirst(stlIteratorFirst, stlIteratorFirst + 5);
    std::vector<int> stlOperatorSecond(stlIteratorSecond, stlIteratorSecond + 5);
    ft::vector<int> ftOperatorOne(ftIteratorFirst, ftIteratorFirst + 5);
    ft::vector<int> ftOperatorSecond(ftIteratorSecond, ftIteratorSecond + 5);

    showInfoVector(stlOperatorFirst, ftOperatorOne);
    showInfoVector(stlOperatorSecond, ftOperatorSecond);
 
    std::cout << ((printBoolResult((stlOperatorFirst != stlOperatorSecond), (ftOperatorOne != ftOperatorSecond))) ? "[✅]" : "[❌]");
}

void vectorSmallTrue()
{
    std::cout<< std::endl << "===================================vectorSmallTrue===================================" << std::endl;
    
    int array_one[] = {144, 335, 1, -98, 5};
    int array_two[] = {144, 335, 5, 0, -54};

    ft::vector<int> vct;
    std::vector<int> stvct;


    ft::vector<int> vct2;
    std::vector<int> stvct2;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array_one[i]);
        stvct.push_back(array_one[i]);

        vct2.push_back(array_two[i]);
        stvct2.push_back(array_two[i]);
    }

    std::vector<int>::iterator stlIteratorFirst = stvct.begin();
    ft::vector<int>::iterator ftIteratorFirst = vct.begin();
    
    ft::vector<int>::iterator ftIteratorSecond = vct2.begin();
    std::vector<int>::iterator stlIteratorSecond = stvct2.begin();

    std::vector<int> stlOperatorFirst(stlIteratorFirst, stlIteratorFirst + 5);
    std::vector<int> stlOperatorSecond(stlIteratorSecond, stlIteratorSecond + 5);
    ft::vector<int> ftOperatorOne(ftIteratorFirst, ftIteratorFirst + 5);
    ft::vector<int> ftOperatorSecond(ftIteratorSecond, ftIteratorSecond + 5);

    showInfoVector(stlOperatorFirst, ftOperatorOne);
    showInfoVector(stlOperatorSecond, ftOperatorSecond);

    std::cout << ((printBoolResult((stlOperatorFirst < stlOperatorSecond), (ftOperatorOne < ftOperatorSecond))) ? "[✅]" : "[❌]");
}

void vectorSmallFalse()
{
    std::cout<< std::endl << "===================================vectorSmallFalse===================================" << std::endl;
    
    int array_one[] = {6780, 335, 1, -98, 5};
    int array_two[] = {144, 335, 5, 0, -54};

    ft::vector<int> vct;
    std::vector<int> stvct;


    ft::vector<int> vct2;
    std::vector<int> stvct2;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array_one[i]);
        stvct.push_back(array_one[i]);

        vct2.push_back(array_two[i]);
        stvct2.push_back(array_two[i]);
    }

    std::vector<int>::iterator stlIteratorFirst = stvct.begin();
    ft::vector<int>::iterator ftIteratorFirst = vct.begin();
    
    ft::vector<int>::iterator ftIteratorSecond = vct2.begin();
    std::vector<int>::iterator stlIteratorSecond = stvct2.begin();

    std::vector<int> stlOperatorFirst(stlIteratorFirst, stlIteratorFirst + 5);
    std::vector<int> stlOperatorSecond(stlIteratorSecond, stlIteratorSecond + 5);
    ft::vector<int> ftOperatorOne(ftIteratorFirst, ftIteratorFirst + 5);
    ft::vector<int> ftOperatorSecond(ftIteratorSecond, ftIteratorSecond + 5);

    showInfoVector(stlOperatorFirst, ftOperatorOne);
    showInfoVector(stlOperatorSecond, ftOperatorSecond);

    std::cout << ((printBoolResult((stlOperatorFirst < stlOperatorSecond), (ftOperatorOne < ftOperatorSecond))) ? "[✅]" : "[❌]");
}

void vectorMoreTrue()
{
    std::cout<< std::endl << "===================================vectorMoreTrue===================================" << std::endl;
    
    int array_one[] = {144, 9999, 5, 0, -54};
    int array_two[] = {144, 335, 5, 0, -54};

    ft::vector<int> vct;
    std::vector<int> stvct;

    ft::vector<int> vct2;
    std::vector<int> stvct2;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array_one[i]);
        stvct.push_back(array_one[i]);

        vct2.push_back(array_two[i]);
        stvct2.push_back(array_two[i]);
    }

    std::vector<int>::iterator stlIteratorFirst = stvct.begin();
    ft::vector<int>::iterator ftIteratorFirst = vct.begin();
    
    ft::vector<int>::iterator ftIteratorSecond = vct2.begin();
    std::vector<int>::iterator stlIteratorSecond = stvct2.begin();

    std::vector<int> stlOperatorFirst(stlIteratorFirst, stlIteratorFirst + 5);
    std::vector<int> stlOperatorSecond(stlIteratorSecond, stlIteratorSecond + 5);
    ft::vector<int> ftOperatorOne(ftIteratorFirst, ftIteratorFirst + 5);
    ft::vector<int> ftOperatorSecond(ftIteratorSecond, ftIteratorSecond + 5);

    showInfoVector(stlOperatorFirst, ftOperatorOne);
    showInfoVector(stlOperatorSecond, ftOperatorSecond);
    
    std::cout << ((printBoolResult((stlOperatorFirst > stlOperatorSecond), (ftOperatorOne > ftOperatorSecond))) ? "[✅]" : "[❌]");
}

void vectorMoreFalse()
{
    std::cout<< std::endl << "===================================vectorMoreFalse===================================" << std::endl;

    int array_one[] = {144, 335, 5, 0, -54};
    int array_two[] = {144, 335, 77, 0, -54};

    ft::vector<int> vct;
    std::vector<int> stvct;

    ft::vector<int> vct2;
    std::vector<int> stvct2;

    for (int i = 0; i < 5; i++)
    {
        vct.push_back(array_one[i]);
        stvct.push_back(array_one[i]);

        vct2.push_back(array_two[i]);
        stvct2.push_back(array_two[i]);
    }

    std::vector<int>::iterator stlIteratorFirst = stvct.begin();
    ft::vector<int>::iterator ftIteratorFirst = vct.begin();
    
    ft::vector<int>::iterator ftIteratorSecond = vct2.begin();
    std::vector<int>::iterator stlIteratorSecond = stvct2.begin();

    std::vector<int> stlOperatorFirst(stlIteratorFirst, stlIteratorFirst + 5);
    std::vector<int> stlOperatorSecond(stlIteratorSecond, stlIteratorSecond + 5);
    ft::vector<int> ftOperatorOne(ftIteratorFirst, ftIteratorFirst + 5);
    ft::vector<int> ftOperatorSecond(ftIteratorSecond, ftIteratorSecond + 5);

    
    showInfoVector(stlOperatorFirst, ftOperatorOne);
    showInfoVector(stlOperatorSecond, ftOperatorSecond);


    std::cout << ((printBoolResult((stlOperatorFirst > stlOperatorSecond), (ftOperatorOne > ftOperatorSecond))) ? "[✅]" : "[❌]");
}