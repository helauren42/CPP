#include <iostream>
#include <map>
#include <list>
#include <exception>
#include <stdexcept>
#include <sstream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class Data
{
	public:
		Data(std::list<std::string> file);
		~Data();
		bool isValid(std::string line);
		float fetchRate(std::string line);
		std::string fetchYear(std::string line);
		class	DataFileInvalid : public std::exception
		{
			public:
				explicit DataFileInvalid(const std::string& s)
				{
					message = "ERROR: Data invalid, verify line: ";
					message += s;
				}
				virtual const char* what() const noexcept;
			private:
				std::string message;
		};
	private:
		std::list<std::string> list;
		std::map<std::string, float> map;
};
