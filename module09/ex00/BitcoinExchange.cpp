#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	loadData();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_exchange_rate = other._exchange_rate;
	}
	return *this;
}

void BitcoinExchange::loadData() {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	std::string line;

	int delim_pos;
	std::string date;
	std::string rate;
	while (file) {
		file >> line;
		delim_pos = line.find(',');
		date = line.substr(0, delim_pos);
		rate = line.substr(delim_pos + 1, line.size());
		_exchange_rate.insert(date, rate);
	}
}
