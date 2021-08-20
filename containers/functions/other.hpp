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

    //st map
    //==================Start BST_Node==================
    template <typename T>
    struct BST_Node
    {
        public:
            typedef T value_type;

            value_type value;
            BST_Node* parent;
            BST_Node* left;
            BST_Node* right;

            BST_Node (): value(), parent(u_nullptr), left(u_nullptr), right(u_nullptr)
            {}

            BST_Node (BST_Node* parent = u_nullptr, BST_Node* left = u_nullptr, BST_Node* right = u_nullptr):
                value(),
                parent(parent),
                left(left),
                right(right)
            {}

            BST_Node (const value_type& val, BST_Node* parent = u_nullptr, BST_Node* left = u_nullptr, BST_Node* right = u_nullptr):
                value(val),
                parent(parent),
                left(left),
                right(right)
            {}

            BST_Node (const BST_Node& other): value(other.value), parent(other.parent), left(other.left), right(other.right)
            {}

            virtual ~BST_Node() {}

            BST_Node &operator=(const BST_Node& other)
            {
                if (other == *this)
                    return (*this);
                this->value = other.value;
                this->parent = other.parent;
                this->left = other.left;
                this->right = other.right;
                return (*this);
            }

            bool operator==(const BST_Node& other)
            {
                if (value == other.value)
                    return (true);
                return (false);
            }
    };
    //===================End BST_Node===================

    //===================Start Doubly_Linked_Node===================
    template <class Data_T>
    struct Doubly_Linked_Node 
    {
        public :
            Data_T              data;
            Doubly_Linked_Node  *prev;
            Doubly_Linked_Node  *next;
            Doubly_Linked_Node(): prev(u_nullptr), next(u_nullptr)
            {}

            Doubly_Linked_Node(const Data_T& val): prev(u_nullptr), next(u_nullptr), data(val)
            {}

            Doubly_Linked_Node(const Data_T& val, Doubly_Linked_Node *prev, Doubly_Linked_Node *next):
                prev(prev),
                next(next),
                data(val)
            {}
    };
    //===================End Doubly_Linked_Node===================
    //end map

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

    //===================Start InvalidIteratorException===================
    template <typename T>
    class InvalidIteratorException : public std::exception
    {
        private:
            std::string _str;
        public:
            InvalidIteratorException () throw()
            {
                _str = "Is invalid iterator tag: " + std::string(typeid(T).name());
            }
            InvalidIteratorException (const InvalidIteratorException&) throw()
            {}
            InvalidIteratorException &operator=(const InvalidIteratorException&) throw()
            {}
            virtual ~InvalidIteratorException() throw()
            {}
            virtual const char * what() const throw()
            {
                return (_str.c_str());
            }
    };
    //===================End InvalidIteratorException===================
}
#endif