#ifndef MAP_FUNCTIONS_HPP
#define MAP_FUNCTIONS_HPP

#include "functions.hpp"
#include "map_iterator.hpp"

namespace ft
{
    //==================Start BST_Node==================
    template <typename T>
    struct BST_Node
    {
        public:
            typedef T value_type;

            value_type value;
            BST_Node* parent;
            BST_Node* left;
            BST_Node* right;

            BST_Node (): value(), parent(u_nullptr), left(u_nullptr), right(u_nullptr)
            {
			}

            BST_Node (BST_Node* parent = u_nullptr, BST_Node* left = u_nullptr, BST_Node* right = u_nullptr):
                value(),
                parent(parent),
                left(left),
                right(right)
            {
			}

            BST_Node (const value_type& val, BST_Node* parent = u_nullptr, BST_Node* left = u_nullptr, BST_Node* right = u_nullptr):
                value(val),
                parent(parent),
                left(left),
                right(right)
            {
			}

            BST_Node (const BST_Node& other): value(other.value), parent(other.parent), left(other.left), right(other.right)
            {
			}

            virtual ~BST_Node()
			{
			}

            BST_Node &operator= (const BST_Node& other)
            {
                if (other == *this)
                    return (*this);
                this->value = other.value;
                this->parent = other.parent;
                this->left = other.left;
                this->right = other.right;
                return (*this);
            }

            bool operator== (const BST_Node& other)
            {
                if (value == other.value)
                    return (true);
                return (false);
            }
    };
    //===================End BST_Node===================

    //===================Start Doubly_Linked_Node===================
    template <class Data_T>
    struct Doubly_Linked_Node 
    {
        public :
            Data_T              data;
            Doubly_Linked_Node  *prev;
            Doubly_Linked_Node  *next;
            Doubly_Linked_Node(): prev(u_nullptr), next(u_nullptr)
            {
			}

            Doubly_Linked_Node(const Data_T& val): prev(u_nullptr), next(u_nullptr), data(val)
            {
			}

            Doubly_Linked_Node(const Data_T& val, Doubly_Linked_Node *prev, Doubly_Linked_Node *next):
                prev(prev),
                next(next),
                data(val)
            {
			}
    };
    //===================End Doubly_Linked_Node===================

    template <class T, class Compare = ft::less<T>, class Node = ft::BST_Node<T>,
              class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
    class Binary_search_tree
    {
        public:
            typedef Binary_search_tree          self;
            typedef self&                       self_reference;
            typedef T                                       value_type;
			typedef Node                                    node_type;
			typedef Node *                                  node_pointer;
			typedef Node_Alloc                              node_alloc;
			typedef ft::BST_iterator<Node, Compare>         iterator;
			typedef ft::BST_const_iterator<Node, Compare>   const_iterator;
			typedef size_t                                  size_type;

            node_pointer    _last_node;
			node_alloc      _node_alloc;

            Binary_search_tree(const node_alloc& node_alloc_init = node_alloc()): _node_alloc(node_alloc_init)
            {
                _last_node = _node_alloc.allocate(1);
                _node_alloc.consruct(_last_node, Node(_last_node, _last_node, _last_node));
            }

            ~Binary_search_tree()
            {
                _node_alloc.destroy(_last_node);
                _node_alloc.deallocate(_last_node, 1);
            }

            ft::pair<iterator, bool> insertPair(value_type to_insert)
			{
				Node*   new_node = _node_alloc.allocate(1);
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
				_node_alloc.construct(new_node, Node(to_insert, prev_node, _last_node, _last_node));
				
				if (prev_node == _last_node)
					_last_node->parent = new_node;
				else if (side == true)
					prev_node->right = new_node;
				else
					prev_node->left = new_node;
				
				_last_node->left = _BST_get_lower_node(_last_node->parent);
				_last_node->right = _BST_get_higher_node(_last_node->parent);
				_last_node->value.first += 1;
				return (ft::make_pair(iterator(new_node, _last_node), true));
			}

            void removeByKey(value_type to_remove)
			{
                _removeByKey(_last_node->parent, to_remove);
            }

            node_pointer searchByKey(value_type to_remove)
			{
				node_pointer node = _last_node->parent;

				while (node != _last_node)
				{
					if (node->value.first == to_remove.first)
						return (node);
					if (node->value.first > to_remove.first)
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
            node_pointer _BST_get_lower_node(node_pointer root)
			{
				while (root != _last_node && root->left != _last_node)
					root = root->left;
				return (root);
			}
			node_pointer _BST_get_higher_node(node_pointer root)
			{
				while (root != _last_node && root->right != _last_node)
					root = root->right;
				return (root);
			}
			void _replaceNodeInParent(node_pointer node, node_pointer new_node)
			{
				if (node->parent != _last_node)
				{
					if (_last_node->parent == node)
						_last_node->parent = new_node;

					if (node == node->parent->left)
						node->parent->left = new_node;
					else
						node->parent->right = new_node;
				}
				else
					_last_node->parent = new_node;

				_last_node->left = _BST_get_lower_node(_last_node->parent);
				_last_node->right = _BST_get_higher_node(_last_node->parent);
				_last_node->value.first -= 1;
				
				new_node->parent = node->parent;
				
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}

			void _replaceDoubleChildren(node_pointer& to_remove, node_pointer new_node)
			{
				if (new_node->parent != _last_node)
				{
					if (new_node->parent != to_remove)
						new_node->parent->left = new_node->right;
				}
				
				new_node->parent = to_remove->parent;
				if (to_remove->left != new_node)
					new_node->left = to_remove->left;
				if (to_remove->right != new_node)
					new_node->right = to_remove->right;

				if (to_remove->parent != _last_node)
				{
					if (to_remove->parent->left == to_remove)
						to_remove->parent->left = new_node;
					else if (to_remove->parent->right == to_remove)
						to_remove->parent->right = new_node;
				}
				else
					_last_node->parent = new_node;
					
				if (to_remove->left != _last_node && to_remove->left != new_node)
					to_remove->left->parent = new_node;
				if (to_remove->right != _last_node && to_remove->right != new_node)
					to_remove->right->parent = new_node;

				if (to_remove->parent != _last_node)
				{
					to_remove->left = _last_node;
					to_remove->right = _last_node;
					to_remove->parent = new_node;
				}

				_last_node->left = _BST_get_lower_node(_last_node->parent);
				_last_node->right = _BST_get_higher_node(_last_node->parent);
				_last_node->value.first -= 1;

				_node_alloc.destroy(to_remove);
				_node_alloc.deallocate(to_remove, 1);
			}

			void _removeByKey(node_pointer node, value_type to_remove)
			{
				if (to_remove.first < node->value.first)
				{
					_removeByKey(node->left, to_remove);
					return ;
				}

				if (to_remove.first > node->value.first)
				{
					_removeByKey(node->right, to_remove);
					return ;
				}

				if (node->left != _last_node && node->right != _last_node)
				{
					node_pointer successor = _BST_get_lower_node(node->right);
					_replaceDoubleChildren(node, successor);
					return ;
				}
				else if (node->left != _last_node)
					_replaceNodeInParent(node, node->left);
				else if (node->right != _last_node)
					_replaceNodeInParent(node, node->right);
				else
					_replaceNodeInParent(node, _last_node);
			}
    };
}


#endif