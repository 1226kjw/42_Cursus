#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

template<typename T>
void printall(T a)
{
	for (typename T::iterator i = a.begin(); i != a.end(); i++)
		cout << *i << " ";
	cout << endl;
}

int main()
{
	int limit = 10;
	std::srand(std::time(0));
	std::vector<int> a;
	std::list<int> b;
	std::set<int> c;
	std::deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		a.push_back(std::rand()%limit);
		b.push_back(std::rand()%limit);
		c.insert(std::rand()%limit);
		d.push_back(std::rand()%limit);
	}
	int tofind = 3;
	cout << (easyfind(a, tofind)==a.end()?"not exists":"exists") << endl;
	printall(a);
	cout << (easyfind(b, tofind)==b.end()?"not exists":"exists") << endl;
	printall(b);
	cout << (easyfind(c, tofind)==c.end()?"not exists":"exists") << endl;
	printall(c);
	cout << (easyfind(d, tofind)==d.end()?"not exists":"exists") << endl;
	printall(d);
}
