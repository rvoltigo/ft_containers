#ifndef RANDOM_ITERATOR_HPP
#define RANDOM_ITERATOR_HPP

#include "functions.hpp"

namespace ft
{
    template <typename T>
    class random_access_iterator: ft::iterator<ft::random_access_iterator_tag, T>
    {
        public:
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;

            typedef T*      pointer;
            typedef T&      reference;

            random_access_iterator(): _value(u_nullptr)
            {
            }

            random_access_iterator(pointer value): _value(value)
            {
            }

            random_access_iterator(const random_access_iterator &other): _value(other._value)
            {
            }

            virtual ~random_access_iterator()
            {
            }

            random_access_iterator &operator=(const random_access_iterator &other)
            {
                if (this != &other)
                    this->_value = other._value;
                return (*this);
            }

            pointer base() const
            {
                return (this->_value);
            }

            reference operator*() const
            {
                return (*_value);
            }

            pointer operator->()
            {
                return &(this->operator*());
            }

            random_access_iterator &operator++()
            {
                _value++;
                return (*this);
            }

            random_access_iterator &operator--()
            {
                _value--;
                return (*this);
            }

            random_access_iterator operator++(int)
            {
                random_access_iterator result(*this);
                operator++();
                return (result);
            }

            random_access_iterator operator--(int)
            {
                random_access_iterator result(*this);
                operator--();
                return (result);
            }

            random_access_iterator operator+(difference_type number) const 
            {
                return (_value + number);
            }

            random_access_iterator operator-(difference_type number) const 
            {
                return (_value - number);
            }

            random_access_iterator &operator+=(difference_type number)
            {
                _value += number;
                return (*this);
            }

            random_access_iterator &operator-=(difference_type number)
            {
                _value -= number;
                return (*this);
            }


            reference operator[](difference_type number) 
            {
                return (*(operator+(number)));
            }

            operator random_access_iterator<const T> () const
            {
                return (random_access_iterator<const T>(this->_value));
            }

            private:
                pointer _value;
    };

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator== (const ft::random_access_iterator<T> arg1,
              const ft::random_access_iterator<T> arg2)
    {
        return (arg1.base() == arg2.base());
    }

    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator== (const ft::random_access_iterator<T_L> arg1,
              const ft::random_access_iterator<T_R> arg2)
    {
        return (arg1.base() == arg2.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator!= (const ft::random_access_iterator<T> arg1,
              const ft::random_access_iterator<T> arg2)
    {
        return (arg1.base() != arg2.base());
    }

    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator!= (const ft::random_access_iterator<T_L> arg1,
              const ft::random_access_iterator<T_R> arg2)
    {
        return (arg1.base() != arg2.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator< (const ft::random_access_iterator<T> arg1,
              const ft::random_access_iterator<T> arg2)
    {
        return (arg1.base() < arg2.base());
    }

    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator< (const ft::random_access_iterator<T_L> arg1,
              const ft::random_access_iterator<T_R> arg2)
    {
        return (arg1.base() < arg2.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator> (const ft::random_access_iterator<T> arg1,
              const ft::random_access_iterator<T> arg2)
    {
        return (arg1.base() > arg2.base());
    }

    template<typename T_L,
             typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator> (const ft::random_access_iterator<T_L> arg1,
              const ft::random_access_iterator<T_R> arg2)
    {
        return (arg1.base() > arg2.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<= (const ft::random_access_iterator<T> arg1,
              const ft::random_access_iterator<T> arg2)
    {
        return (arg1.base() <= arg2.base());
    }

    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator<= (const ft::random_access_iterator<T_L> arg1,
              const ft::random_access_iterator<T_R> arg2)
    {
        return (arg1.base() <= arg2.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>= (const ft::random_access_iterator<T> arg1,
              const ft::random_access_iterator<T> arg2)
    {
        return (arg1.base() >= arg2.base());
    }

    template<typename T_L,
             typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator>=(const ft::random_access_iterator<T_L> arg1,
              const ft::random_access_iterator<T_R> arg2)
    {
        return (arg1.base() >= arg2.base());
    }

    template<typename T>
    ft::random_access_iterator<T> operator+ (
    typename ft::random_access_iterator<T>::difference_type number,
    typename ft::random_access_iterator<T> &arg)
    {
        return (&(*arg) + number);
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator- (const ft::random_access_iterator<T> arg1,
              const ft::random_access_iterator<T> arg2)
    {
        return (arg1.base() - arg2.base());
    }

    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator- (const ft::random_access_iterator<T_L> arg1,
              const ft::random_access_iterator<T_R> arg2)
    {
        return (arg1.base() - arg2.base());
    }
}

#endif