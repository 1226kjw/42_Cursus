#include <iostream>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "set.hpp"
using std::cout;
using std::endl;

int main()
{
	ft::map<int, int> a;
	for (int i = 0; i < 3000; ++i)
		a.insert(ft::make_pair(i,i*i));
		//a[i] = i*i;
	for (ft::map<int, int>::iterator itr = a.begin(); itr != a.end(); ++itr)
		cout << itr->first << ' ' << itr->second << endl;
	a.erase(1);
	a.erase(12);
	a.erase(13);
	a.erase(21);
	a.erase(31);
	a.erase(41);
	a.erase(1);
	a.erase(3);
	a.erase(5);
	cout << a.size() << endl;
	a.print();
	ft::set<int> b;
	return 0;
}
