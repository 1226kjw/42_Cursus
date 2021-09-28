#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* b; 
public:
	Cat();
	Cat(const Cat& a);
	~Cat();
	Cat& operator= (const Cat& a);
	void makeSound() const;
	void tellIdeas() const;
};

#endif
