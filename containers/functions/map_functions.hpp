#ifndef MAP_FUNCTIONS_HPP
#define MAP_FUNCTIONS_HPP

#include "functions.hpp"
#include "map_const_iterator.hpp"

namespace ft
{
    //==================Start Node==================
    template <typename T>
    struct Node
    {
        public:
            typedef T value_type;

            value_type value;
            Node* parent;
            Node* left;
            Node* right;

            Node (): value(), parent(u_nullptr), left(u_nullptr), right(u_nullptr)
            {
			}

            Node (Node* parent = u_nullptr, Node* left = u_nullptr, Node* right = u_nullptr):
                value(),
                parent(parent),
                left(left),
                right(right)
            {
			}

            Node (const value_type& val, Node* parent = u_nullptr, Node* left = u_nullptr, Node* right = u_nullptr):
                value(val),
                parent(parent),
                left(left),
                right(right)
            {
			}

            Node (const Node& other): value(other.value), parent(other.parent), left(other.left), right(other.right)
            {
			}

            virtual ~Node()
			{
			}

            Node &operator= (const Node& other)
            {
                if (other == *this)
                    return (*this);
                this->value = other.value;
                this->parent = other.parent;
                this->left = other.left;
                this->right = other.right;
                return (*this);
            }

            bool operator== (const Node& other)
            {
                if (value == other.value)
                    return (true);
                return (false);
            }
    };
    //===================End Node===================

	//===================End bidirectional_iterator_map===================
    template <class T, class Compare = ft::less<T>, class Node = ft::Node<T>,
              class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
    class bidirectional_iterator_map
    {
        public:
            typedef bidirectional_iterator_map          self;
            typedef self&                       self_reference;
            typedef T                                       value_type;
			typedef Node                                    node_type;
			typedef Node *                                  node_pointer;
			typedef Node_Alloc                              node_alloc;
			typedef ft::map_iterator<Node, Compare>         iterator;
			typedef ft::map_const_iterator<Node, Compare>   const_iterator;
			typedef size_t                                  size_type;

            bidirectional_iterator_map(const node_alloc& node_alloc_init = node_alloc()) : _node_alloc(node_alloc_init)
            {
                _last_node = _node_alloc.allocate(1);
                _node_alloc.construct(_last_node, Node(_last_node, _last_node, _last_node));
            }

            ~bidirectional_iterator_map()
            {
                _node_alloc.destroy(_last_node);
                _node_alloc.deallocate(_last_node, 1);
            }

			node_pointer    _last_node;
			node_alloc      _node_alloc;

            ft::pair<iterator, bool> insertPair(value_type to_insert)
			{
				Node*   afterNode = _node_alloc.allocate(1);
				Node*   prev_node = _last_node;
				Node*   start_node = _last_node->parent;
				bool    side = true;
				while (start_node != _last_node)
				{
					int curkey = start_node->value.first;
					if (curkey == to_insert.first)
						return (ft::make_pair(iterator(start_node, _last_node), false));
					prev_node = start_node;
					if (to_insert.first > curkey)
					{
						side = true;
						start_node = start_node->right;
					}
					else
					{
						side = false;
						start_node = start_node->left;
					}
				}
				_node_alloc.construct(afterNode, Node(to_insert, prev_node, _last_node, _last_node));
				
				if (prev_node == _last_node)
					_last_node->parent = afterNode;
				else if (side == true)
					prev_node->right = afterNode;
				else
					prev_node->left = afterNode;
				
				_last_node->left = _map_while_loop_left(_last_node->parent);
				_last_node->right = _map_while_loop_right(_last_node->parent);
				_last_node->value.first += 1;
				return (ft::make_pair(iterator(afterNode, _last_node), true));
			}

            void removeByKey(value_type remove_key)
			{
                _remove(_last_node->parent, remove_key);
            }

