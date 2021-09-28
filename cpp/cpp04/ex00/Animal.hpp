#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::endl;

class Animal
{
protected:
	string type;
public:
	Animal();
	Animal(const Animal& a);
	virtual ~Animal();
	Animal& operator= (const Animal& a);
	string getType() const;
	virtual void makeSound() const;
};

#endif
