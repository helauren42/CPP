#include "BitcoinExchange.hpp"

int	main(int ac, char **av, char **env)
{
	if(ac != 2)
	{
		std::cerr << "Program must take a file as argument\n";
		return (1);
	}

	BitcoinExchange btc("data.csv");
	btc.processFileInput(av[1]);
	return (0);
}
