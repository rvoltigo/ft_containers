#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
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
}

#endif