#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

template<typename T>
size_t easyfind(T container, int wanted)
{
	typename T::iterator	it = container.begin();
	int						i = 0;

	while (it != container.end())
	{
		if (*it == wanted)
			return i;
		it++;
		i++;
	}
	throw (std::invalid_argument("Invalid arg"));
}

#endif