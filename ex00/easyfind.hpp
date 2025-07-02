#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

template<typename T>
class easyfind
{

	private:
	public:
		void easyfind(T container, int wanted)
		{
			int i = 0;
			while (container[i] != NULL && container[i] != wanted)
				i++;
			return container[i];
		}
};

#endif