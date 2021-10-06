#include "mutantstack.hpp"

#include <iostream>

using std::cout;
using std::endl;
int main()
{
	MutantStack<int> mstack;
	MutantStack<int> m(mstack);
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	it = it + 2;
	it = it - 1;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	mstack.print();
	std::stack<int> s(mstack);
	return 0;
}
/*int main()
{
	MutantStack<int> m;
	m.push(3);
	m.push(5);
	m.push(8);
	m.push(10);
	for (MutantStack<int>::iterator i = m.begin(); i != m.end(); i++)
		cout << *i << " ";
}*/
