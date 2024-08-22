#include "BitcoinExchange.hpp"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>

void	BitcoinExchange::trimSpaces(string& s) {
	while(s.length() && std::isspace(s[0]))
		s.erase(s.begin());
	while(s.length() && std::isspace(s[s.length() -1]))
		s = s.substr(0, s.length() -1);
}

BitcoinExchange::BitcoinExchange(const string& dbName) {
	init_db(dbName);
}

BitcoinExchange::~BitcoinExchange() {
}

void	BitcoinExchange::init_db(const string& dbName) {

	std::ifstream	input_stream;
	input_stream.open(dbName.c_str());
	if(input_stream.is_open() == false) {
		cerr << "Database failed to open\n";
		throw Error();
	}

	std::string line, date;
	double price;
	while (std::getline(input_stream, line)) {
		std::size_t pos = line.find(',');
		if(pos == std::string::npos || line.length() < 10 || std::isdigit(line[0]) == false || std::isdigit((line[line.size() -1]) == false)) {
			continue;
		}
		date = line.substr(0, pos);
		if(this->earliestDate.empty() == true)
			earliestDate = date;
		std::stringstream ss(line.substr(pos +1, line.length() - pos));
		ss >> price;
		priceDate.insert(std::make_pair(date, price));
	}
}

bool monthis31(int month) {
	if (month == 1 || month == 3 || month == 5
		|| month == 7 || month == 8 || month == 10
		|| month == 12)
		return true;
	return false;
}

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

bool	splitDate(const string& date) {
	int year, month, day;
	char dash;
	
	std::stringstream ss(date);
	ss >> year >> dash >> month >> dash >> day;
	
	if(year > 2024 || month < 1 || month > 12 || day < 1)
		return false;
	if(month == 2 && isLeapYear(year) == true && day == 29)
		return true;
	if(day > 31
		|| (monthis31(month) == false && day > 30)
		|| month == 2 && day > 28)
		return false;
	return true;
}

bool BitcoinExchange::validDate(const string& date) {
	if(date.size() != 10)
		return false;
	for(int i = 0; i != date.size(); i++) {
		if(std::isdigit(date[i]) == false && date[i] != '-') {
			return false;
		}
		if((i == 4 || i == 7)) {
			if(date[i] != '-')
				return false;
		}
		else if (isdigit(date[i]) == false) {
			return false;
		}
	}
	return splitDate(date);
}

bool BitcoinExchange::validValue(double &value) {
	if(value < 0 || value > 1000)
		return false;
	return true;
}

double	BitcoinExchange::getBitcoinPrice(const string& date) {
	std::map<string, double>::iterator it = priceDate.lower_bound(date);
	if(it == priceDate.end() || date < earliestDate) {
		throw Custom("Could not find date in database it's too early => " + date);
	}
	if(it->first != date)
		it--;
	return it->second;
}

void	BitcoinExchange::processLine(const string& line) {

	try {
		size_t split_pos = line.find('|');
		if(split_pos == std::string::npos)
			throw LineInvalid(line);

		string	date = line.substr(0, split_pos);
		double	value;
		string str_value = line.substr(split_pos +1, line.length() - split_pos);
		std::stringstream ss(str_value);
		ss >> value;
		this->trimSpaces(date);
		if(this->validDate(date) == false)
			throw Custom("Date is not valid => " + date);
		if(this->validValue(value) == false)
			throw Custom("Value is out of range => " + str_value);
		double price = getBitcoinPrice(date);
		std::cout << date << " => " << value << " = " << value * price << std::endl;
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}
}

void	BitcoinExchange::processInput(const string& inputFile) {
	std::ifstream	input_stream;
	input_stream.open(inputFile.c_str());
	if(input_stream.is_open() == false) {
		throw Custom("Input file failed to open");
	}
	
	string line;
	while (std::getline(input_stream, line)) {
		BitcoinExchange::trimSpaces(line);
		if(line == "date | value")
			continue;
		processLine(line);
	}
}