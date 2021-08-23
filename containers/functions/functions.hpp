#ifndef OTHER_HPP
#define OTHER_HPP

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>
# include "empty_classes.hpp"
# include "iterator_traits.hpp"
# include "iterator.hpp"
# include "pair.hpp"


//================Start u_nullptr================
static class nullptr_t
{
    public:
        template<class T>
        operator T*() const
        {
            return (0);
        }

        template<class A, class T>
        operator T A::*() const
        {
            return (0);
        }
    private:
        void operator&() const;
} u_nullptr = {};
//================End u_nullptr================

namespace ft
{
    //================Start to_string================
    template <typename T>
    std::string to_string(T value)
    {
        std::ostringstream resultString;
        resultString << value;
        return (resultString.str());
    }
    //================End to_string================

    //================Start binary_function================
    template <class A, class B, class Result>
    struct binary_function
    {
        typedef A first_argument_type;

        typedef B second_argument_type;

        typedef Result result_type;
    };

    template <class T>
    struct less : binary_function<T, T, bool>
    {
        bool operator() (const T& x, const T& y) const
        {
            return(x < y);
        }
    };
    //================End binary_function================

    //==================Start lexicographical_compare==================
    template <class IteratorInputFirst, class IteratorInputSecond>
    bool lexicographical_compare(IteratorInputFirst beginFirst, IteratorInputFirst endFirst,
                                    IteratorInputSecond beginSecond, IteratorInputSecond endSecond)
    {
        while (beginFirst != endFirst)
        {
            if (*beginFirst < *beginSecond)
                return true;
            else if (beginSecond == endSecond || *beginFirst > *beginSecond)
                return false;
            ++beginFirst;
            ++beginSecond;
        }
        return (beginSecond != endSecond);
    }                                

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare (InputIterator1 beginFirst, InputIterator1 endFirst,
                                    InputIterator2 beginSecond, InputIterator2 endSecond,
                                    Compare compr)
    {
        while (beginFirst != endFirst)
        {
            if (beginSecond == endSecond || compr(*beginSecond, *beginFirst)) 
                return false;
            else if (compr(*beginFirst, *beginSecond)) 
                return true;
            ++beginFirst;
            ++beginSecond;
        }
        return (beginSecond != endSecond);
    }
    //==================End lexicographical_compare==================

    //=================Start Types=================

    template <typename>
    struct is_integral_type : public is_integral_res<false, bool> {};

    template <>
    struct is_integral_type<bool> : public is_integral_res<true, bool> {};

    template <>
    struct is_integral_type<char> : public is_integral_res<true, char> {};
    
    template <>
    struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};

    template <>
    struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};

    template <>
    struct is_integral_type<int> : public is_integral_res<true, int> {};

    template <>
    struct is_integral_type<short int> : public is_integral_res<true, short int> {};

    template <>
    struct is_integral_type<long int> : public is_integral_res<true, long int> {};

    template <>
    struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};

    template <>
    struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};

    template <>
    struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};

    template <>
    struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};

    template <>
    struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

    template <typename T>
    struct is_integral : public is_integral_type<T> {};

    //==================End Types==================

    //================Start bidirectional_iterator================
    template <class T>
    class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type        value_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type   difference_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer           pointer;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference         reference;

        private:
            pointer _elem;
    };
    //================End bidirectional_iterator================

    template <bool is_valid, typename T>
    struct valid_iterator_tag_res 
    {
        typedef T type; const static bool value = is_valid;
    };

    //default = false
    template <typename T>
    struct is_input_iterator_tagged : public valid_iterator_tag_res<false, T> {};

    //if input == random
    template <>
    struct is_input_iterator_tagged<ft::random_access_iterator_tag> 
        : public valid_iterator_tag_res<true, ft::random_access_iterator_tag> {};

    //bidirectional is input!
    template <>
    struct is_input_iterator_tagged<ft::bidirectional_iterator_tag> 
        : public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> {};

    //forward is input!
    template <>
    struct is_input_iterator_tagged<ft::forward_iterator_tag> 
        : public valid_iterator_tag_res<true, ft::forward_iterator_tag> {};

    template <>
    struct is_input_iterator_tagged<ft::input_iterator_tag>
        : public valid_iterator_tag_res<true, ft::input_iterator_tag> {};


    //===================Start is_ft_iterator_tagged===================
    template <typename T>
        struct is_ft_iterator_tagged : public valid_iterator_tag_res<false, T> { }; //false by default

    template <>
        struct is_ft_iterator_tagged<ft::random_access_iterator_tag>
            : public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };

    template <>
        struct is_ft_iterator_tagged<ft::bidirectional_iterator_tag>
            : public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

    template <>
        struct is_ft_iterator_tagged<ft::forward_iterator_tag>
            : public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };

    template <>
        struct is_ft_iterator_tagged<ft::input_iterator_tag>
            : public valid_iterator_tag_res<true, ft::input_iterator_tag> { };

    template <>
        struct is_ft_iterator_tagged<ft::output_iterator_tag>
            : public valid_iterator_tag_res<true, ft::output_iterator_tag> { };
    //===================End is_ft_iterator_tagged===================
}
#endif