#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "random_iterator.hpp"
# include "random_reverse_iterator.hpp"

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
		typedef random_reverse_iterator<pointer, vector> reverse_iterator;
		typedef random_reverse_iterator<const_pointer, vector> const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type difference_type;
		typedef size_t size_type;

		vector(const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_start = _finish = _end_storage = _alloc.allocate(0);
		}
		vector(int n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_start = _finish = _alloc.allocate(n);
			_end_storage = _start + n;
			while (n--)
				*_finish++ = val;
		}
		template <typename Iter>
		vector(typename ft::enable_if<!ft::is_same<typename Iter::iterator_category, random_access_iterator_tag>::value, Iter>::type first,
				Iter last, const allocator_type& alloc = allocator_type())
		{
			size_type n = 0;
			for (Iter cur = first; cur != last; ++cur)
				++n;
			_alloc = alloc;
			_start = _finish = _alloc.allocate(n);
			_end_storage = _start + n;
			while (n--)
				*_finish++ = *first++;
		}
		template <typename Iter>
		vector(typename ft::enable_if<ft::is_same<typename Iter::iterator_category, random_access_iterator_tag>::value, Iter>::type first,
				Iter last, const allocator_type& alloc = allocator_type())
		{
			size_type n = last - first;
			_alloc = alloc;
			_start = _finish = _alloc.allocate(n);
			_end_storage = _start + n;
			while (n--)
				*_finish++ = *first++;
		}
		vector(const vector& x)
		{
			_alloc = x._alloc;
			_start = _finish = _alloc.allocate(x.capacity());
			_end_storage = _start + x.capacity();
			for (size_t i = 0; i < x.size(); ++i)
				_start[i] = x[i];
		}

		//iterators
		iterator				begin() { return _start; }
		iterator				end() { return _finish; }
		const_iterator			begin() const { return _start; }
		const_iterator			end() const { return _finish; }
		reverse_iterator		rbegin() { return _finish - 1; }
		reverse_iterator		rend() { return _start - 1; }
		const_reverse_iterator	rbegin() const { return _finish - 1; }
		const_reverse_iterator	rend() const { return _start - 1; }
		
		//capacity
		size_type size() const
		{
			return _finish - _start;
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
			if (n < size())
				_finish -= size() - n;
			else if (n > size())
			{
				if (n > capacity())
					reserve(n);
				while (n > size())
					*_finish++ = val;
			}
		}
		size_type capacity() const
		{
			return _end_storage - _start;
		}
		bool empty() const
		{
			return _start == _finish;
		}
		void reserve(size_type n)
		{
			if (n > max_size())
				throw std::length_error("vector::reserve");
			if (capacity() < n && n < 2 * capacity())
				n = 2 * capacity();
			if (n > capacity())
			{
				pointer new_start, new_end;
				new_start = new_end = _alloc.allocate(n);
				for (pointer i = _start; i != _finish; ++i)
					*new_end++ = *i;
				_alloc.destroy(_start);
				_alloc.deallocate(_start, capacity());
				_start = new_start;
				_finish = new_end;
				_end_storage = _start + n;
			}
		}

		//element access
		reference operator[](size_type n)
		{
			return _start[n];
		}
		const_reference operator[](size_type n) const
		{
			return _start[n];
		}
		reference at(size_type n)
		{
			if (n >= size())
				throw std::out_of_range("vector::at");
			return _start[n];
		}
		const_reference at(size_type n) const
		{
			if (n >= size())
				throw std::out_of_range("vector::at");
			return _start[n];
		}
		reference front()
		{
			return *_start;
		}
		const_reference front() const
		{
			return *_start;
		}
		reference back()
		{
			return *(_finish - 1);
		}
		const_reference back() const
		{
			return *(_finish - 1);
		}

		//modifier
		template <typename Iter>
		void assign(typename ft::enable_if<!ft::is_same<typename Iter::iterator_category, random_access_iterator_tag>::value, Iter>::type first, Iter last)
		{
			size_type n = 0;
			for (Iter cur = first; cur != last; ++cur)
				++n;
			reserve(n);
			_finish = _start;
			while (n--)
				*_finish++ = *first++;
		}
		template <typename Iter>
		void assign(typename ft::enable_if<ft::is_same<typename Iter::iterator_category, random_access_iterator_tag>::value, Iter>::type first, Iter last)
		{
			size_type n = last - first;
			reserve(n);
			_finish = _start;
			while (n--)
				*_finish++ = *first++;
		}
		void assign(size_type n, const value_type& val)
		{
			reserve(n);
			_finish = _start;
			while (n--)
				*_finish++ = val;
		}
		void push_back(const value_type& val)
		{
			if (_finish == _end_storage)
				reserve(capacity() + 1);
			*_finish++ = val;
		}
		void pop_back()
		{
			--_finish;
		}
		iterator insert(iterator position, const value_type& val)
		{
			size_type tmp = position - begin();
			reserve(size() + 1);
			position = begin() + tmp;
			reserve(size() + 1);
			iterator cur;
			for (cur = end(); cur != position; --cur)
				*cur = *(cur - 1);
			*cur = val;
			++_finish;
			return cur;
		}
		iterator insert(iterator position, size_type n, const value_type& val)
		{
			size_type tmp = position - begin();
			reserve(size() + n);
			position = begin() + tmp;
			iterator cur;
			for (cur = end() + n - 1; cur != position + n - 1; --cur)
				*cur = *(cur - n);
			for (; cur >= position; --cur)
				*cur = val;
			_finish += n;
			return ++cur;
		}
		template <typename Iter>
		iterator insert(iterator position, Iter first,
				typename ft::enable_if<!ft::is_same<typename Iter::iterator_category, random_access_iterator_tag>::value, Iter>::type last)
		{
			size_type n = 0;
			for (Iter cur = first; cur != last; ++cur)
				++n;
			size_type tmp = position - begin();
			reserve(size() + n);
			position = begin() + tmp;
			iterator cur;
			for (cur = end() + n - 1; cur != position + n - 1; --cur)
				*cur = *(cur - n);
			for (; cur >= position; --cur)
				*cur = *--last;
			_finish += n;
			return ++cur;
		}
		template <typename Iter>
		iterator insert(iterator position, Iter first,
				typename ft::enable_if<ft::is_same<typename Iter::iterator_category, random_access_iterator_tag>::value, Iter>::type last)
		{
			size_type n = last - first;
			size_type tmp = position - begin();
			reserve(size() + n);
			position = begin() + tmp;
			iterator cur;
			for (cur = end() + n - 1; cur != position + n - 1; --cur)
				*cur = *(cur - n);
			for (; cur >= position; --cur)
				*cur = *--last;
			_finish += n;
			return ++cur;
		}
		iterator erase(iterator position)
		{
			iterator tmp(position);
			tmp->~value_type();
			for (; tmp != end(); ++tmp)
				*tmp = *(tmp + 1);
			--_finish;
			return position;
		}
		iterator erase(iterator first, iterator last)
		{
			iterator tmp(first);
			size_type n = 0;
			for (; tmp != last; ++tmp, ++n)
				tmp->~value_type();
			tmp = first;
			for (; tmp + n != end(); ++tmp)
				*tmp = *(tmp + n);
			_finish -= n;
			return first;
		}
		void swap(vector& x)
		{
			pointer tmp = _start;
			_start = x._start;
			x._start = tmp;
			tmp = _finish;
			_finish = x._finish;
			x._finish = tmp;
			tmp = _end_storage;
			_end_storage = x._end_storage;
			x._end_storage = tmp;
		}
		void clear()
		{
			for (iterator itr = begin(); itr != end(); ++itr)
				itr->~value_type();
			_finish = _start;
		}
		
		//allocator
		allocator_type get_allocator() const
		{
			return _alloc;
		}

	private:
		allocator_type _alloc;
		pointer _start;
		pointer _finish;
		pointer _end_storage;
	};

	template <typename T, class Alloc>
	bool operator==(const vector<T, Alloc>& l, const vector<T, Alloc>& r)
	{
		if (l.size() != r.size())
			return false;
		for (typename vector<T, Alloc>::size_type i = 0; i < l.size(); ++i)
			if (l[i] != r[i])
				return false;
		return true;
	}
	template <typename T, class Alloc>
	bool operator!=(const vector<T, Alloc>& l, const vector<T, Alloc>& r)
	{
		return !(l == r);
	}
	template <typename T, class Alloc>
	bool operator<(const vector<T, Alloc>& l, const vector<T, Alloc>& r)
	{
		for (typename vector<T, Alloc>::size_type i = 0; i < l.size() && i < r.size(); ++i)
			if (l[i] != r[i])
				return l[i] < r[i];
		return l.size() < r.size();
	}
	template <typename T, class Alloc>
	bool operator<=(const vector<T, Alloc>& l, const vector<T, Alloc>& r)
	{
		return !(r < l);
	}
	template <typename T, class Alloc>
	bool operator>(const vector<T, Alloc>& l, const vector<T, Alloc>& r)
	{
		return r < l;
	}
	template <typename T, class Alloc>
	bool operator>=(const vector<T, Alloc>& l, const vector<T, Alloc>& r)
	{
		return !(l < r);
	}
	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
};

#endif
