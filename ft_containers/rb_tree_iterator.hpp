#ifndef RB_TREE_ITERATOR_HPP
# define RB_TREE_ITERATOR_HPP

# include "stack.hpp"
# include "iterator.hpp"

namespace ft
{
	enum rb_color { red = false, black = true };

	template <typename Val>
	struct node
	{
		Val* value;
		struct node* parent;
		struct node* left;
		struct node* right;
		rb_color color;
		node(): value(0), parent(0), left(0), right(0) {}
		node(const Val* x): value(x), parent(0), left(0), right(0) {}
		node& operator=(const node& x)
		{
			if (value)
				delete value;
			value = new Val(*x.value);
			return *this;
		}
	};

	template <typename T>
	class rb_tree_iterator
	{
	public:
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef struct node<value_type> node;
		typedef node* node_pointer;
		typedef rb_tree_iterator<value_type> iterator;

		rb_tree_iterator(const node_pointer nil, const node_pointer x): _cur(x), _nil(nil) {}
		rb_tree_iterator(const iterator& x): _cur(x._cur), _nil(x._nil) {}
		//rb_tree_iterator(const Iter& x) : _cur(x) {}
		// template<typename CIter>
		// rb_tree_iterator(const rb_tree_iterator<Iter, typename enable_if<
		// 	(is_same<Iter, typename Cont::pointer>::value), Cont>::type>& x)
		// : _cur(x) {}
		~rb_tree_iterator() {}
		// const Iter& base() const { return _cur; }
		// reference			operator*() const { return *_cur; }
		// pointer				operator->() const { return _cur; }
		pointer operator->()
		{
			return _cur->value;
		}
		node_pointer rb_tree_iterator_increment(node_pointer x)
		{
			if (x->right != _nil)
			{
				x = x->right;
				while (x->left != _nil)
					x = x->left;
			}
			else
			{
				node_pointer y = x->parent;
				while (x == y->right)
				{
					x = y;
					y = y->parent;
				}
				x = y;
			}
			return x;
		}
		node_pointer rb_tree_iterator_decrement(node_pointer x)
		{
			if (x->left != _nil)
			{
				x = x->left;
				while (x->right != _nil)
					x = x->right;
			}
			else
			{
				node_pointer y = x->parent;
				while (x == y->left)
				{
					x = y;
					y = y->parent;
				}
				x = y;
			}
			return x;
		}
		reference operator*()
		{
			return *_cur->value;
		}
		iterator& operator++()
		{
			_cur = rb_tree_iterator_increment(_cur);
			return *this;
		}
		iterator operator++(int)
		{
			iterator tmp = *this;
			_cur = rb_tree_iterator_increment(_cur);
			return tmp;
		}
		iterator& operator--()
		{
			_cur = rb_tree_iterator_increment(_cur);
			return *this;
		}
		iterator operator--(int)
		{
			iterator tmp = *this;
			_cur = rb_tree_iterator_decrement(_cur);
			return tmp;
		}
		
		template <typename LIter, typename RIter>
		friend bool operator==(const rb_tree_iterator<LIter>& l, const rb_tree_iterator<RIter>& r);
		template <typename Iter>
		friend bool operator==(const rb_tree_iterator<Iter>& l, const rb_tree_iterator<Iter>& r);
	private:
		node_pointer _cur;
		node_pointer _nil;
	};
	template <typename LIter, typename RIter>
	bool operator==(const rb_tree_iterator<LIter>& l, const rb_tree_iterator<RIter>& r)
	{ return l._cur == r._cur; }
	template <typename Iter>
	bool operator==(const rb_tree_iterator<Iter>& l, const rb_tree_iterator<Iter>& r)
	{ return l._cur == r._cur; }
	template <typename LIter, typename RIter, typename Cont>
	bool operator!=(const rb_tree_iterator<LIter>& l, const rb_tree_iterator<RIter>& r)
	{ return !(l == r); }
	template <typename Iter>
	bool operator!=(const rb_tree_iterator<Iter>& l, const rb_tree_iterator<Iter>& r)
	{ return !(l == r); }
}

#endif