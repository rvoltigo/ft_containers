#ifndef VECTOR_UTILS_HPP
#define VECTOR_UTILS_HPP

#include "../test.hpp"
#include "../../vector.hpp"
#include <vector>

template <class T>
std::string equalContent(
    const std::vector<T> & stl_vector,
    const ft::vector<T> & ft_vector
)
{
    typename ft::vector<T>::const_iterator ft_it;
    typename std::vector<T>::const_iterator stl_it;
    if (ft_vector.size() != stl_vector.size())
        return ("✘");
    stl_it = stl_vector.begin();
    for(ft_it = ft_vector.begin(); ft_it != ft_vector.end(); ft_it++)
    {
        if (*ft_it != *stl_it)
            return ("✘");
        stl_it++;
    }
    return ("✔");
}

template <class T>
bool showInfoVector(
    std::vector<T>& stl_vector,
    ft::vector<T>& ft_vector
)
{
    /* STL Values */
    std::string stl_empty = ((stl_vector.empty() == 1) ? "true" : "false");
    size_t stl_size = stl_vector.size();
    size_t stl_max_size = stl_vector.max_size();
    size_t stl_capacity = stl_vector.capacity();

    /* FT Values */
    std::string ft_empty = ((ft_vector.empty() == 1) ? "true" : "false");
    size_t ft_size = ft_vector.size();
    size_t ft_max_size = ft_vector.max_size();
    size_t ft_capacity = ft_vector.capacity();

    /* FT Result compare values */
    bool empty = equalbool(ft_empty, stl_empty);
    bool size = equalbool(ft_size, stl_size);
    bool max_size = equalbool(ft_max_size, stl_max_size);
    bool capacity = equalbool(ft_capacity, stl_capacity);
    std::string content = equalContent(stl_vector, ft_vector);
    
    std::cout << "\n══════════════════════════════════════════════════════════════\n";
    std::cout << "Vectors attributes : \n";
    std::cout << "STL : \n";
    std::cout << "Empty       : " << stl_empty  << std::endl;
    std::cout << "Size        : " << stl_size  << std::endl;
    std::cout << "Max size    : " << stl_max_size  << std::endl;
    std::cout << "Capacity    : " << stl_capacity  << std::endl;
    std::cout << "Content     : [";
    
    typename std::vector<T>::const_iterator stl_it;
    for (stl_it = stl_vector.begin();  stl_it != stl_vector.end(); stl_it++)
    {
        std::cout << *stl_it;
        if (stl_it + 1 != stl_vector.end())
            std::cout << ", ";
    }
    std::cout << "]\n";

    std::cout << std::endl;

    std::cout << "FT : \n";
    std::cout << "Empty    [" << equal(ft_empty, stl_empty) << "]: " << ft_empty  << std::endl;
    std::cout << "Size     [" << equal(ft_size, stl_size) << "]: " << ft_size  << std::endl;
    std::cout << "Max size [" << equal(ft_max_size, stl_max_size) << "]: " << ft_max_size  << std::endl;
    std::cout << "Capacity [" << equal(ft_capacity, stl_capacity) << "]: " << ft_capacity  << std::endl;

    std::cout << "Content  [" << content << "]: [";

    typename ft::vector<T>::const_iterator ft_it;
    for(ft_it = ft_vector.begin(); ft_it != ft_vector.end(); ft_it++)
    {
        std::cout << *ft_it;
        if (ft_it + 1 != ft_vector.end())
            std::cout << ", ";
    }
    std::cout << "]\n";

    std::cout << "══════════════════════════════════════════════════════════════\n";

    /* Error case */
    if (empty == false)
        return (false);
    else if (size == false)
        return (false);
    else if (max_size == false)
        return (false);
    else if (capacity == false)
        return (false);
    else if (content == "✘")
        return (false);
    return (true);
}

void vector_Default_constructor();
void vector_CopyConstructor();
void vector_RangeConstructor();

void vector_FillConstructor();
void vector_FillConstructorSizedValue();
void vectorAssignOperator();
void vectorIteratorBegin();
void vectorConstIteratorBegin();
void vectorIteratorEnd();
void vectorConstIteratorEnd();
void vectorIteratorRbegin();
void vectorConstIteratorRbegin();
void vectorIteratorRend();
void vectorConstIteratorRend();
void vecotSizeMaximum();
void vectorResize();
void vectorEmtyTrue();
void vectorEmtyFalse();
void vectorOperator();
void vectorConstOperator();
void vectorAt();
void vectorConstAt();
void vectorFront();
void vectorConstFront();
void vectorBack();
void vectorConstBack();
void vectorAssignRange();
void vectorPushBackEmpty();
void vectorPushBack();
void vectorPopBack();
void vectorInsertSingleElement();
void vectorInsertFill();
void vectorEraseSingleElement();
void vectorEraseRange();
void vectorSwap();
void vectorClear();
void vectorRealationEqualTrue();
void vectorRealationEqualFalse();
void vectorRealationNotEqualTrue();
void vectorRealationNotEqualFalse();
void vectorSmallTrue();
void vectorSmallFalse();
void vectorMoreTrue();
void vectorMoreFalse();



#endif