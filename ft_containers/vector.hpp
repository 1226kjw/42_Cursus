#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "random_iterator.hpp"
# include <memory>

namespace ft
{
	template<typename T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename Alloc::reference reference;
		typedef typename Alloc::const_reference const_reference;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;
		typedef random_iterator<pointer, vector> iterator;
		typedef random_iterator<const_pointer, vector> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type difference_type;
		typedef size_t size_type;

		vector(const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_start = _end = _end_storage = _alloc.allocate(0);
		}
		vector(int n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_start = _end = _alloc.allocate(n);
			_end_storage = _start + n;
			while (n--)
				*_end++ = val;
		}
		template <typename Iter>
		vector(typename ft::enable_if<!ft::is_same<typename Iter::value_type, void>::value>::type first,
				Iter last, const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			Iter cur = first;
			// for (Iter cur = first; cur != last; ++cur)
			// 	push_back(*cur);
		}
		vector(const vector& x)
		{
			_alloc = x._alloc;
			_start = _end = _alloc.allocate(x.capacity());
			_end_storage = _start + x.capacity();
			for (size_t i = 0; i < x.size(); ++i)
				_start[i] = x[i];
		}

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _end;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _end;
		}
		

		size_type size() const
		{
			return _end - _start;
		}
		size_type max_size()
		{
			ptrdiff_t m = 1;
			m <<= sizeof(ptrdiff_t) * 8 - 1;
			m = ~m;
			size_type diffmax = m;
			size_type allocmax = _alloc.max_size();
			return std::min(diffmax, allocmax);
		}
		void resize(size_type n, value_type val = value_type())
		{
			//if (n > )
		}
//	private:
		allocator_type _alloc;
		pointer _start;
		pointer _end;
		pointer _end_storage;
	};
};

#endif
