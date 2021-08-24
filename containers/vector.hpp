#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

#include "functions/functions.hpp"
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
			typedef typename allocator_type::pointer                        pointer;
			typedef typename allocator_type::const_pointer                  const_pointer;
			typedef typename allocator_type::size_type                      size_type;

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
			{
			}

			explicit vector(size_t n, const value_type &var = value_type(),
					const allocator_type &allocate = allocator_type()):
				_alloc(allocate)
			{
				this->_first = _alloc.allocate(n);
				this->_last = this->_first;
				_last_capacity = this->_first + n;
				while (n--)
					_alloc.construct(this->_last++, var);
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr): _alloc(alloc)
			{
				difference_type n = ft::distance(first, last);
				this->_first = this->_alloc.allocate(n);
				this->_last = this->_first;
				this->_last_capacity = this->_first + n;
				while (n--)
					_alloc.construct(_last++, *first++);
			}

			vector (const vector& x): _alloc(x._alloc), _first(u_nullptr), _last(u_nullptr), _last_capacity(u_nullptr)
			{
				this->insert(this->begin(), x.begin(), x.end());
			}

			~vector()
			{
				this->clear();
				_alloc.deallocate(this->_first, this->capacity());
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
			
			size_type size(void) const
			{
				return (this->_last - this->_first);
			}

			size_type max_size() const
			{
				return (allocator_type().max_size());
			}

			void resize (size_type n, value_type val = value_type())
			{
				if (n < this->size())
				{
					while (this->size() > n)
					{
						--_last;
						_alloc.destroy(_last);
					}
				}
				else if (n > this->max_size())
					throw (std::length_error("Error: vector::resize"));
				else
					this->insert(this->end(), n - this->size(), val);
			}

			size_type capacity() const
			{
				return (this->_last_capacity - this->_first);
			}

			bool empty () const
			{
				return (!size());
			}

			void reserve (size_type n)
			{
				if (n > this->max_size())
					throw (std::length_error("Error: vector::reserve"));
				else if (n > this->capacity())
				{
					pointer     tmp_first = _first;
					pointer     tmp_last = _last;
					size_type   tmp_size = this->size();
					size_type   tmp_capacity = this->capacity();

					_first = _alloc.allocate(n);
					_last_capacity = _first + n;
					_last = _first;

					while (tmp_first != tmp_last)
					{
						_alloc.construct(_last, *tmp_first);
						_last++;
						tmp_first++;
					}
					_alloc.deallocate(tmp_first - tmp_size, tmp_capacity);
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
				segmentationFault(n);
				return ((*this)[n]);
			}

			const_reference at(size_type n) const
			{
				segmentationFault(n);
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
						_alloc.construct(new_last, *first);
					
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
				else if (n >= size_type(_last_capacity - _first))
				{
					_alloc.deallocate(_first, this->capacity());
					_first = _alloc.allocate(n);
					_last = _first;
					_last_capacity = _first + n;
				}
				while (n)
				{
					_alloc.construct(_last++, val);
					n--;
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
				_alloc.construct(_last, val);
				_last++;
			}

			void pop_back()
			{
				_alloc.destroy(&this->back());
				_last--;
			}
			
			iterator erase (iterator position)
			{
				pointer p_pos = &(*position);

				_alloc.destroy(&(*position));

				if (&(*position) + 1 == _last)
					_alloc.destroy(&(*position));
				else
				{
					for (int i = 0; i < _last - &(*position) - 1; i++)
					{
						_alloc.construct(&(*position) + i, *(&(*position) + i + 1));
						_alloc.destroy(&(*position) + i + 1);
					}
				}
				_last -= 1;
				return (iterator(p_pos));
			}

			iterator erase (iterator first, iterator last)
			{
				pointer p_first = &(*first);

				for (; &(*first) != &(*last); first++)
					_alloc.destroy(&(*first));

				for (int i = 0; i < _last - &(*last); i++)
				{
					_alloc.construct(p_first + i, *(&(*last) + i));
					_alloc.destroy(&(*last) + i);
				}

				_last -= (&(*last) - p_first);
				return (iterator(p_first));
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
				allocator_type  tmp_alloc = x._alloc;
				pointer         tmp_first = x._first;
				pointer         tmp_last = x._last;
				pointer         tmp_last_capacity = x._last_capacity;

				x._alloc = this->_alloc;
				x._first = this->_first;
				x._last = this->_last;
				x._last_capacity = this->_last_capacity;

				this->_alloc = tmp_alloc;
				this->_first = tmp_first;
				this->_last = tmp_last;
				this->_last_capacity = tmp_last_capacity;
			}

			//============= START INSERT =============
			iterator insert(iterator position, const value_type& val)
			{
				this->insert(position, 1, val);
				return (++position);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				if (n == 0)
					return ;
				if (n > this->max_size())
					throw (std::length_error("Error: vector::insert (fill)"));
				size_type pos_len = &(*position) - this->_first;
				if (size_type(_last_capacity - this->_last) >= n)
				{
					for (size_type i = 0; i < this->size() - pos_len; i++)
						this->_alloc.construct(this->_last - i + (n - 1), *(this->_last - i - 1));
					this->_last += n;
					n++;
					while (--n)
						this->_alloc.construct(&(*position) + (n - 1), val);
				}
				else
				{
					int next_capacity = (this->capacity() > 0) ? (int)(this->size() * 2) : 1;
					
					pointer new_last = pointer();
					pointer new_first = _alloc.allocate(next_capacity);
					pointer new_last_capacity = new_first + next_capacity;

					if (size_type(new_last_capacity - new_first) < this->size() + n)
					{
						if (new_first)
							this->_alloc.deallocate(new_first, new_first - new_last_capacity);
						next_capacity = this->size() + n;
						new_first = this->_alloc.allocate(next_capacity);
						new_last = new_first + this->size() + n;
						new_last_capacity = new_first + next_capacity;
					}

					new_last = new_first + this->size() + n;

					for (int i = 0; i < (&(*position) - this->_first); i++)
						this->_alloc.construct(new_first + i, *(this->_first + i));
					for (size_type k = 0; k < n; k++)
						this->_alloc.construct(new_first + pos_len + k, val);
					for (size_type j = 0; j < (this->size() - pos_len); j++)
						this->_alloc.construct(new_last - j - 1, *(this->_last - j - 1));

					for (size_type u = 0; u < this->size(); u++)
						this->_alloc.destroy(this->_first + u);
					this->_alloc.deallocate(this->_first, this->capacity());

					this->_first = new_first;
					this->_last = new_last;
					this->_last_capacity = new_last_capacity;
				}
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr)
			{
				size_type dist = ft::distance(first, last);
				if (size_type(this->_last_capacity - this->_last) >= dist)
				{
					for(size_type i = 0; i < this->size() - (&(*position) - this->_first); i++)
						this->_alloc.construct(this->_last - i + (dist - 1), *(this->_last - i - 1));
					this->_last += dist;
					for (; &(*first) != &(*last); first++, position++)
						this->_alloc.construct(&(*position), *first);
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

					for (int i = 0; i < &(*position) - this->_first; i++)
						this->_alloc.construct(new_first + i, *(this->_first + i));
					for (int j = 0; &(*first) != &(*last); first++, j++)
						this->_alloc.construct(new_first + (&(*position) - this->_first) + j, *first);
					for (size_type k = 0; k < this->size() - (&(*position) - this->_first); k++)
						this->_alloc.construct(new_first + (&(*position) - this->_first) + dist + k, *(this->_first + (&(*position) - this->_first) + k));

					for (size_type l = 0; l < this->size(); l++)
						this->_alloc.destroy(this->_first + l);
					this->_alloc.deallocate(this->_first, this->capacity());

					this->_first = new_first;
					this->_last = new_last;
					this->_last_capacity = new_last_capacity;
				}
			}
			//============== END INSERT ==============
			//==============#5 END MODIFIERS #5==============

			//=============#6 START ALLOCATOR #6=============

			allocator_type get_allocator() const
        	{
				return _alloc; 
			}

			//==============#6 END ALLOCATOR #6==============

		private:
			allocator_type  _alloc;
			pointer         _first;
			pointer         _last;
			pointer         _last_capacity;
			
			void segmentationFault(const size_type& n) const
			{
				if (n >= this->size())
					throw (std::out_of_range("Error: vector::segmentationFault: segmentation fault"));
			}
	};

	template <class T, class Alloc>
	bool operator== (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T>::const_iterator lIter = lhs.begin();
		typename ft::vector<T>::const_iterator rIter = rhs.begin();

		while (lIter != lhs.end())
		{
			if (*lIter != *rIter || rIter == rhs.end())
				return (false);
			lIter++;
			rIter++;
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
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
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