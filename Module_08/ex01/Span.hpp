#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>

class Span
{
	public:
		Span();
		Span(unsigned int n);
		~Span();

		// METHODS
		void	addNumber(int num);
		void	addNumbersIter(int amount);
		std::out_of_range	spanOverFlow();

		int	shortestSpan();
		int	longestSpan();

		class exceptNoSpan : public std::exception
		{
			public:
			virtual const char *what() const throw();
		};

	private:
		uintptr_t			ptr_addr;
		std::vector<int>	v;
		unsigned int		curr_size;
		unsigned int		max_size;
};

#endif
