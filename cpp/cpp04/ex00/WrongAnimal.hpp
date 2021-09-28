#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::endl;

class WrongAnimal
{
protected:
	string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& a);
	~WrongAnimal();
	WrongAnimal& operator= (const WrongAnimal& a);
	string getType() const;
	void makeSound() const;
};

#endif
