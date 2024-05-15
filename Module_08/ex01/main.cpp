#include "Span.hpp"

int	main(void)
{
	try
	{
		Span sp = Span(500);
		sp.addNumber(8);
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		sp.addNumber(4);
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		sp.addNumber(17);
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		sp.addNumber(9);
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		sp.addNumber(11);
		sp.addNumbersIter(100);
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
