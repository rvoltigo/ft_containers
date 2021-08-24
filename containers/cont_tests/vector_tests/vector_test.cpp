#include "vector_utils.hpp"
#include <iostream>

void vector_Default_constructor()
{
    std::cout<< std::endl << "===================================Default constructor===================================" << std::endl;
    
    std::vector<int> stl_default_vector;
    ft::vector<int> ft_default_vector;

    std::cout << ((printVectorAttributes(stl_default_vector, ft_default_vector) == true) ? "[OK]" : "[NOP]");
}

void vector_FillConstructor()
{
    std::cout<< std::endl << "===================================Fill constructor===================================" << std::endl;
    std::vector<int> stl_fill_vector(0);
    ft::vector<int> ft_fill_vector(0);

    std::cout << ((printVectorAttributes(stl_fill_vector, ft_fill_vector) == true) ? "[OK]" : "[NOP]");
    
}

void vector_FillConstructorSizedValue()
{
    std::cout<< std::endl << "===================================FillConstructorSizedValue===================================" << std::endl;
    std::vector<int> stl_fill_vector_sized(19, 42);
    ft::vector<int> ft_fill_vector_sized(19, 42);

    std::cout << ((printVectorAttributes(stl_fill_vector_sized, ft_fill_vector_sized) == true) ? "[OK]" : "[NOP]");
}

void vector_RangeConstructor()
{
    std::cout<< std::endl << "===================================RangeConstructor===================================" << std::endl;
    int range_array[] = { 45, 87846, 12, 965, 5 };

    std::vector<int>::iterator stl_iterator(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator(&(range_array[0]));

    std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);
    ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);

    std::cout << ((printVectorAttributes(stl_range_vector, ft_range_vector) == true) ? "[OK]" : "[NOP]");
    
}

void vector_CopyConstructor()
{
    std::cout<< std::endl << "===================================CopyConstructor===================================" << std::endl;
     int range_array[] = { -89, 561, 874, 7777 , 987, -6 };
        
    std::vector<int>::iterator stl_iterator(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator(&(range_array[0]));

    std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 6);
    ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 6);

    std::vector<int> stl_copy_vector(stl_range_vector);
    ft::vector<int> ft_copy_vector(ft_range_vector);

    std::cout << ((printVectorAttributes(stl_copy_vector, ft_copy_vector) == true) ? "[OK]" : "[NOP]");
    
}

void vectorAssignOperator()
{
    std::cout<< std::endl << "===================================vectorAssignOperator===================================" << std::endl;
    int range_array[] = { 74, 569, -8822, 8515, 5 };

    std::vector<int>::iterator stl_iterator(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator(&(range_array[0]));

    std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);
    ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);

    std::vector<int> stl_assign_vector = stl_range_vector;
    ft::vector<int> ft_assign_vector = ft_range_vector;

    std::cout << ((printVectorAttributes(stl_assign_vector, ft_assign_vector) == true) ? "[OK]" : "[NOP]");
    
}

void vectorIteratorBegin()
{
    std::cout<< std::endl << "===================================vectorIteratorBegin===================================" << std::endl;
    
    int range_array[] = { 87, 92, -5, 8984, 96 };

    std::vector<int>::iterator stl_iterator(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator(&(range_array[0]));

    std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);
    ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);

    int from_stl = *(stl_range_vector.begin());
    int from_ft = *(ft_range_vector.begin());

    std::cout << ((printSingleValue(from_stl, from_ft) == true) ? "[OK]" : "[NOP]");
    
}

void vectorConstIteratorBegin()
{
    std::cout<< std::endl << "===================================vectorConstIteratorBegin===================================" << std::endl;
    int range_array[] = { 87, 92, -5, 8984, 96 };

    std::vector<int>::const_iterator stl_iterator(&(range_array[0]));
    ft::vector<int>::const_iterator ft_iterator(&(range_array[0]));

    std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);
    ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);

    std::vector<int>::const_iterator stl_const_it = stl_range_vector.begin();
    ft::vector<int>::const_iterator ft_const_it = ft_range_vector.begin();
    const int from_stl = *(stl_const_it);
    const int from_ft = *(ft_const_it);

    std::cout << ((printSingleValue(from_stl, from_ft) == true) ? "[OK]" : "[NOP]");
}

