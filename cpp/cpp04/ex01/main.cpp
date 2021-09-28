#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


using std::cout;
using std::endl;
using std::string;

int main()
{
	Cat a;
	a.tellBrain();
	Cat b(a);
	b.tellBrain();
}
