#include "Identify.hpp"

Base* generate(void)
{
	static int v = 0;
	if (!v)
	{
		Base* tmp = new Base;
		v = std::time(0) * reinterpret_cast<unsigned long long>(tmp);
		std::srand(v);
		delete tmp;
	}
	switch (std::rand() % 3)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	default:
		return new C;
	}
	return 0;
}

void identify(Base* p)
{
	void* parr[3] = {dynamic_cast<A*>(p), dynamic_cast<B*>(p), dynamic_cast<C*>(p)};
	for (int i = 0; i < 3; i++)
		if (parr[i])
			cout << static_cast<char>('A' + i) << endl;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		cout << 'A' << endl;
		return ;
	} catch (std::exception& e){
		try {
			(void)dynamic_cast<B&>(p);
			cout << 'B' << endl;
			return ;
		} catch (std::exception& e){
			try {
				(void)dynamic_cast<C&>(p);
				cout << 'C' << endl;
			} catch (std::exception& e) {}
		}
	}
}
