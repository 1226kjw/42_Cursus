#include <iostream>
#include "Data.hpp"

using std::cout;
using std::string;
using std::endl;

int main()
{
	Data d = {10, 'a', "abcde"};
	uintptr_t a = serialize(&d);
	Data* dp = deserialize(a);
	cout << &d << endl << (void*)a << endl << dp << endl << endl;
	cout << (&d+1) << endl << std::hex << "0x" << ++a << endl;
	cout << *(string*)(serialize(&d)+8);
}
