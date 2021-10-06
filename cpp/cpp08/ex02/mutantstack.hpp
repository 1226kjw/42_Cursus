#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

using std::cout;
using std::endl;

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack& a) : std::stack<T>(a) {}
	~MutantStack() {}
	MutantStack& operator= (const MutantStack& a) {std::stack<T>::operator=(a); return *this;}

	typedef class MyIterator {
	private:
		T* cur;
	public:
		MyIterator(T* p): cur(p) {}
		MyIterator(const MyIterator& a): cur(a.cur) {}
		~MyIterator() {}
		MyIterator& operator= (const MyIterator& a) {cur = a.cur; return *this;}

		MyIterator operator++() {cur++; return *this;}
		MyIterator operator++(int) {MyIterator tmp(*this); cur++; return tmp;}
		MyIterator operator--() {cur--; return *this;}
		MyIterator operator--(int) {MyIterator tmp(*this); cur--; return tmp;}
		MyIterator operator+(int n) {return MyIterator(*this) += n;}
		MyIterator& operator+=(int n) {cur += n; return *this;}
		MyIterator operator-(int n) {return MyIterator(*this) -= n;}
		MyIterator& operator-=(int n) {cur -= n; return *this;}
		T& operator* () {return *cur;}
		bool operator== (const MyIterator& a) {return cur == a.cur;}
		bool operator!= (const MyIterator& a) {return cur != a.cur;}
		bool operator< (const MyIterator& a) {return cur < a.cur;}
		bool operator<= (const MyIterator& a) {return cur <= a.cur;}
		bool operator> (const MyIterator& a) {return cur > a.cur;}
		bool operator>= (const MyIterator& a) {return cur >= a.cur;}
	} iterator;
	iterator begin() {return iterator(&this->top() - this->size() + 1);}
	iterator end() {return iterator(&this->top() + 1);}
	void print() {for (iterator i = begin(); i != end(); i++) cout << *i << " "; cout << endl;}
};

#endif
