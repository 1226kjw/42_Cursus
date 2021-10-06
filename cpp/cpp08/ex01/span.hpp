#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>
# include <iostream>

using std::multiset;
using std::cout;
using std::endl;

class Span
{
private:
	unsigned int N;
	multiset<int> s;
public:
	Span(unsigned int N);
	Span(const Span& a);
	~Span();
	Span& operator= (const Span& a);

	void addNumber(int n);
	
	template<typename T>
	void addNumbers(T begin, T end)
	{
		for (T i = begin; i != end; i++)
			addNumber(*i);
	}
	void printSpan();
	int shortestSpan();
	int longestSpan();
};

#endif
