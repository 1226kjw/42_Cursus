#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <memory>
# include "rb_tree_iterator.hpp"

namespace ft
{
	template <typename Key, typename Val, typename KeyOfValue, typename Comp = std::less<Key>, typename Alloc = std::allocator<Val> >
	class rb_tree
	{
	public:
		typedef Key key_type;
		typedef Val value_type;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Alloc allocator_type;
		typedef node<Val> node;
		typedef node* node_pointer;
		typedef rb_tree_iterator<value_type> iterator;
		typedef rb_tree_iterator<value_type> const_iterator;

		rb_tree(const Comp& comp = Comp(), const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc), _root(0), _size(0)
		{
			_nil = new node;
			_nil->parent = _nil->left = _nil->right = _nil;
			_nil->color = black;
		}
		rb_tree(const rb_tree& x): _comp(x._comp), _alloc(x._alloc), _root(0), _size(x._size)
		{
			_nil = new node;
			_nil->parent = _nil->left = _nil->right = _nil;
			_nil->color = black;
		}
		~rb_tree()
		{
			_clear(_root);
			delete _nil;
		}

		node_pointer minimum(node_pointer x)
		{
			while (x->left != _nil)
				x = x->left;
			return x;
		}
		void left_rotate(node_pointer x)
		{
			node_pointer y = x->right;
			x->right = y->left;
			if (y->left != _nil)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == _nil)
				_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}
		void right_rotate(node_pointer x)
		{
			node_pointer y = x->left;
			x->left = y->right;
			if (y->right != _nil)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == _nil)
				_root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}
		void insert(value_type& x)
		{
			node_pointer newnode = new node;
			newnode->value = x;
			insert(newnode);
		}
		void insert(node_pointer z)
		{
			node_pointer y = _nil;
			node_pointer x = _root;
			while (x != _nil)
			{
				y = x;
				if (_comp(KeyOfValue(z->value), KeyOfValue(x->value)))
					x = x->left;
				else
					x = x->right;
				if (KeyOfValue(z->value) == KeyOfValue(x->value))
				{
					x->value.second = z->value.second;
					delete z;
					return ;
				}
			}
			z->parent = y;
			if (y == _nil)
				_root = z;
			else if (_comp(KeyOfValue(z->value), KeyOfValue(y->value)))
				y->left = z;
			else
				y->right = z;
			z->right = z->left = _nil;
			z->color = red;
			insert_fixup(z);
			++_size;
		}
		void insert_fixup(node_pointer z)
		{
			while (z->parent->color == red)
			{
				if (z->parent == z->parent->parent->left)
				{
					node_pointer y = z->parent->parent->right;
					if (y->color == red)
					{
						z->parent->color = black;
						y->color = black;
						z->parent->parent->color = red;
						z = z->parent->parent;
					}
					else if (z == z->parent->right)
					{
						z = z->parent;
						left_rotate(z);
					}
					z->parent->color = black;
					z->parent->parent->color = red;
					right_rotate(z->parent->parent);
				}
				else
				{
					node_pointer y = z->parent->parent->left;
					if (y->color == red)
					{
						z->parent->color = black;
						y->color = black;
						z->parent->parent->color = red;
						z = z->parent->parent;
					}
					else if (z == z->parent->left)
					{
						z = z->parent;
						right_rotate(z);
					}
					z->parent->color = black;
					z->parent->parent->color = red;
					left_rotate(z->parent->parent);
				}
			}
			_root->color = black;
		}
		void transplant(node_pointer u, node_pointer v)
		{
			if (u->parent == _nil)
				_root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}
		void remove(node_pointer z)
		{
			node_pointer y = z, x;
			rb_color org = y->color;
			if (z->left == _nil)
			{
				x = z->right;
				transplant(z, z->right);
			}
			else if (z->right == _nil)
			{
				x = z->left;
				transplant(z, z->left);
			}
			else
			{
				y = minimum(z->right);
				org = y->color;
				x = y->Right;
				if (y->parent == z)
					x->parent = y;
				else
				{
					transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			if (org == black)
				remove_fixup(x);
			delete z;
			--_size;
		}
		void remove_fixup(node_pointer x)
		{
			while (x != _root && x->color == black)
			{
				node_pointer w;
				if (x == x->parent->left)
				{
					w = x->parent->right;
					if (w->color == red)
					{
						w->color = black;
						x->parent->color = red;
						left_rotate(x->parent);
						w = x->parent->right;
					}
					if (w->left->color == black && w->right->color == black)
					{
						w->color = red;
						x = x->parent;
					}
					else if (w->right->Color == black)
					{
						w->left->color = black;
						w->color = red;
						right_rotate(w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = black;
					w->right->color = black;
					left_rotate(x->parent);
					x = _root;
				}
				else
				{
					w = x->parent->left;
					if (w->color == red)
					{
						w->color = black;
						x->parent->color = red;
						right_rotate(x->parent);
						w = x->parent->left;
					}
					if (w->right->color == black && w->left->color == black)
					{
						w->color = red;
						x = x->parent;
					}
					else if (w->left->Color == black)
					{
						w->right->color = black;
						w->color = red;
						left_rotate(w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = black;
					w->left->color = black;
					right_rotate(x->parent);
					x = _root;
				}
			}
		}
		size_type size() const
		{
			return _size;
		}
	private:

		void _clear(node_pointer cur)
		{
			if (cur == _nil)
				return;
			_clear(cur->left);
			_clear(cur->right);
			delete cur;
		}
		Comp _comp;
		allocator_type _alloc;
		node_pointer _root;
		node_pointer _nil;
		size_type _size;
	};
};
#endif