#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include <cstdlib>
# include <ctime>
# include <iostream>

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

using std::cout;
using std::endl;

Base* generate(void);
void identify(Base* p);
void identify(Base& p);


#endif
