#include "span.hpp"

Span::Span(unsigned int N): N(N), s(multiset<int>()) {}
Span::Span(const Span& a) : N(a.N), s(a.s) {}
Span::~Span() {}
Span& Span::operator= (const Span& a)
{
	N = a.N;
	s = a.s;
	return *this;
}

void Span::addNumber(int n)
{
	if (s.size() == N)
		throw std::out_of_range("span is already full");
	s.insert(n);
}

void Span::printSpan()
{
	for (multiset<int>::iterator i = s.begin(); i != s.end(); i++)
		cout << *i << " ";
	cout << endl;
}

int Span::shortestSpan()
{
	if (s.size() < 2)
		throw std::out_of_range("span is too small");
	int shortest = *--s.end() - *s.begin();
	for (multiset<int>::iterator i = s.begin();;)
	{
		int f = *i;
		if (++i == s.end())
			break ;
		int b = *i;
		shortest = std::min(shortest, f>b?f-b:b-f);
	}
	return shortest;
}

int Span::longestSpan()
{
	if (s.size() < 2)
		throw std::out_of_range("span is too small");
	return *--s.end() - *s.begin();
}
