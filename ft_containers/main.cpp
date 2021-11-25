#include <iostream>
#include <string>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "set.hpp"

using std::cout;
using std::endl;

template <typename F, typename S>
std::ostream& operator<<(std::ostream& out, const ft::pair<F, S>& p)
{
	out << '(' << p.first << ", " << p.second << ')';
	return out;
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const ft::vector<T>& v)
{
	out << '[';
	if (!v.empty())
	{
		out << v[0];
		for (size_t i = 1; i < v.size(); ++i)
			out << ", " << v[i];
	}
	out << ']';
	return out;
}
template <typename K, typename V>
std::ostream& operator<<(std::ostream& out, const ft::map<K, V>& m)
{
	out << '{';
	if (!m.empty())
	{
		typename ft::map<K, V>::const_iterator itr = m.begin();
		out << itr->first << ':' << itr->second;
		++itr;
		for (; itr != m.end(); ++itr)
			out << ", " << itr->first << ':' << itr->second;
	}
	out << '}';
	return out;
}
template <typename K>
std::ostream& operator<<(std::ostream& out, const ft::set<K>& s)
{
	out << '{';
	if (!s.empty())
	{
		typename ft::set<K>::const_iterator itr = s.begin();
		out << *itr;
		++itr;
		for (; itr != s.end(); ++itr)
			out << ", " << *itr;
	}
	out << '}';
	return out;
}

int main()
{
	// cout << "---------vector---------" << endl;
	// ft::vector<int> vbase;
	// for (int i = 3; i < 9; ++i)
	// 	vbase.push_back(i);
	// ft::vector<int> v(vbase.begin(), vbase.end());
	// cout << v << endl;;
	// v.insert(v.begin() + 1, 11);
	// cout << v << endl;
	// v.pop_back();
	// cout << v << endl;
	// v.erase(v.begin() + 3);
	// cout << v << endl;

	// ft::vector<bool> bv(3, false);
	// bv[1] = true;
	// bv.flip();
	// bv.swap(bv[1], bv[2]);
	// cout << bv << endl;


	// cout << "---------stack---------" << endl;
	// ft::stack<int> s;
	// for (int i = 5; i < 10; ++i)
	// 	s.push(i*i);
	// while (!s.empty())
	// {
	// 	cout << s.top() << ' ';
	// 	s.pop();
	// }
	// cout << endl;

	// cout << "---------map---------" << endl;
	// ft::map<std::string, double> m;
	// m["2nd_string"] = 212.11;
	// m["1st_string"] = 111.11;
	// m["3rd_string"] = 333.11;
	// for (size_t i = 0; i < v.size(); ++i)
	// 	m.insert(ft::make_pair(std::string("strnum") + static_cast<char>('0' + i%10), static_cast<double>(i*i*i)));
	// cout << m << endl;
	// cout << m.size() << endl;
	// cout << m["strnum3"] << endl;

	// cout << "---------set---------" << endl;
	// ft::set<std::string> ss;
	// for (ft::map<std::string, double>::iterator itr = m.begin(); itr != m.end(); ++itr)
	// 	ss.insert(itr->first);
	// cout << ss << endl;
	// cout << ss.size() << endl;

	ft::set<int> s;
	s.insert(42);

	s.insert(50);
	s.insert(25);

	s.insert(46);
	s.insert(21);
	s.insert(30);
	s.insert(55);

	s.insert(18);
	s.insert(23);
	s.insert(28);
	s.insert(35);
	s.insert(44);
	s.insert(48);
	s.insert(53);
	s.insert(80);
	
	s.insert(12);
	s.insert(20);
	s.insert(22);
	s.insert(24);
	s.insert(27);
	s.insert(29);
	s.insert(33);
	s.insert(38);

	s.insert(43);
	s.insert(45);
	s.insert(47);
	s.insert(49);
	s.insert(51);
	s.insert(54);
	s.insert(60);
	s.insert(90);

	s.erase(25);
	s.erase(55);
	s.erase(24);
	s.erase(54);

	s.erase(22);
	s.erase(51);
	s.erase(21);
	s.erase(23);

	s.erase(20);
	s.erase(23);
	s.erase(42);

	s.erase(38);
	s.erase(35);
	s.print();
	cout << "---------------" << endl;
	s.erase(33);
	s.print();

	cout << s << endl;

	return 0;
}
