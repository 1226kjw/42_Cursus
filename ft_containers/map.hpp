#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "pair.hpp"
# include "rb_tree.hpp"
# include "iterator.hpp"

namespace ft
{
	template <typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
		public:
			value_compare(Compare c): comp(c){}
			bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
		private:
			Compare comp;
		};
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef rb_tree<key_type, value_type, Select1st<value_type>, key_compare, allocator_type> tree;

		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _container(tree()), _comp(comp), _alloc(alloc) {}
		template <typename Iter>
		map(typename ft::enable_if<!ft::is_same<typename Iter::iterator_category, void>::value, Iter>::type first,
				Iter last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _container(tree()), _comp(comp), _alloc(alloc) {}
		map(const map& x): _container(x._container), _comp(x._comp), _alloc(x._alloc) {}
	private:
		tree _container;
		key_compare _comp;
		allocator_type _alloc;
	};
};

#endif