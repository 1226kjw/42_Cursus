#include "Brain.hpp"

Brain::Brain()
{
	cout << "Brain's default constructor called" << endl;
	std::srand(std::time(0) * reinterpret_cast<unsigned long long>(this));
	for (int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		for (int j = 0; j < MAXIDEA; j++)
		{
			int r = std::rand() % (11*26*3);
			if (r >= 10*26*3)
				break ;
			if (r % 3 == 0)
				ss << static_cast<char>('0' + r%10);
			else if (r % 3 == 1)
				ss << static_cast<char>('a' + r%26);
			else if (r % 3 == 2)
				ss << static_cast<char>('A' + r%26);
		}
		ideas[i] = ss.str();
	}
}
Brain::Brain(const Brain& a)
{
	cout << "Brain's copy constructor called" << endl;
	*this = a;
}
Brain::~Brain()
{
	cout << "Brain's destructor called" << endl;
}
Brain& Brain::operator= (const Brain& a)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = a.ideas[i];
	return *this;
}

string Brain::getIdea(int i) const
{
	return ideas[i];
}

void Brain::tellIdeas() const
{
	cout << endl << "In my Brain(" << this << ")..." << endl;
	cout << "-------------------------------------------------------" << endl;
	for (int i = 0; i < 100; i++)
	{
		cout << std::setw(11) << ideas[i];
		if ((i+1) % 5 == 0)
			cout << endl;
	}
	cout << "-------------------------------------------------------" << endl << endl;
}
