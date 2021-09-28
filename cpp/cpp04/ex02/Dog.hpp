#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* b;
public:
	Dog();
	Dog(const Dog& a);
	~Dog();
	Dog& operator= (const Dog& a);
	void makeSound() const;
	void tellIdeas() const;
};

#endif
