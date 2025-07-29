#ifndef SPAN_HPP
# define SPAN_HPP

#include <cstdarg>
#include <iostream>

class Span
{
	private:
		int*	data;
		int		size;
		int		end;
		int		spanCmp(int i, char sign, int base);
	public:
		void	addNumber(int number);
		void	addNumbers(int number, ...);
		int		shortestSpan();
		int		longestSpan();
		Span(unsigned int N);
		~Span();
};

#endif