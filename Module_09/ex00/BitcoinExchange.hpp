#include <iostream>
#include <map>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class BitcoinExchange
{
	public:
		BitcoinExchange(const string& dbName);
		~BitcoinExchange();

		void	trimSpaces(string& s);
		void	init_db(const string& dbName);
		void	processFileInput(const string& inputFile);
		void	processLine(const string& line);
		bool	validDate(const string& date);
		bool	validValue(double &value);
		double	getBitcoinPrice(const string& date);
	private:
		std::map<std::string, double>	priceDate;
		string							earliestDate;
};
