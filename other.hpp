#ifndef OTHER_HPP
#define OTHER_HPP

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>


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

    // class random_access_iterator_tag {};

    

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

    //===================Start pair===================
    template <class T1, class T2>
    struct pair
    {
        public :
            typedef T1 t1;
            typedef T2 t2;
            t1 first;
            t2 second;

            pair(): first(), second(){}

            template<class U, class V>
            pair (const pair<U, V>& pr): first(pr.first), second(pr.second){}


            pair (const t1& a, const t2& b): first(a), second(b){}
            
            pair& operator= (const pair& pr)
            {
                if (*this == pr)
                    return (*this);
                this->first = pr.first;
                this->second = pr.second;
                return (*this);
            }
    };
    //===================End pair===================

    ////===================Start overloads===================
    template <class T1, class T2>
    bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class T1, class T2>
    bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T1, class T2>
    bool operator< (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) &&\
        lhs.second < rhs.second));
        
    }

    template <class T1, class T2>
    bool operator> (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return (rhs < lhs); 
    }

    template <class T1, class T2>
    bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T1, class T2>
    bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return (!(lhs < rhs));
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
    ////===================End overloads===================

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

    //================Start iterator_traits================
    template <class Iterator> struct iterator_traits
    {
        typedef typename Iterator::difference_type       difference_type;
        typedef typename Iterator::value_type            value_type;
        typedef typename Iterator::pointer               pointer;
        typedef typename Iterator::reference             reference;
        typedef typename Iterator::iterator_category     iterator_category;
    };
    
    template <class T> struct iterator_traits<T*>
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef ft::random_access_iterator_tag  iterator_category;
    };

    template <class T> class iterator_traits<const T*>
    {
        typedef         ptrdiff_t                       difference_type;
        typedef         T                               value_type;
        typedef const   T*                              pointer;
        typedef const   T&                              reference;
        typedef         ft::random_access_iterator_tag  iterator_category;
    };
    //================End iterator_traits================

    //================Start distance================
    template <class InputIterator>
    typename ft::iterator_traits<InputIterator>::difference_type 
        distance(InputIterator begin, InputIterator end)
    {
        typename ft::iterator_traits<InputIterator>::difference_type dfrType = 0;
        while(begin != end)
        {
            begin++;
            dfrType++;
        }
        return (dfrType);
    }
    //================End distance================

    //================Start Iterator================
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
    //================End Iterator================

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
    
    //================Start reverse_iterator================
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

            iterator_type base() const
            {
                return (_elem);
            }

            reference operator*() const
            {
                iterator_type result = _elem;
                return (*(--result));
            }

            reverse_iterator operator+ (difference_type n) const
            {
                return (reverse_iterator(_elem - n));
            }

            reverse_iterator operator++(int)
            {
                reverse_iterator result = *this;
                ++(*this);
                return (result);
            }

            reverse_iterator &operator+= (difference_type n)
            {
                _elem -= n;
                return (*this);
            }

            reverse_iterator operator- (difference_type n) const
            {
                return (reverse_iterator(_elem + n));
            }

            reverse_iterator operator-- (int)
            {
                reverse_iterator result = *this;
                --(*this);
                return (result);
            }

            reverse_iterator &operator-= (difference_type n)
            {
                _elem += n;
                return (*this);
            }

            pointer operator->() const
            {
                return &(operator*());
            }

            reference operator[] (difference_type n) const
            {
                return (this->base()[-n - 1]);
            }

        private:
            iterator_type   _elem;
    };
    //================End reverse_iterator================

    //==================Start iterator_overloads==================
    template <class Iterator>
    bool operator== (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class Iterator_L, class Iterator_R>
    bool operator== (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class Iterator_L, class Iterator_R>
    bool operator!= (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <class Iterator>
    bool operator< (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (rhs.base() < lhs.base());
    }

    template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (rhs.base() <= lhs.base());
    }

    template <class Iterator_L, class Iterator_R>
    bool operator< (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class Iterator_L, class Iterator_R>
    bool operator<= (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <class Iterator>
    bool operator> (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) 
    {
        return (lhs.base() < rhs.bash());
    }

    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) 
    {
        return (lhs.base() <= rhs.bash());
    }

    template <class Iterator_L, class Iterator_R>
    bool operator> (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <class Iterator_L, class Iterator_R>
    bool operator>= (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator> &reverse_it)
    {
        return (reverse_it + n);
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() - rhs.base());
    }

    template <class Iterator_L, class Iterator_R>
    bool operator- (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
    {
        return (lhs.base() - rhs.base());
    }
    //==================End iterator_overloads==================

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