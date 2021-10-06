#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& cont, int tofind)
{
	return std::find(cont.begin(), cont.end(), tofind);
}

#endif
