#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <ctime>

# define MAXIDEA 10

using std::string;
using std::cout;
using std::endl;

class Brain
{
private:
	string ideas[100];
public:
	Brain();
	Brain(const Brain& a);
	~Brain();
	Brain& operator= (const Brain& a);
	string getIdea(int i) const;
	void tellIdeas() const;
};

#endif