void vectorIteratorEnd()
{
    std::cout<< std::endl << "===================================vectorIteratorEnd===================================" << std::endl;

    int range_array[] = { 48, 967, 52, -45, -9, 956551, 44};

    std::vector<int>::iterator stl_iterator(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator(&(range_array[0]));

    std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 7);
    ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 7);

    int from_stl = *(stl_range_vector.end() - 1);
    int from_ft = *(ft_range_vector.end() - 1);

    std::cout << ((printSingleValue(from_stl, from_ft) == true) ? "[OK]" : "[NOP]");

}

void vectorConstIteratorEnd()
{
    std::cout<< std::endl << "===================================vectorConstIteratorEnd===================================" << std::endl;

    int range_array[] = { 95, 89, -6121, 48, 5 };

    std::vector<int>::const_iterator stl_iterator(&(range_array[0]));
    ft::vector<int>::const_iterator ft_iterator(&(range_array[0]));

    std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);
    ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);

    std::vector<int>::const_iterator stl_const_it = stl_range_vector.end() - 1;
    ft::vector<int>::const_iterator ft_const_it = ft_range_vector.end() - 1;
    const int from_stl = *(stl_const_it);
    const int from_ft = *(ft_const_it);

    std::cout << ((printSingleValue(from_stl, from_ft) == true) ? "[OK]" : "[NOP]");
    
}

void vectorIteratorRbegin()
{
    std::cout<< std::endl << "===================================vectorIteratorRbegin===================================" << std::endl;

    int range_array[] = {250, -1200, -98657, 2, 34};

    std::vector<int>::iterator stl_iterator(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator(&(range_array[0]));

    std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);
    ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);

    int from_stl = *(stl_range_vector.rbegin());
    int from_ft = *(ft_range_vector.rbegin());

    std::cout << ((printSingleValue(from_stl, from_ft) == true) ? "[OK]" : "[NOP]");
        
}

void vectorConstIteratorRbegin()
{
    std::cout<< std::endl << "===================================vectorConstIteratorRbegin===================================" << std::endl;
    int range_array[] = { 958, -561, 54, 789, -8};

    std::vector<int>::const_iterator stl_iterator(&(range_array[0]));
    ft::vector<int>::const_iterator ft_iterator(&(range_array[0]));

    std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);
    ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);
 
    std::vector<int>::const_reverse_iterator stl_const_it = stl_range_vector.rbegin();
    ft::vector<int>::const_reverse_iterator ft_const_it = ft_range_vector.rbegin();
    const int from_stl = *(stl_const_it);
    const int from_ft = *(ft_const_it);

    std::cout << ((printSingleValue(from_stl, from_ft) == true) ? "[OK]" : "[NOP]");
    
}

void vectorIteratorRend()
{
    std::cout<< std::endl << "===================================vectorIteratorRend===================================" << std::endl;

    int range_array[] = {78, -951, 562, 8, 745, 51236, 6987};

    std::vector<int>::iterator stl_iterator(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator(&(range_array[0]));

    std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 7);
    ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 7);

    int from_stl = *(stl_range_vector.rend() - 1);
    int from_ft = *(ft_range_vector.rend() - 1);

    std::cout << ((printSingleValue(from_stl, from_ft) == true) ? "[OK]" : "[NOP]");
    
}
 
void vectorConstIteratorRend()
{
    std::cout<< std::endl << "===================================vectorConstIteratorRend===================================" << std::endl;
    
    int range_array[] = { 8, -5615, 412, 89, 475};

    std::vector<int>::const_iterator stl_iterator(&(range_array[0]));
    ft::vector<int>::const_iterator ft_iterator(&(range_array[0]));

    std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);
    ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);

    std::vector<int>::const_reverse_iterator stl_const_it = stl_range_vector.rend() - 1;
    ft::vector<int>::const_reverse_iterator ft_const_it = ft_range_vector.rend() - 1;
    const int from_stl = *(stl_const_it);
    const int from_ft = *(ft_const_it);

    std::cout << ((printSingleValue(from_stl, from_ft) == true) ? "[OK]" : "[NOP]");
}

