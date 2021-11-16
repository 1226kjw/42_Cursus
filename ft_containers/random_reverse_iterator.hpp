#ifndef RANDOM_REVERSE_ITERATOR_HPP
# define RANDOM_REVERSE_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{
	template <typename Iter, typename Cont>
	class random_reverse_iterator
	: public iterator<
		typename iterator_traits<Iter>::iterator_category,
		typename iterator_traits<Iter>::value_type,
		typename iterator_traits<Iter>::difference_type,
		typename iterator_traits<Iter>::pointer,
		typename iterator_traits<Iter>::reference
	>
	{
	protected:
		Iter _cur;
	
	public:
		typedef typename iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename iterator_traits<Iter>::value_type value_type;
		typedef typename iterator_traits<Iter>::difference_type difference_type;
		typedef typename iterator_traits<Iter>::pointer pointer;
		typedef typename iterator_traits<Iter>::reference reference;

		random_reverse_iterator() : _cur(Iter()) {}
		random_reverse_iterator(const Iter& x) : _cur(x) {}
		// template<typename CIter>
		// random_reverse_iterator(const random_reverse_iterator<Iter, typename enable_if<
		// 	(is_same<Iter, typename Cont::pointer>::value), Cont>::type>& x)
		// : _cur(x) {}
		~random_reverse_iterator() {}
		const Iter& base() const { return _cur; }

		reference					operator*() const { return *_cur; }
		pointer						operator->() const { return _cur; }
		random_reverse_iterator&	operator++() { --_cur; return *this; }
		random_reverse_iterator		operator++(int) { return random_reverse_iterator<Iter, Cont>(_cur--); }
		random_reverse_iterator&	operator--() { ++_cur; return *this; }
		random_reverse_iterator		operator--(int) { return random_reverse_iterator<Iter, Cont>(_cur++); }
		reference					operator[](difference_type n) const { return *(_cur - n); }
		random_reverse_iterator&	operator+=(difference_type n) { _cur -= n; return *this; }
		random_reverse_iterator		operator+(difference_type n) { return random_reverse_iterator(_cur - n); }
		random_reverse_iterator&	operator-=(difference_type n) { _cur += n; return *this; }
		random_reverse_iterator		operator-(difference_type n) { return random_reverse_iterator(_cur + n); }
	};

	template <typename LIter, typename RIter, typename Cont>
	bool operator==(const random_reverse_iterator<LIter, Cont>& l, const random_reverse_iterator<RIter, Cont>& r)
	{ return l.base() == r.base(); }
	template <typename Iter, typename Cont>
	bool operator==(const random_reverse_iterator<Iter, Cont>& l, const random_reverse_iterator<Iter, Cont>& r)
	{ return l.base() == r.base(); }
	template <typename LIter, typename RIter, typename Cont>
	bool operator!=(const random_reverse_iterator<LIter, Cont>& l, const random_reverse_iterator<RIter, Cont>& r)
	{ return l.base() != r.base(); }
	template <typename Iter, typename Cont>
	bool operator!=(const random_reverse_iterator<Iter, Cont>& l, const random_reverse_iterator<Iter, Cont>& r)
	{ return l.base() != r.base(); }
	
	template <typename LIter, typename RIter, typename Cont>
	bool operator<(const random_reverse_iterator<LIter, Cont>& l, const random_reverse_iterator<RIter, Cont>& r)
	{ return l.base() > r.base(); }
	template <typename Iter, typename Cont>
	bool operator<(const random_reverse_iterator<Iter, Cont>& l, const random_reverse_iterator<Iter, Cont>& r)
	{ return l.base() > r.base(); }
	template <typename LIter, typename RIter, typename Cont>
	bool operator>(const random_reverse_iterator<LIter, Cont>& l, const random_reverse_iterator<RIter, Cont>& r)
	{ return l.base() < r.base(); }
	template <typename Iter, typename Cont>
	bool operator>(const random_reverse_iterator<Iter, Cont>& l, const random_reverse_iterator<Iter, Cont>& r)
	{ return l.base() < r.base(); }
	template <typename LIter, typename RIter, typename Cont>
	bool operator<=(const random_reverse_iterator<LIter, Cont>& l, const random_reverse_iterator<RIter, Cont>& r)
	{ return l.base() >= r.base(); }
	template <typename Iter, typename Cont>
	bool operator<=(const random_reverse_iterator<Iter, Cont>& l, const random_reverse_iterator<Iter, Cont>& r)
	{ return l.base() >= r.base(); }
	template <typename LIter, typename RIter, typename Cont>
	bool operator>=(const random_reverse_iterator<LIter, Cont>& l, const random_reverse_iterator<RIter, Cont>& r)
	{ return l.base() <= r.base(); }
	template <typename Iter, typename Cont>
	bool operator>=(const random_reverse_iterator<Iter, Cont>& l, const random_reverse_iterator<Iter, Cont>& r)
	{ return l.base() <= r.base(); }

	template <typename LIter, typename RIter, typename Cont>
	typename random_reverse_iterator<LIter, Cont>::difference_type
	operator-(const random_reverse_iterator<LIter, Cont>& l, const random_reverse_iterator<RIter, Cont>& r)
	{ return r.base() - l.base(); }
	template <typename Iter, typename Cont>
	typename random_reverse_iterator<Iter, Cont>::difference_type
	operator-(const random_reverse_iterator<Iter, Cont>& l, const random_reverse_iterator<Iter, Cont>& r)
	{ return r.base() - l.base(); }
	template <typename Iter, typename Cont>
	random_reverse_iterator<Iter, Cont>
	operator+(typename random_reverse_iterator<Iter, Cont>::difference_type n, const random_reverse_iterator<Iter, Cont>& i)
	{ return random_reverse_iterator<Iter, Cont>(i.base() - n); }
}

#endif