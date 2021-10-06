#include "span.hpp"

#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;

int main()
{
	Span sp = Span(10);
	std::vector<int> v;
	v.push_back(1);
	v.push_back(20);
	v.push_back(23);
	v.push_back(7);
	v.push_back(10);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumbers(v.begin(), v.end());
	cout << sp.shortestSpan() << endl;
	cout << sp.longestSpan() << endl;
	sp.printSpan();

	cout << "------------------" << endl;
	int test = 10;
	Span sp2 = Span(test);
	std::srand(std::time(0)*reinterpret_cast<unsigned long long>(&sp));
	for (int i = 0; i < test; i++)
		sp2.addNumber(std::rand()%40000);
	cout << sp2.shortestSpan() << endl;
	cout << sp2.longestSpan() << endl;
	sp2.printSpan();
}
