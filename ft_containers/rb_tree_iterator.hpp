#ifndef RB_TREE_ITERATOR_HPP
# define RB_TREE_ITERATOR_HPP

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
		node& operator=(const node& x)
		{
			value = x.value;
			
			return *this;
		}
	};

	template <typename T>
	class rb_tree_iterator
	{
	protected:
	
	public:
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef struct node<T> node;
		typedef node* node_pointer;

		rb_tree_iterator() {}
		//rb_tree_iterator(const Iter& x) : _cur(x) {}
		// template<typename CIter>
		// rb_tree_iterator(const rb_tree_iterator<Iter, typename enable_if<
		// 	(is_same<Iter, typename Cont::pointer>::value), Cont>::type>& x)
		// : _cur(x) {}
		~rb_tree_iterator() {}
		// const Iter& base() const { return _cur; }

		// reference			operator*() const { return *_cur; }
		// pointer				operator->() const { return _cur; }
		// rb_tree_iterator&	operator++() { ++_cur; return *this; }
		// rb_tree_iterator		operator++(int) { return rb_tree_iterator<Iter, Cont>(_cur++); }
		// rb_tree_iterator&	operator--() { --_cur; return *this; }
		// rb_tree_iterator		operator--(int) { return rb_tree_iterator<Iter, Cont>(_cur--); }
	};

	// template <typename LIter, typename RIter, typename Cont>
	// bool operator==(const rb_tree_iterator<LIter, Cont>& l, const rb_tree_iterator<RIter, Cont>& r)
	// { return l.base() == r.base(); }
	// template <typename Iter, typename Cont>
	// bool operator==(const rb_tree_iterator<Iter, Cont>& l, const rb_tree_iterator<Iter, Cont>& r)
	// { return l.base() == r.base(); }
	// template <typename LIter, typename RIter, typename Cont>
	// bool operator!=(const rb_tree_iterator<LIter, Cont>& l, const rb_tree_iterator<RIter, Cont>& r)
	// { return l.base() != r.base(); }
	// template <typename Iter, typename Cont>
	// bool operator!=(const rb_tree_iterator<Iter, Cont>& l, const rb_tree_iterator<Iter, Cont>& r)
	// { return l.base() != r.base(); }
}

#endif