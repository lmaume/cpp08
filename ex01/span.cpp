#include "span.hpp"

Span::Span(unsigned int N)
{
	this->data = new int[N];
	size = N;
	end = 0;
	for (int i = 0; i < size - 1; i++)
		this->data[i] = 0;
}

Span::~Span()
{
	delete []this->data;
}

void Span::addNumber(int number)
{
	if (end < size)
	{
		data[end] = number;
		end++;
	}
	else
		throw(std::invalid_argument("No space avaliable."));
}

void Span::addNumbers(int number, ...)
{
	int tmp = 0;
	va_list ap;
	va_start(ap, number);
	for (int i = 0; i < this->size - 1; i++)
	{
		tmp = va_arg(ap, int);
		addNumber(tmp);
	}
	va_end(ap);
}

int Span::shortestSpan()
{
	int	i = 0;
	int	shortest = 0;

	if (end == 1)
		return (0);
	if (end > 0)
		shortest = data[0] - data[1];
	if (shortest < 0)
		shortest *= -1;
	while (i < end)
	{
		shortest = spanCmp(i, '<', shortest);
		i++;
	}
	return (shortest);
}

int Span::longestSpan()
{
	int	i = 0;
	int	longest = 0;

	if (end == 1)
		return (0);
	while (i < end)
	{
		longest = spanCmp(i, '>', longest);
		i++;
	}
	return (longest);
}

int	Span::spanCmp(int i, char sign, int base)
{
	int value = base;
	int j = 0;
	while (j < end)
	{
		if (j == i)
			j++;
		if (j == end)
			return (value);
		if (sign == '>')
		{
			if (data[j] > data[i] && (data[j] - data[i]) > value)
				value = data[j] - data[i];
			else if (data[j] < data[i] && (data[i] - data[j]) > value)
				value = data[i] - data[j];
		}
		else if (sign == '<')
		{
			if (data[j] > data[i] && (data[j] - data[i]) < value)
				value = data[j] - data[i];
			else if (data[j] < data[i] && (data[i] - data[j]) < value)
				value = data[i] - data[j];
		}
		j++;
	}
	return (value);
}
