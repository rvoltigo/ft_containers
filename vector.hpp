#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory> //allocator
#include <algorithm> //?!
#include <cstddef> //??
#include <iostream>

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

            // typedef ft::random_access_iterator<value_type>                  iterator;
			// typedef ft::random_access_iterator<const value_type>            const_iterator;
			// typedef ft::reverse_iterator<iterator>                          reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
			// typedef typename ft::iterator_traits<iterator>::difference_type difference_type; //signed integral type

            //=============#1 START MEMBER FUNCTIONS #1=============

            explicit vector(const allocator_type &allocate = allocator_type()):
                _allocate(allocate),
                _begin(u_nullptr),
                _end(u_nullptr),
                _end_cap(u_nullptr)
            {}

            explicit vector(size_t n, const value_type &var = value_type(),
                    const allocator_type &allocate = allocator_type()):
                _allocate(allocate),
            {
                _begin = _allocate.allocate(n);
                _end_cap = _begin + n;
                _end = _begin;
                while (n--)
                    _allocate.constructor(_end++, var);
            }

            vector (const vector& x): //Constructs a container with a copy of each of the elements in x, in the same order.
				_allocate(x._alloc),
				_begin(u_nullptr),
				_end(u_nullptr),
				_end_cap(u_nullptr)
			{
				this->insert(this->begin(), x.begin(), x.end());
			}

            ~vector()
			{
				this->clear();
				_alloc.deallocate(_start, this->capacity());
			}

            vector &operator=(const vector& other)
			{
				// if (other == *this)
				// 	return (*this);
				this->clear();
				this->insert(this->end(), other.begin(), other.end());
				return (*this);
			}

            //==============#1 END MEMBER FUNCTIONS #1==============

            //=============#2 START ITERATORS #2=============
            
            // begin
            // end
            // rbegin
            // rend

            //==============#2 END ITERATORS #2==============


            //=============#3 START CAPACITY #3=============
            
            // size
            // max_size
            // resize
            // capacity
            // empty
            // reserve

            //==============#3 END CAPACITY #3==============



            //=============#4 START ELEMENT ACCESS #4=============
            
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
            allocator_type  _allocate;
            pointer         _begin;
            pointer         _end;
            pointer         _end_cap;//??
			
            // void checkRange(const size_type& n) const
			// {
			// 	if (n >= this->size())
			// 		throw (std::out_of_range("vector::checkRange: n (which is "
			// 				+ ft::to_string(n) + ") >= this->size() (which is "
			// 				+ ft::to_string(this->size()) + ")"));
			// }

    };
}

#endif