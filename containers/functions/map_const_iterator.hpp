#ifndef MAP_CONST_ITERATOR_HPP
# define MAP_CONST_ITERATOR_HPP

#include "map_iterator.hpp"

namespace ft
{
	template <typename T, class Compare >
	class map_const_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public :

			typedef typename T::value_type                                                                  value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category    iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type      difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer              pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference            reference;

			map_const_iterator(const Compare& comp = Compare()): _node(), _last_node(), _comp(comp)
			{
			}

			map_const_iterator(T * node_p, T * last_node, const Compare& comp = Compare()): _node(node_p), _last_node(last_node), _comp(comp)
			{
			}

			map_const_iterator(const map_const_iterator& bst_it): _node(bst_it._node), _last_node(bst_it._last_node), _comp()
			{
			}

			map_const_iterator(const map_iterator<T, Compare>& bst_it): _node(bst_it._node), _last_node(bst_it._last_node), _comp()
			{
			}

			virtual ~map_const_iterator()
			{
			}

			map_const_iterator &operator= (const map_const_iterator& bst_it)
			{
				if (*this == bst_it)
					return (*this);
				this->_node = bst_it._node;
				this->_last_node = bst_it._last_node;
				this->_comp = bst_it._comp;
				return (*this);
			}

			bool operator== (const map_const_iterator& bst_it)
			{
				return (this->_node == bst_it._node);
			}

			bool operator!= (const map_const_iterator& bst_it)
			{
				return (this->_node != bst_it._node);
			}

			reference operator* () const
			{
				return (this->_node->value);
			}

			pointer operator-> () const
			{
				return (&this->_node->value);
			}

			map_const_iterator& operator++ (void)
			{
				T * tmp = _node;

				if (tmp == _last_node)
					_node = _last_node->right;
				else if (_node->right == _last_node)
				{
					tmp = _node->parent;
					while (tmp != _last_node && _comp(tmp->value.first, _node->value.first))
						tmp = tmp->parent;
					_node = tmp;
				}
				else
				{
					tmp = _node->right;
					if (tmp == _last_node->parent && tmp->left == _last_node)
						_node = tmp;
					else
					{
						while (tmp->left != _last_node)
							tmp = tmp->left;
					}					
					_node = tmp;
				}
				return (*this);
			}

			map_const_iterator operator++ (int)
			{
				map_const_iterator result(*this);
				operator++();
				return (result);
			}

			map_const_iterator& operator-- (void)
			{
				T * tmp = _node;
				if (tmp == _last_node)
					_node = _last_node->right;
				else if (_node->left == _last_node)
				{
					tmp = _node->parent;
					while (tmp != _last_node && !_comp(tmp->value.first, _node->value.first))
						tmp = tmp->parent;
					_node = tmp;
				}
				else
				{
					tmp = _node->left;
					if (tmp == _last_node->parent && tmp->left == _last_node)
						_node = tmp;
					else
					{
						while (tmp->right != _last_node)
							tmp = tmp->right;
					}
					_node = tmp;
				}
				return (*this);
			}

			map_const_iterator operator-- (int)
			{
				map_const_iterator result(*this);
				operator--();
				return (result);
			}

			T *         _node;
			T *         _last_node;
			Compare     _comp;
	};
}

#endif