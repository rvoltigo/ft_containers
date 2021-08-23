#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
    //===================Start pair===================
    template <class T1, class T2>
    struct pair
    {
        public :
            typedef T1 t1;
            typedef T2 t2;
            t1 first;
            t2 second;

            pair(): first(t1()), second(t2()){};

            pair (const t1& a, const t2& b): first(a), second(b)
            {
            };

            template<class U, class V>
            pair (const pair<U, V>& pr): first(pr.first), second(pr.second)
            {   
            };
            
            ~pair()
            {
            };
            
            pair& operator= (const pair& pr)
            {
                if (*this == pr)
                    return (*this);
                this->first = pr.first;
                this->second = pr.second;
                return (*this);
            };
    };
    //===================End pair===================

    //===================Start pair overloads===================
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
    //===================End pair overloads===================
}


#endif