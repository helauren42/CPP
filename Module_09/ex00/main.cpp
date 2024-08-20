#include "BitcoinExchange.hpp"

int	main(int ac, char **av, char **env)
{
	if(ac != 2)
	{
		std::cerr << "Program must take a file as argument\n";
		return (1);
	}

	try
	{
		BitcoinExchange btc("data.csv");
		btc.processInput(av[1]);
	}
	catch(const std::exception& e) 
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