            node_pointer searchByKey(value_type remove_key) const
			{
				node_pointer node = _last_node->parent;

				while (node != _last_node)
				{
					if (node->value.first == remove_key.first)
						return (node);
					if (node->value.first > remove_key.first)
						node = node->left;
					else
						node = node->right;
				}
				return (node);
			}

			void swap(self& x)
			{
				if (&x == this)
					return ;
				
				node_pointer save = this->_last_node;
				this->_last_node = x._last_node;
				x._last_node = save;
			}

			size_type max_size() const
			{
                return (node_alloc().max_size());
            }
			
        private:
            node_pointer _map_while_loop_left(node_pointer arg)
			{
				while (arg->left != _last_node && arg != _last_node)
					arg = arg->left;
				return (arg);
			}
			node_pointer _map_while_loop_right(node_pointer arg)
			{
				while (arg->right != _last_node && arg != _last_node)
					arg = arg->right;
				return (arg);
			}
			void _replaceNodeInParent(node_pointer beforeNode, node_pointer afterNode)
			{
				if (beforeNode->parent != _last_node)
				{
					if (_last_node->parent == beforeNode)
						_last_node->parent = afterNode;

					if (beforeNode == beforeNode->parent->left)
						beforeNode->parent->left = afterNode;
					else
						beforeNode->parent->right = afterNode;
				}
				else
					_last_node->parent = afterNode;

				_last_node->left = _map_while_loop_left(_last_node->parent);
				_last_node->right = _map_while_loop_right(_last_node->parent);
				_last_node->value.first -= 1;
				
				afterNode->parent = beforeNode->parent;
				
				_node_alloc.destroy(beforeNode);
				_node_alloc.deallocate(beforeNode, 1);
			}

			void _doubleReplace(node_pointer& remove_key, node_pointer afterNode)
			{
				if (afterNode->parent != _last_node && afterNode->parent != remove_key)
						afterNode->parent->left = afterNode->right;
				
				afterNode->parent = remove_key->parent;

				if (remove_key->left != afterNode)
					afterNode->left = remove_key->left;
				if (remove_key->right != afterNode)
					afterNode->right = remove_key->right;

				if (remove_key->parent != _last_node)
				{
					if (remove_key->parent->left == remove_key)
						remove_key->parent->left = afterNode;
					else if (remove_key->parent->right == remove_key)
						remove_key->parent->right = afterNode;
				}
				else
					_last_node->parent = afterNode;
					
				if (remove_key->left != _last_node && remove_key->left != afterNode)
					remove_key->left->parent = afterNode;
				if (remove_key->right != _last_node && remove_key->right != afterNode)
					remove_key->right->parent = afterNode;

				if (remove_key->parent != _last_node)
				{
					remove_key->left = _last_node;
					remove_key->right = _last_node;
					remove_key->parent = afterNode;
				}

				_last_node->left = _map_while_loop_left(_last_node->parent);
				_last_node->right = _map_while_loop_right(_last_node->parent);
				_last_node->value.first -= 1;

				_node_alloc.destroy(remove_key);
				_node_alloc.deallocate(remove_key, 1);
			}

			void _remove(node_pointer prev_node, value_type remove_key)
			{
				if (remove_key.first < prev_node->value.first)
				{
					_remove(prev_node->left, remove_key);
					return ;
				}

				if (remove_key.first > prev_node->value.first)
				{
					_remove(prev_node->right, remove_key);
					return ;
				}

				if (prev_node->left != _last_node && prev_node->right != _last_node)
				{
					node_pointer successor = _map_while_loop_left(prev_node->right);
					_doubleReplace(prev_node, successor);
					return ;
				}
				else if (prev_node->left != _last_node)
					_replaceNodeInParent(prev_node, prev_node->left);
				else if (prev_node->right != _last_node)
					_replaceNodeInParent(prev_node, prev_node->right);
				else
					_replaceNodeInParent(prev_node, _last_node);
			}
    };
	//===================End bidirectional_iterator_map===================
}


#endif