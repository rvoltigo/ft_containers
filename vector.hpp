#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
#include "other.hpp"
#include "random_iterator.hpp"

using namespace std;

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T                                                       value_type;
            typedef Alloc                                                   allocator_type;
            
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
			typedef typename allocator_type::pointer                        pointer;//a pointer to an element stored
			typedef typename allocator_type::const_pointer                  const_pointer;
            typedef typename allocator_type::size_type                      size_type;//unsigned integral type

            typedef ft::random_access_iterator<value_type>                  iterator;
			typedef ft::random_access_iterator<const value_type>            const_iterator;
			typedef ft::reverse_iterator<iterator>                          reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type; //signed integral type

            //=============#1 START MEMBER FUNCTIONS #1=============

            explicit vector(const allocator_type &allocate = allocator_type()):
                _alloc(allocate),
                _first(u_nullptr),
                _last(u_nullptr),
                _last_cap(u_nullptr)
            {}

            explicit vector(size_t n, const value_type &var = value_type(),
                    const allocator_type &allocate = allocator_type()):
                _alloc(allocate)
            {
                _first = _alloc.allocate(n);
                _last_cap = _first + n;
                _last = _first;
                while (n--)
                    _alloc.constructor(_last++, var);
            }

            vector (const vector& x): //Constructs a container with a copy of each of the elements in x, in the same order.
				_alloc(x._alloc),
				_first(u_nullptr),
				_last(u_nullptr),
				_last_cap(u_nullptr)
			{
				this->insert(this->begin(), x.begin(), x.end());
			}

            ~vector()
			{
				this->clear();
				_alloc.deallocate(_first, this->capacity());
			}

            vector &operator=(const vector &other)
			{
				if (other != *this)
                {
					this->clear();
				    this->insert(this->end(), other.begin(), other.end());
                }
				return (*this);
			}

            //==============#1 END MEMBER FUNCTIONS #1==============

            //=============#2 START ITERATORS #2=============
            
            iterator begin()
            {
                return (_first);
            }

            iterator end()
            {
                if (this->empty())
                    return (this->begin());
                return (_last);
            }

            const_iterator begin() const
            {
                return (_first);
            }

            const_iterator end() const
            {
                if (this->empty())
                    return (this->begin());
                return (_last);
            }

            reverse_iterator rbegin()
            {
                return (reverse_iterator(this->end()));
            }

            reverse_iterator rend()
            {
                return (reverse_iterator(this->begin()));
            }

            const_reverse_iterator rbegin() const 
            {
                return (reverse_iterator(this->end()));
            }

            const_reverse_iterator rend() const 
            {
                return (reverse_iterator(this->begin()));
            }
            // begin
            // end
            // rbegin
            // rend

            //==============#2 END ITERATORS #2==============


            //=============#3 START CAPACITY #3=============
            
            size_type size() const
            {
                return (this->_last - this->_first);
            }

            size_type max_size() const
            {
                return (allocator_type().max_size());
            }

            void resize (size_type count, value_type variable = value_type())
			{
                if (count < this->max_size())
                {
                    while (this->size() > count)
                    {
                        --_last;
                        _alloc.destroy(_last);
                    }
                }
                else if (count > this->max_size())
                    throw (std::length_error("vector::resize"));
				else
					this->insert(this->end(), count - this->size(), variable);
			}

            size_type capacity() const
            {
                return (this->_last_capacity - this->_start);
            }

            bool empty () const
            {
                if (size() == 0)
                    return (true);
                return (false);
            }

            void        reserve (size_type length)
			{
                if (length > this->max_size())
                    throw (std::length_error("vector::reserve"));
                else if (length > this->capacity())
                {
                    pointer     prev_first = _first;
                    pointer     prev_last = _last;
                    size_type   prev_size = this->size();
                    size_type   prev_capacity = this->capacity();

                    _first = _alloc.allocate(length);
                    _last_capacity = _first + length;
                    _last = _first;

                    while (prev_first != prev_last)
                    {
                        _alloc,construct(_last, *prev_first);
                        _last++;
                        prev_first++;
                    }
                    _alloc.deallocate(prev_first - prev_size, prev_capacity);
                }
			}

            //==============#3 END CAPACITY #3==============



            //=============#4 START ELEMENT ACCESS #4=============
            
            reference operator[] (size_type n)
            {
                return (*(_first + n));
            }

            const_reference operator[] (size_type n) const
            {
                return (*(_first + n));
            }

            reference at (size_type n)
			{
				checkRange(n);
				return ((*this)[n]);
			}

            // operator[]
            // at
            // front
            // back

            //==============#4 END ELEMENT ACCESS #4==============



            //=============#5 START MODIFIERS #5=============
            
            // assign
            // push_back
            // pop_back
            // insert
            // erase
            // swap
            // clear

            //==============#5 END MODIFIERS #5==============




            //=============#6 START ALLOCATOR #6=============

            // get_allocator

            //==============#6 END ALLOCATOR #6==============




            //=============#7 START NON-MEMBER #7=============
            
            // relational operators
            // swap

            //==============#7 END NON-MEMBER #7==============

        private:
            allocator_type  _alloc;
            pointer         _first;
            pointer         _last;
            pointer         _last_cap;//??
			
            void checkRange(const size_type& n) const
			{
				if (n >= this->size())
					throw (std::out_of_range("vector::checkRange: n (which is "
							+ ft::to_string(n) + ") >= this->size() (which is "
							+ ft::to_string(this->size()) + ")"));
			}

    };
}

#endif