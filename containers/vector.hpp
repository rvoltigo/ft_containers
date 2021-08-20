#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

#include "functions/other.hpp"
#include "functions/random_iterator.hpp"

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
				_last_capacity(u_nullptr)
			{}

			explicit vector(size_t n, const value_type &var = value_type(),
					const allocator_type &allocate = allocator_type()):
				_alloc(allocate)
			{
				_first = _alloc.allocate(n);
				_last_capacity = _first + n;
				_last = _first;
				while (n--)
					_alloc.constructor(_last++, var);
			}

			vector (const vector& x): //Constructs a container with a copy of each of the elements in x, in the same order.
				_alloc(x._alloc),
				_first(u_nullptr),
				_last(u_nullptr),
				_last_capacity(u_nullptr)
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

			void resize (size_type n, value_type val = value_type())
			{
				if (n < this->max_size())
				{
					while (this->size() > n)
					{
						--_last;
						_alloc.destroy(_last);
					}
				}
				else if (n > this->max_size())
					throw (std::length_error("vector::resize"));
				else
					this->insert(this->end(), n - this->size(), val);
			}

			size_type capacity() const
			{
				return (this->_last_capacity - this->_first);
			}

			bool empty () const
			{
				if (size() == 0)
					return (true);
				return (false);
			}

			void reserve (size_type n)
			{
				if (n > this->max_size())
					throw (std::length_error("vector::reserve"));
				else if (n > this->capacity())
				{
					pointer     prev_first = _first;
					pointer     prev_last = _last;
					size_type   prev_size = this->size();
					size_type   prev_capacity = this->capacity();

					_first = _alloc.allocate(n);
					_last_capacity = _first + n;
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

			reference at(size_type n)
			{
				checkRange(n);
				return ((*this)[n]);
			}

			const_reference at(size_type n) const
			{
				checkRange(n);
				return ((*this)[n]);
			}

			reference front()
			{
				return (*_first);
			}

			const_reference front() const
			{
				return (*_first);
			}

			reference back()
			{
				return (*(_last - 1));
			}

			const_reference back() const
			{
				return (*(_last - 1));
			}

			//==============#4 END ELEMENT ACCESS #4==============



			//=============#5 START MODIFIERS #5=============
			
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr)
			{
				bool isValid = ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::value;
				if (!isValid)
					throw (ft::InvalidIteratorException<typename ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());
				this->clear();
				size_type dist = ft::distance(first, last);
				if (size_type(_last_capacity - _first) >= dist)
				{
					for (; &(*first) != &(*last); first++, _last++)
						_alloc.construct(_last, *first);
				}
				else
				{
					pointer new_first = _alloc.allocate(dist);
					pointer new_last = new_first;
					pointer new_last_capacity = new_first + dist;

					for (; &(*first) != &(*last); first++, new_last++)
						_alloc.constructor(new_last, *first);
					
					_alloc.deallocate(_first, this->capacity());

					_first = new_first;
					_last = new_last;
					_last_capacity = new_last_capacity;
				}
			}

			void assign (size_type n, const value_type &val)
			{
				this->clear();
				if (n == 0)
					return ;
				if (n >= size_type(_last_capacity - _first))
				{
					_alloc.deallocate(_first, this->capacity());
					_first = _alloc.allocate(n);
					_last = _first;
					_last_capacity = _first + n;
					while (n)
					{
						_alloc.constructor(_last++, val);
						n--;
					}
				}
				else
				{
					while(n)
					{
						_alloc.constructor(_last++, val);
						n--;
					}
				}
			}

			void push_back (const value_type &val)
			{
				if (_last == _last_capacity)
				{
					int next_capacity = 0;
					if (this->size() > 0)
						next_capacity = (int)(this->size() * 2);
					else
						next_capacity = 1;
					this->reserve(next_capacity);
				}
				_alloc.constructor(_last, val);
				_last++;
			}

			void pop_back()
			{
				_alloc.destroy(&this->back());
				_last--;
			}
			
			iterator erase(iterator position)
			{
				pointer tmp_pos = &(*position);
				_alloc.destroy(&(*position));

				if (&(*position) + 1 == _last)
					_alloc.destroy(&(*position));
				else
				{
					for (int i = 0; _last - &(*position) - 1; i++)
					{
						_alloc.constructor(&(*position) + i, (&(*position) + i + 1));
						_alloc.destroy(&(*position) + i + 1);
					}
				}
				_last -= 1;
				return (iterator(tmp_pos));
			}

			iterator erase(iterator first, iterator last)
			{
				pointer tmp_pos = &(*first);
				for (; &(*first) != &(*last); first++)
					_alloc.destroy(&(*first));
				for (int i = 0; i < _last - &(*last); i++)
				{
					_alloc.constructor(tmp_pos + i, *(&(*last) + i));
					_alloc.destroy(&(*last) + i);
				}
				_last -= (&(*last) - tmp_pos);
				return (iterator(tmp_pos));
			}

			void clear()
			{
				size_type length = this->size();
				for (size_type i = 0; i < length; i++)
				{
					_last--;
					_alloc.destroy(_last);
				}
			}

			void swap (vector &x)
			{
				if (x == *this)
					return ;
				pointer         tmp_first = x._first;
				pointer         tmp_last = x._last;
				pointer         tmp_last_capacity = x._last_capacity;
				allocator_type  tmp_alloc = x._alloc;

				x._first = this->_first;
				x._last = this->_last;
				x._last_capacity = this->_last_capacity;
				x._alloc = this->_alloc;

				this->_first = tmp_first;
				this->_last = tmp_last;
				this->_last_capacity = tmp_last_capacity;
				this->_alloc = tmp_alloc;
			}

			//============= START INSERT =============
			iterator insert(iterator position, const value_type& val)
			{
				size_type pos_len = &(*position) - _first;
				if (size_type(_last_capacity - _last) >= this->size() + 1)
				{
					for (size_type i = 0; i < pos_len; i++)
						_alloc.construct(_last - i, *(_last - i - 1));
					_last++;
					_alloc.construct(&(*position), val);
				}
				else
				{
					pointer new_first = pointer();
					pointer new_last = pointer();
					pointer new_last_capacity = pointer();

					int next_capacity = (this->size() * 2 > 0) ? this->size() * 2 : 1; 
					new_first = _alloc.allocate( next_capacity );
					new_last = new_first + this->size() + 1;
					new_last_capacity = new_first + next_capacity;

					for (size_type i = 0; i < pos_len; i++)
						_alloc.construct(new_first + i, *(_first + i));
					_alloc.construct(new_first + pos_len, val);
					for (size_type j = 0; j < this->size() - pos_len; j++)
						_alloc.construct(new_last - j - 1, *(_last - j - 1));

					for (size_type l = 0; l < this->size(); l++)
						_alloc.destroy(_first + l);
					if (_first)
						_alloc.deallocate(_first, this->capacity());
					
					_first = new_first;
					_last = new_last;
					_last_capacity = new_last_capacity;
				}
				return (iterator(_first + pos_len));
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				if (n == 0)
					return ;
				if (n > this->max_size())
					throw (std::length_error("vector::insert (fill)"));
				size_type pos_len = &(*position) - _first;
				if (size_type(_last_capacity - _last) >= n)
				{
					for (size_type i = 0; i < this->size() - pos_len; i++)
						_alloc.construct(_last - i + (n - 1), *(_last - i - 1));
					_last += n;
					while (n)
					{
						_alloc.construct(&(*position) + (n - 1), val);
						n--;
					}
				}
				else
				{
					pointer new_first = pointer();
					pointer new_last = pointer();
					pointer new_last_capacity = pointer();
					
					int next_capacity = (this->capacity() > 0) ? (int)(this->size() * 2) : 1;
					new_first = _alloc.allocate(next_capacity);
					new_last_capacity = new_first + next_capacity;

					if (size_type(new_last_capacity - new_first) < this->size() + n)
					{
						if (new_first)
							_alloc.deallocate(new_first, new_first - new_last_capacity);
						next_capacity = this->size() + n;
						new_first = _alloc.allocate(next_capacity);
						new_last = new_first + this->size() + n;
						new_last_capacity = new_first + next_capacity;
					}

					new_last = new_first + this->size() + n;

					for (int i = 0; i < (&(*position) - _first); i++)
						_alloc.construct(new_first + i, *(_first + i));
					for (size_type k = 0; k < n; k++)
						_alloc.construct(new_first + pos_len + k, val);
					for (size_type j = 0; j < (this->size() - pos_len); j++)
						_alloc.construct(new_last - j - 1, *(_last - j - 1));

					for (size_type u = 0; u < this->size(); u++)
						_alloc.destroy(_first + u);
					_alloc.deallocate(_first, this->capacity());

					_first = new_first;
					_last = new_last;
					_last_capacity = new_last_capacity;
				}
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr)
			{
				bool is_valid;
				if (!(is_valid = ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::value))
					throw (ft::InvalidIteratorException<typename ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());
				
				size_type dist = ft::distance(first, last);
				if (size_type(_last_capacity - _last) >= dist)
				{
					for(size_type i = 0; i < this->size() - (&(*position) - _first); i++)
						_alloc.construct(_last - i + (dist - 1), *(_last - i - 1));
					_last += dist;
					for (; &(*first) != &(*last); first++, position++)
						_alloc.construct(&(*position), *first);
				}
				else
				{
					pointer new_first = pointer();
					pointer new_last = pointer();
					pointer new_last_capacity = pointer();

					new_first = _alloc.allocate( this->size() * 2 );
					new_last = new_first + this->size() + dist;
					new_last_capacity = new_first + ( this->size() * 2 );

					if (size_type(new_last_capacity - new_first) < this->size() + dist)
					{
						if (new_first)
							_alloc.deallocate(new_first, new_last_capacity - new_first);
						new_first = _alloc.allocate (this->size() + dist);
						new_last = new_first + this->size() + dist;
						new_last_capacity = new_last;
					}

					for (int i = 0; i < &(*position) - _first; i++)
						_alloc.construct(new_first + i, *(_first + i));
					for (int j = 0; &(*first) != &(*last); first++, j++)
						_alloc.construct(new_first + (&(*position) - _first) + j, *first);
					for (size_type k = 0; k < this->size() - (&(*position) - _first); k++)
						_alloc.construct(new_first + (&(*position) - _first) + dist + k, *(_first + (&(*position) - _first) + k));

					for (size_type l = 0; l < this->size(); l++)
						_alloc.destroy(_first + l);
					_alloc.deallocate(_first, this->capacity());

					_first = new_first;
					_last = new_last;
					_last_capacity = new_last_capacity;
				}
			}
			//============== END INSERT ==============
			// insert

			//==============#5 END MODIFIERS #5==============




			//=============#6 START ALLOCATOR #6=============

			allocator_type get_allocator() const
        	{
				return _alloc; 
			}
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
			pointer         _last_capacity;//??
			
			void checkRange(const size_type& n) const
			{
				if (n >= this->size())
					throw (std::out_of_range("vector::checkRange: n (which is "
							+ ft::to_string(n) + ") >= this->size() (which is "
							+ ft::to_string(this->size()) + ")"));
			}

	};

	template <class T, class Alloc>
	bool operator== (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T>::const_iterator leftIter = lhs.begin();
		typename ft::vector<T>::const_iterator rightIter = rhs.begin();

		while (leftIter != lhs.end())
		{
			if (*leftIter != *rightIter || rightIter == rhs.end())
				return (false);
			leftIter++;
			rightIter++;
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator!= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator< (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.endif(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator> (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap (ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y)
	{
		x.swap(y);
	}
}

#endif