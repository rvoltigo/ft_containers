#ifndef OTHER_HPP
#define OTHER_HPP

#include <iostream>
#include <sstream>
#include <typeinfo>
#include <vector>

static class nullptr_t
{
    private:
        void operator&() const;
    public:
        template<class T>
        operator T*() const {return (0); }

        template<class A, class T>
        operator T A::*() const {return (0); }
} u_nullptr = {};

namespace ft
{
    //converting
    template <typename T>
    std::string to_string(T value)
    {
        std::ostringstream resultString;
        resultString << value;
        return (resultString.str());
    }

    // template <class A, class B, class Result>
    // struct binary_function
    // {
    //     typedef A first_argument_type;

    //     typedef B second_argument_type;

    //     typedef Result result_type;
    // };

    class random_access_iterator_tag { };

    template <class Category, class T, class Distance = ptrdiff_t,
        class Pointer = T*, class Reference = T&>
    class iterator
    {
        public:
            typedef T           value_type;
            typedef Distance    difference_type;
            typedef Pointer     pointer;
            typedef Reference   reference;
            typedef Category    iterator_category;
    };

    //iterator_traits
    template <class Iterator> struct iterator_traits
    {
        typedef typename Iterator::difference_type       difference_type;
        typedef typename Iterator::value_type            value_type;
        typedef typename Iterator::pointer               pointer;
        typedef typename Iterator::reference             reference;
        typedef typename Iterator::iterator_category     iterator_category;
    };
    
    //struct iterator_traits
    template <class T> struct iterator_traits<T*>
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef ft::random_access_iterator_tag  iterator_category;
    };

    //class struct const iterator_traits
    template <class T> class iterator_traits<const T*>
    {
        typedef         ptrdiff_t                       difference_type;
        typedef         T                               value_type;
        typedef const   T*                              pointer;
        typedef const   T&                              reference;
        typedef         ft::random_access_iterator_tag  iterator_category;
    };

    // create reverse_iterator
    template <class Iterator>
    class reverse_iterator
    {

        public:
            typedef             Iterator                                           iterator_type;
            typedef typename    ft::iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename    ft::iterator_traits<Iterator>::value_type          value_type;
            typedef typename    ft::iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename    ft::iterator_traits<Iterator>::pointer             pointer;
            typedef typename    ft::iterator_traits<Iterator>::reference           reference;

            reverse_iterator() : _elem() {}

            explicit reverse_iterator(iterator_type iterator) : _elem(iterator) {}

            template <class Iter>
            reverse_iterator(const reverse_iterator<Iter>& reverse_it): _elem(reverse_it.base()) {}

            virtual ~reverse_iterator() {}
        private:

            iterator_type   _elem;
            

    };

    template <class T1, class T2>
    struct pair
    {
        public :
            typedef T1 t1;
            typedef T2 t2;
            t1 arg1;
            t2 arg2;

            pair(): first(), second(){}

            template<class U, class V>
            pair (const pair<U, V>& pr): first(pr.arg1), second(pr.arg2){}


            pair (const t1& a, const t2& b): first(a), second(b){}
            
            pair& operator= (const pair& pr)
            {
                if (*this == pr)
                    return (*this);
                this->arg1 = pr.arg1;
                this->arg2 = pr.arg2;
                return (*this);
            }
    };

    template <class T1, class T2>
    bool operator== (const ft::pair<T1,T2>& firstArg, const ft::pair<T1,T2>& secondArg)
    {
        return (firstArg.arg1 == secondArg.arg1 && firstArg.arg2 == secondArg.arg2);
    }

    template <class T1, class T2>
    bool operator!= (const ft::pair<T1,T2>& firstArg, const ft::pair<T1,T2>& secondArg)
    {
        return (firstArg != secondArg);
    }

    template <class T1, class T2>
    bool operator< (const ft::pair<T1,T2>& firstArg, const ft::pair<T1,T2>& secondArg)
    {
        return (firstArg.arg1 < secondArg.arg1 || (!(firstArg.arg1 < secondArg.arg1) &&\
        firstArg.arg1 < secondArg.arg2));
    }

    template <class T1, class T2>
    bool operator> (const ft::pair<T1,T2>& firstArg, const ft::pair<T1,T2>& secondArg)
    {
        return (firstArg > secondArg); 
        // (firstArg.arg1 < secondArg.arg1 || (!(firstArg.arg1 < secondArg.arg1) &&\
        // firstArg.arg1 < secondArg.arg2));
    }

    template <class T1, class T2>
    bool operator<= (const ft::pair<T1,T2>& firstArg, const ft::pair<T1,T2>& secondArg)
    {
        return (secondArg > firstArg);
    }

    template <class T1, class T2>
    bool operator>= (const ft::pair<T1,T2>& firstArg, const ft::pair<T1,T2>& secondArg)
    {
        return (firstArg > secondArg);
    }

    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (ft::pair<T1, T2>(x, y));
    }
    
    template<bool Cond, class T = void> struct enable_if 
    {};

    template<class T> struct enable_if<true, T> 
    { 
        typedef T type; 
    };

    template <bool is_integral, typename T>
    struct is_integral_res 
    {
        typedef T type;
        static const bool value = is_integral;
    };

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

    class random_access_iterator_tag {};
    class bidirectional_iterator_tag {};
    class forward_iterator_tag {};
    class input_iterator_tag {};
    class output_iterator_tag {};

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
        : public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };

    template <>
    struct is_input_iterator_tagged<ft::bidirectional_iterator_tag> //bidirectional is input!
        : public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

    template <>
    struct is_input_iterator_tagged<ft::forward_iterator_tag> //forward is input!
        : public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };

    template <>
    struct is_input_iterator_tagged<ft::input_iterator_tag>
        : public valid_iterator_tag_res<true, ft::input_iterator_tag> { };




}


#endif


