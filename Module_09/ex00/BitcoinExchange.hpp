#include <iostream>
#include <map>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <sstream>
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
		void	processInput(const string& inputFile);
		void	processLine(const string& line);
		bool	validDate(const string& date);
		bool	validValue(double &value);
		double	getBitcoinPrice(const string& date);
		class	Custom : public std::exception
		{
			public:
				explicit Custom(const std::string& s)
				{
					message = "ERROR: ";
					message += s;
				}
				virtual const char* what() const throw()
				{
					return (message.c_str());
				};
				virtual ~Custom() throw() {}
			private:
				std::string message;
		};
		class	ValueInvalid : public std::exception
		{
			public:
				ValueInvalid(const std::string& s)
				{
					message = "ERROR: value must be a float between 0 and 1000 => ";
					message += s;
				}
				virtual const char* what() const throw()
				{
					return (message.c_str());
				};
				virtual ~ValueInvalid() throw() {}
			private:
				std::string message;
		};
		class	LineInvalid : public std::exception
		{
			public:
				explicit LineInvalid(const std::string& s)
				{
					message = "ERROR: verify line => ";
					message += s;
				}
				virtual const char* what() const throw()
				{
					return (message.c_str());
				};
				virtual ~LineInvalid() throw() {}
			private:
				std::string message;
		};
		class Error : public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return ("Error\n");
				};
				virtual ~Error() throw() {};
			private:
				std::string message;
		};
	private:
		std::map<std::string, double> priceDate;
};
