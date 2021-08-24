#ifndef MAP_HPP
#define MAP_HPP

#include "functions/functions.hpp"
#include "functions/map_functions.hpp"

namespace ft
{
    template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef ft::pair<key_type, mapped_type>		value_type;
			typedef Compare								key_compare;
			
			class value_compare : ft::binary_function<value_type, value_type, bool>
			{
				friend class map<key_type, mapped_type, key_compare, Alloc>;
			    protected:
					Compare         comp;
					value_compare   (Compare c) : comp(c) 
					{
					}
				public:
					bool operator() (const value_type& x, const value_type& y) const
					{
						return (comp(x.first, y.first));
					}
			};

			typedef Alloc                                                                       allocator_type;

			typedef typename allocator_type::reference                                          reference;
			typedef typename allocator_type::const_reference                                    const_reference;
			typedef typename allocator_type::pointer                                            pointer;
			typedef typename allocator_type::const_pointer                                      const_pointer;

			typedef typename ft::bidirectional_iterator_map<value_type, key_compare>::iterator          iterator;
			typedef typename ft::bidirectional_iterator_map<value_type, key_compare>::const_iterator    const_iterator;
			typedef typename ft::reverse_iterator<iterator>                                     reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>                               const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type                     difference_type;
			
			typedef size_t                                                                      size_type;

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp), _map()
			{
			}

			template <class InputIterator> map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr): _alloc(alloc), _comp(comp), _map()
			{
				this->insert(first, last);
			}

			map(const map& other): _alloc(other._alloc), _comp(other._comp), _map()
			{
				this->insert(other.begin(), other.end());
			}

			map& operator= (const map& other)
			{
				if (&other == this)
					return (*this);
				this->clear();
				this->insert(other.begin(), other.end());
				return (*this);
			}

			~map()
			{
				this->clear();
			}

			//====================#1 START ITERATORS #1====================
			//==================== START BEGIN ====================
			iterator	begin()
			{
				return (iterator(_map._last_node->left, _map._last_node));
			}

			reverse_iterator	rbegin()
			{
				return (reverse_iterator(this->end()));
			}

			const_iterator	begin() const
			{
				return (const_iterator(_map._last_node->left, _map._last_node));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->end()));
			}
			//==================== END BEGIN ====================

			//==================== START END ====================
			iterator	end()
			{
				return (iterator(_map._last_node, _map._last_node));
			}

			const_iterator	end() const
			{
				return (const_iterator(_map._last_node, _map._last_node));
			}

			reverse_iterator	rend()
			{
				return (reverse_iterator(this->begin()));
			}

			const_reverse_iterator	rend() const
			{
				return (const_reverse_iterator(this->begin()));
			}

			//==================== END END ====================
			//====================#1 END ITERATORS #1====================


			//====================#2 START CAPACITY #2====================
			bool	empty() const
			{
				return (_map._last_node->parent == _map._last_node);
			}

			size_type	size() const
			{
				return (_map._last_node->value.first);
			}

			size_type	max_size() const
			{
				return (_map.max_size());
			}

			//====================#2 END CAPACITY #2====================

			//====================#3 START ELEMENT ACCESS #3====================
			mapped_type&	operator[] (const key_type& k)
			{
				iterator result = this->find(k);

				if (result == this->end())
					this->insert(ft::make_pair(k, mapped_type()));
				result = this->find(k);
				return ((*result).second);
			}
			//====================#3 END ELEMENT ACCESS #3====================

			//====================#4 START MODIFIERS #4====================
			pair<iterator, bool>	insert (const value_type& val)
			{
				return (_map.insertPair(val));
			}

			iterator	insert (iterator position, const value_type& val)
			{
				(void)position;
				return (_map.insertPair(val).first);
			}

			template <class InputIterator> void insert (InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr)
			{
				difference_type n = ft::distance(first, last);
				while (n--)
					this->insert(*(first++));
			}

			void	erase (iterator position)
			{
				this->erase(position++, position);
			}

			size_type	erase (const key_type& k)
			{
				if (this->find(k) == this->end())
					return (0);
				_map.removeByKey(ft::make_pair(k, mapped_type()));
				return (1);
			}

			void	erase (iterator first, iterator last)
			{
				while (first != last)
					this->erase((*(first++)).first);
			}

			void	swap (map& x)
			{
				_map.swap(x._map);
			}

			void	clear()
			{
				this->erase(this->begin(), this->end());
			}
			//====================#4 END MODIFIERS #4====================

			//====================#5 START OBSERVERS #5====================
			key_compare     key_comp() const
			{
				return (key_compare());
			}

			value_compare	value_comp() const
			{
				return (value_compare(key_compare()));
			}
			//====================#5 END OBSERVERS #5====================

			//====================#6 START OPERATIONS #6====================
			iterator	find (const key_type& k)
			{
				return (iterator(_map.searchByKey(ft::make_pair(k, mapped_type())), _map._last_node));
			}

			const_iterator	find (const key_type& k) const
			{
				return (const_iterator(_map.searchByKey(ft::make_pair(k, mapped_type())), _map._last_node));
			}

			size_type	count (const key_type& k) const
			{
				const_iterator ci_begin = this->begin();
				const_iterator ci_end = this->end();
				while (ci_begin != ci_end)
					if ((*(ci_begin++)).first == k)
						return (1);
				return (0);
			}

			iterator	lower_bound (const key_type& k)
			{
				iterator i_begin = this->begin();
				iterator i_end = this->end();
				while (i_begin != i_end)
				{
					if (_comp((*i_begin).first, k) == false)
						break;
					i_begin++;
				}
				return (i_begin);
			}

			const_iterator  lower_bound (const key_type& k) const
			{
				return (const_iterator(this->lower_bound(k)));
			}

			iterator	upper_bound (const key_type& k)
			{
				iterator i_begin = this->begin();
				iterator i_end = this->end();
				while (i_begin != i_end)
				{
					if (_comp(k, (*i_begin).first) == true)
						break;
					i_begin++;
				}
				return (i_begin);
			}

			const_iterator upper_bound (const key_type& k) const
			{
				return (const_iterator(this->upper_bound(k)));
			}

			ft::pair<iterator, iterator> equal_range (const key_type& k)
			{
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			}

			ft::pair<const_iterator, const_iterator> equal_range (const key_type& k) const
			{
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			}
			//====================#6 END OPERATIONS #6====================

			//====================#7 START ALLOCATOR #7====================
			allocator_type get_allocator() const
        	{
				return _alloc; 
			}
			//====================#7 START ALLOCATOR #7====================

		private:
			allocator_type                          _alloc;
			Compare                                 _comp;
			bidirectional_iterator_map<value_type, Compare>  _map;
    };
}

#endif