void vecotSizeMaximum()
{
    std::cout<< std::endl << "===================================vecotSizeMaximum===================================" << std::endl;
   
    std::vector<int> stl_base;
    ft::vector<int> ft_base;

    std::cout << ((printVectorAttributes(stl_base, ft_base) == true) ? "[OK]" : "[NOP]");
}

void vectorResize()
{
    std::cout<< std::endl << "===================================vectorResize===================================" << std::endl;
   
    std::vector<int> stl_base(40);
    ft::vector<int> ft_base(40);

    stl_base.resize(85);
    ft_base.resize(85);

    std::cout << ((printVectorAttributes(stl_base, ft_base) == true) ? "[OK]" : "[NOP]");       
}

void vectorEmtyTrue()
{
    std::cout<< std::endl << "===================================vectorEmtyTrue===================================" << std::endl;
   
    std::vector<int> stl_base;
    ft::vector<int> ft_base;
    std::cout << ((printVectorAttributes(stl_base, ft_base) == true) ? "[OK]" : "[NOP]");
}

void vectorEmtyFalse()
{
    std::cout<< std::endl << "===================================vectorEmtyFalse===================================" << std::endl;
   
    std::vector<int> stl_base(5);
    ft::vector<int> ft_base(5);

    std::cout << ((printVectorAttributes(stl_base, ft_base) == true) ? "[OK]" : "[NOP]");
}

