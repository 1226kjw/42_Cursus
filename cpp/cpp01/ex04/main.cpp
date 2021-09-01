#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void replace(string &readin, string s1, string s2)
{
	for (int i = 0; readin[i]; i++)
	{
		if (readin.substr(i, s1.size()) == s1)
		{
			readin = readin.substr(0, i) + s2 + readin.substr(i + s1.size());
			i += s2.size() - 1;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		cout << "Invalid argc" << endl;
		return -1;
	}
	string fin(argv[1]);
	string s1(argv[2]);
	string s2(argv[3]);
	if (fin.size() * s1.size() * s2.size() == 0)
	{
		cout << "argv length cannot be 0" << endl;
		return -1;
	}
	std::ifstream in(&fin[0]);
	if (in.is_open())
	{
		in.seekg(0, std::ios::end);
		int size = in.tellg();
		in.seekg(0, std::ios::beg);
		string readin;
		readin.resize(size);
		in.read(&readin[0], size);
		replace(readin, s1, s2);
		std::ofstream out(&(fin + ".replace")[0]);
		out << readin;
	}
	else
		cout << "Cannot open file: " << fin << endl;
}
