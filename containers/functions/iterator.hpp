#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{

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

            reverse_iterator& operator++()
            {
                --_elem;
                return (*this);
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

            reverse_iterator& operator--()
            {
                ++_elem;
                return (*this);
            }

            reverse_iterator operator--(int)
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
        return (lhs.base() < rhs.base());
    }

    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) 
    {
        return (lhs.base() <= rhs.base());
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

    //================End reverse_iterator================
}

#endif