void vectorOperator()
{
    std::cout<< std::endl << "===================================vectorOperator===================================" << std::endl;
    int range_array[] = { 8, -5615, 412, 89, 475};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_operator(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_operator(ft_iterator_beg, ft_iterator_beg + 5);
    std::cout << ((printSingleValue(stl_operator[1], ft_operator[1]) == true) ? "[OK]" : "[NOP]");
}

void vectorConstOperator()
{
    std::cout<< std::endl << "===================================vectorConstOperator===================================" << std::endl;

    int range_array[] = {8, -98, 541, 53361, 9};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_operator(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_operator(ft_iterator_beg, ft_iterator_beg + 5);

    const int stl_const = stl_operator[1];
    const int ft_const = ft_operator[1];
    
    std::cout << ((printSingleValue(stl_const, ft_const) == true) ? "[OK]" : "[NOP]");
        
}

void vectorAt()
{
    std::cout<< std::endl << "===================================vectorAt===================================" << std::endl;
    int range_array[] = {8, -986, -8, 66, 7};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_at(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_at(ft_iterator_beg, ft_iterator_beg + 5);
    std::cout << ((printSingleValue(stl_at.at(3), ft_at.at(3)) == true) ? "[OK]" : "[NOP]");
    
}

void vectorConstAt()
{
    std::cout<< std::endl << "===================================vectorConstAt===================================" << std::endl;

    int range_array[] = {845, -9, 47, 4, -825};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_at(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_at(ft_iterator_beg, ft_iterator_beg + 5);

    const int stl_const = stl_at.at(4);
    const int ft_const = ft_at.at(4);
    std::cout << ((printSingleValue(stl_const, ft_const) == true) ? "[OK]" : "[NOP]");
}

void vectorFront()
{
    std::cout<< std::endl << "===================================vectorFront===================================" << std::endl;

    int range_array[] = {2, 0, 982, -9, 87};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_front(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_front(ft_iterator_beg, ft_iterator_beg + 5);
    std::cout << ((printSingleValue(stl_front.front(), ft_front.front()) == true) ? "[OK]" : "[NOP]");
}

void vectorConstFront()
{
    std::cout<< std::endl << "===================================vectorConstFront===================================" << std::endl;

    int range_array[] = {5589, -97, -98, -63, 8};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_front(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_front(ft_iterator_beg, ft_iterator_beg + 5);

    const int stl_const = stl_front.front();
    const int ft_const = ft_front.front();
    std::cout << ((printSingleValue(stl_const, ft_const) == true) ? "[OK]" : "[NOP]");
}

void vectorBack()
{
    std::cout<< std::endl << "===================================vectorBack===================================" << std::endl;
    int range_array[] = {2, 0, 982, -9, 87};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_back(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_back(ft_iterator_beg, ft_iterator_beg + 5);
    std::cout << ((printSingleValue(stl_back.back(), ft_back.back()) == true) ? "[OK]" : "[NOP]");

}

void vectorConstBack()
{
    std::cout<< std::endl << "===================================vectorConstBack===================================" << std::endl;
    int range_array[] = {5589, -97, -98, -63, 8};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_back(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_back(ft_iterator_beg, ft_iterator_beg + 5);

    const int stl_const = stl_back.back();
    const int ft_const = ft_back.back();
    std::cout << ((printSingleValue(stl_const, ft_const) == true) ? "[OK]" : "[NOP]");   
}

void vectorAssignRange()
{
    std::cout<< std::endl << "===================================vectorAssignRange===================================" << std::endl;
    
    int range_array[] = {84, 522, -654, -7623, 4};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_assign;
    ft::vector<int> ft_assign;

    stl_assign.assign(stl_iterator_beg, stl_iterator_beg + 5);
    ft_assign.assign(ft_iterator_beg, ft_iterator_beg + 5);
    if (flag)stl_assign, ft_assign) == true) ? "[OK]" : "[NOP]");
    
}

void vectorPushBackEmpty()
{
    std::cout<< std::endl << "===================================vectorPushBackEmpty===================================" << std::endl;
    
    std::vector<int> stl_pushback;
    ft::vector<int> ft_pushback;

    stl_pushback.push_back(42);
    ft_pushback.push_back(42);
    if (flag)
    {
    std::cout << ((printVectorAttributes(stl_pushback, ft_pushback) == true) ? "[OK]" : "[NOP]");
    }
        
}

void vectorPushBack()
{
    std::cout<< std::endl << "===================================vectorPushBack===================================" << std::endl;
    std::vector<int> stl_pushback(7);
    ft::vector<int> ft_pushback(7);

    stl_pushback.push_back(42);
    ft_pushback.push_back(42);
    if (flag)
    {
        std::cout << ((printVectorAttributes(stl_pushback, ft_pushback) == true) ? "[OK]" : "[NOP]");
    }
        
}

void vectorPopBack()
{
    std::cout<< std::endl << "===================================vectorPopBack===================================" << std::endl;
    int range_array[] = {547, 98, -6, 0, 47};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_popback(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_popback(ft_iterator_beg, ft_iterator_beg + 5);

    stl_popback.pop_back();
    ft_popback.pop_back();
    
    if (flag)
    {
        std::cout << ((printVectorAttributes(stl_popback, ft_popback) == true) ? "[OK]" : "[NOP]");
    }
        
}

void vectorInsertSingleElement()
{
    std::cout<< std::endl << "===================================vectorInsertSingleElement===================================" << std::endl;
    
    int range_array[] = {478, 87, -85, 44, 7};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_insert(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_insert(ft_iterator_beg, ft_iterator_beg + 5);

    stl_insert.insert(stl_insert.begin() + 2, 9999);
    ft_insert.insert(ft_insert.begin() + 2, 9999);
    if (flag)
    {
        std::cout << ((printVectorAttributes(stl_insert, ft_insert) == true) ? "[OK]" : "[NOP]");
    }
    
}

void vectorInsertFill()
{
    std::cout<< std::endl << "===================================vectorInsertFill===================================" << std::endl;
    int range_array[] = {47, 152, -325, 9, 14444};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_insert(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_insert(ft_iterator_beg, ft_iterator_beg + 5);

    stl_insert.insert(stl_insert.begin() + 2, 6, 4269);
    ft_insert.insert(ft_insert.begin() + 2, 6, 4269);
    if (flag)
    {
        std::cout << ((printVectorAttributes(stl_insert, ft_insert) == true) ? "[OK]" : "[NOP]");      
    }
}

void vectorEraseSingleElement()
{
    std::cout<< std::endl << "===================================vectorEraseSingleElement===================================" << std::endl;
    int range_array[] = {47, 152, -325, 9, 14444};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_erase(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_erase(ft_iterator_beg, ft_iterator_beg + 5);

    stl_erase.erase(stl_erase.begin() + 2);
    ft_erase.erase(ft_erase.begin() + 2);
    if (flag)
    {
        std::cout << ((printVectorAttributes(stl_erase, ft_erase) == true) ? "[OK]" : "[NOP]");
    }
        
}

void vectorEraseRange()
{
    std::cout<< std::endl << "===================================vectorEraseRange===================================" << std::endl;
    int range_array[] = {1458, -98, 745, 62, 9};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_erase(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_erase(ft_iterator_beg, ft_iterator_beg + 5);

    stl_erase.erase(stl_erase.begin() + 1, stl_erase.end() - 2);
    ft_erase.erase(ft_erase.begin() + 1, ft_erase.end() - 2);
    if (flag)
    {
        std::cout << ((printVectorAttributes(stl_erase, ft_erase) == true) ? "[OK]" : "[NOP]");
    }
}

void vectorSwap()
{
    std::cout<< std::endl << "===================================vectorSwap===================================" << std::endl;
    int range_array_one[] = {1458, -98, 745, 62, 9};
    int range_array_two[] = {478, 87, -15, 44, 7};

    std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));
    std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));
    ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));
    ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));

    std::vector<int> stl_swap_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);
    std::vector<int> stl_swap_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);
    ft::vector<int> ft_swap_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);
    ft::vector<int> ft_swap_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);

    stl_swap_one.swap(stl_swap_two);
    ft_swap_one.swap(ft_swap_two);
    if (flag)
    {
        std::cout << ((printVectorAttributes(stl_swap_one, ft_swap_one) == true) ? "[OK]" : "[NOP]");
        std::cout << ((printVectorAttributes(stl_swap_two, ft_swap_two) == true) ? "[OK]" : "[NOP]");
    }
}

