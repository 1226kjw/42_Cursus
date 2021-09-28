#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& a);
	virtual ~Cat();
	Cat& operator= (const Cat& a);
	virtual void makeSound() const;
};

#endif
