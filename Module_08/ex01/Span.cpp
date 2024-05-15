#include "Span.hpp"
#include "stdlib.h"
#include <algorithm>

Span::Span()
: max_size(10000), curr_size(0)
{}

Span::Span(unsigned int n)
: max_size(n), curr_size(0)
{}

Span::~Span()
{}

void	Span::addNumber(int num)
{
	if(this->curr_size >= this->max_size)
		throw (spanOverFlow());
	this->v.push_back(num);
	this->curr_size++;
}

void	Span::addNumbersIter(int amount)
{
	static int	iter = 0;

	if(this->curr_size + amount >= this->max_size)
		throw (spanOverFlow());
	for (int i = 0; i < amount; i++)
	{
		srand(time(NULL) + iter);
		int value = rand();
		this->v.push_back(value);
		std::cout << "value: " << value << std::endl;
		this->curr_size++;
		iter++;
	}
}

int	Span::shortestSpan()
{
	int	previous;
	int	shortest_span = -1;
	int	span;
	std::sort(this->v.begin(), this->v.end());
	for(std::vector<int>::iterator it = this->v.begin(); it != v.end(); it++)
	{
		if(it == this->v.begin())
		{
			previous = *it;
			continue;
		}
		else
		{
			span = previous - *it;
			if(span < 0)
				span = -span;
			if(shortest_span == -1 || shortest_span > span)
				shortest_span = span;
			previous = *it;
		}
	}
	return (shortest_span);
}

int	Span::longestSpan()
{
	std::sort(this->v.begin(), this->v.end());
	int min = *std::min_element(this->v.begin(), this->v.end());
	int max = *std::max_element(this->v.begin(), this->v.end());
	return (max - min);
}

const char * Span::exceptNoSpan::what() const throw()
{
	return ("Size of numbers vector is <= 1, and thus no Span can be found");
}

std::out_of_range	Span::spanOverFlow()
{
	std::out_of_range	ret("The span vector is full already");

	return (ret);
}