void vectorClear()
{
    std::cout<< std::endl << "===================================vectorClear===================================" << std::endl;
    int range_array[] = {-455, 2, 1347, 75, 945};

    std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));
    ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));

    std::vector<int> stl_clear(stl_iterator_beg, stl_iterator_beg + 5);
    ft::vector<int> ft_clear(ft_iterator_beg, ft_iterator_beg + 5);

    stl_clear.clear();
    ft_clear.clear();
    
    if (flag)
    {
        std::cout << ((printVectorAttributes(stl_clear, ft_clear) == true) ? "[OK]" : "[NOP]");
    }
}

void vectorRealationEqualTrue()
{
    std::cout<< std::endl << "===================================vectorRealationEqualTrue===================================" << std::endl;
    int range_array_one[] = {1458, -98, 745, 62, 9};
    int range_array_two[] = {1458, -98, 745, 62, 9};

    std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));
    std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));
    ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));
    ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));

    std::vector<int> stl_equal_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);
    std::vector<int> stl_equal_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);
    ft::vector<int> ft_equal_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);
    ft::vector<int> ft_equal_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);

    if (flag)
    {
        printVectorAttributes(stl_equal_one, ft_equal_one);
        printVectorAttributes(stl_equal_two, ft_equal_two);
    }

    std::cout << ((printBoolResult((stl_equal_one == stl_equal_two), (ft_equal_one == ft_equal_two))) ? "[OK]" : "[NOP]");
}

void vectorRealationEqualFalse()
{
    std::cout<< std::endl << "===================================vectorRealationEqualFalse===================================" << std::endl;
    int range_array_one[] = {144, 335, 5, 0, -54};
    int range_array_two[] = {1458, -98, 745, 62, 9};

    std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));
    std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));
    ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));
    ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));

    std::vector<int> stl_equal_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);
    std::vector<int> stl_equal_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);
    ft::vector<int> ft_equal_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);
    ft::vector<int> ft_equal_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);

    if (flag)
    {
        printVectorAttributes(stl_equal_one, ft_equal_one);
        printVectorAttributes(stl_equal_two, ft_equal_two);
    }

    std::cout << ((printBoolResult((stl_equal_one == stl_equal_two), (ft_equal_one == ft_equal_two))) ? "[OK]" : "[NOP]");
}

