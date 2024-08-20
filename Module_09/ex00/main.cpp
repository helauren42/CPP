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
		std::ifstream	input_stream;
		input_stream.open(av[1]);
		if(input_stream.is_open() == false)
		{
			cerr << "File " << "\"" << av[1] << "\"" << "failed to open\n";
			return (1);
		};
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
