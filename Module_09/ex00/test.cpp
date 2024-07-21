
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& dbFilename);
    void evaluate(const std::string& inputFilename);

private:
    std::map<std::string, double> priceDatabase;

    void loadDatabase(const std::string& dbFilename);
    void processLine(const std::string& line);
    std::string trim(const std::string& str);
    double getPriceForDate(const std::string& date);
};



BitcoinExchange::BitcoinExchange(const std::string& dbFilename) {
    loadDatabase(dbFilename);
}

void BitcoinExchange::evaluate(const std::string& inputFilename) {
    std::ifstream infile(inputFilename);
    if (!infile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        processLine(line);
    }
}

void BitcoinExchange::loadDatabase(const std::string& dbFilename) {
    std::ifstream dbfile(dbFilename);
    if (!dbfile.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line, date;
    double price;
    while (std::getline(dbfile, line)) {
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        ss >> price;
        priceDatabase[date] = price;
    }
}

void BitcoinExchange::processLine(const std::string& line) {
    std::stringstream ss(line);
    std::string date, valueStr;
    if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    date = trim(date);
    try {
        double value = std::stod(trim(valueStr));
        if (value < 0 || value > 1000) {
            std::cerr << "Error: value out of range => " << value << std::endl;
            return;
        }

        double price = getPriceForDate(date);
        std::cout << date << " => " << value << " = " << value * price << std::endl;
    } catch (const std::invalid_argument&) {
        std::cerr << "Error: invalid number => " << valueStr << std::endl;
    } catch (const std::out_of_range&) {
        std::cerr << "Error: number out of range => " << valueStr << std::endl;
    }
}

std::string BitcoinExchange::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" ");
    size_t end = str.find_last_not_of(" ");
    return str.substr(start, end - start + 1);
}

double BitcoinExchange::getPriceForDate(const std::string& date) {
    auto it = priceDatabase.lower_bound(date);
    if (it == priceDatabase.end() || it->first != date) {
        if (it != priceDatabase.begin()) {
            --it;
        }
    }
    return it->second;
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    BitcoinExchange btcExchange("data.csv");
    btcExchange.evaluate(argv[1]);

    return 0;
}