void vectorRealationNotEqualTrue()
{
    std::cout<< std::endl << "===================================vectorRealationNotEqualTrue===================================" << std::endl;
    
    int range_array_one[] = {144, 335, 5, 0, -54};
    int range_array_two[] = {1458, -98, 745, 62, 9};

    std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));
    std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));
    ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));
    ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));

    std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);
    std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);
    ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);
    ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);

    if (flag)
    {
        printVectorAttributes(stl_operator_one, ft_operator_one);
        printVectorAttributes(stl_operator_two, ft_operator_two);
    }

    std::cout << ((printBoolResult((stl_operator_one != stl_operator_two), (ft_operator_one != ft_operator_two))) ? "[OK]" : "[NOP]");
}

void vectorRealationNotEqualFalse()
{
    std::cout<< std::endl << "===================================vectorRealationNotEqualFalse===================================" << std::endl;
    int range_array_one[] = {144, 335, 5, 0, -54};
    int range_array_two[] = {144, 335, 5, 0, -54};

    std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));
    std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));
    ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));
    ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));

    std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);
    std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);
    ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);
    ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);

    if (flag)
    {
        printVectorAttributes(stl_operator_one, ft_operator_one);
        printVectorAttributes(stl_operator_two, ft_operator_two);
    }

    std::cout << ((printBoolResult((stl_operator_one != stl_operator_two), (ft_operator_one != ft_operator_two))) ? "[OK]" : "[NOP]");
}

void vectorSmallTrue()
{
    std::cout<< std::endl << "===================================vectorSmallTrue===================================" << std::endl;
    
    int range_array_one[] = {144, 335, 1, -98, 5};
    int range_array_two[] = {144, 335, 5, 0, -54};

    std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));
    std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));
    ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));
    ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));

    std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);
    std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);
    ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);
    ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);

    if (flag)
    {
        printVectorAttributes(stl_operator_one, ft_operator_one);
        printVectorAttributes(stl_operator_two, ft_operator_two);
    }

    std::cout << ((printBoolResult((stl_operator_one < stl_operator_two), (ft_operator_one < ft_operator_two))) ? "[OK]" : "[NOP]");

}

void vectorSmallFalse()
{
    std::cout<< std::endl << "===================================vectorSmallFalse===================================" << std::endl;
    
    int range_array_one[] = {6780, 335, 1, -98, 5};
    int range_array_two[] = {144, 335, 5, 0, -54};

    std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));
    std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));
    ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));
    ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));

    std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);
    std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);
    ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);
    ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);

    if (flag)
    {
        printVectorAttributes(stl_operator_one, ft_operator_one);
        printVectorAttributes(stl_operator_two, ft_operator_two);
    }

    std::cout << ((printBoolResult((stl_operator_one < stl_operator_two), (ft_operator_one < ft_operator_two))) ? "[OK]" : "[NOP]");
}

void vectorMoreTrue()
{
    std::cout<< std::endl << "===================================vectorMoreTrue===================================" << std::endl;
    
    int range_array_one[] = {144, 9999, 5, 0, -54};
    int range_array_two[] = {144, 335, 5, 0, -54};

    std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));
    std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));
    ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));
    ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));

    std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);
    std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);
    ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);
    ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);

    if (flag)
    {
        printVectorAttributes(stl_operator_one, ft_operator_one);
        printVectorAttributes(stl_operator_two, ft_operator_two);
    }

    std::cout << ((printBoolResult((stl_operator_one > stl_operator_two), (ft_operator_one > ft_operator_two))) ? "[OK]" : "[NOP]");
}

void vectorMoreFalse()
{
    std::cout<< std::endl << "===================================vectorMoreFalse===================================" << std::endl;
    
    int range_array_one[] = {144, 335, 5, 0, -54};
    int range_array_two[] = {144, 335, 77, 0, -54};

    std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));
    std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));
    ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));
    ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));

    std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);
    std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);
    ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);
    ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);

    if (flag)
    {
        printVectorAttributes(stl_operator_one, ft_operator_one);
        printVectorAttributes(stl_operator_two, ft_operator_two);
    }

    std::cout << ((printBoolResult((stl_operator_one > stl_operator_two), (ft_operator_one > ft_operator_two))) ? "[OK]" : "[NOP]");
}