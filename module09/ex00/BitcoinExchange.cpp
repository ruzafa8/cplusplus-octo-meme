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
	} else {
		std::string line;

		int delim_pos;
		std::string date;
		std::string rate;
		while (std::getline(file, line)) {
			if (line.empty()) {
				continue;
			}
			if (line == "date,exchange_rate") {
				continue;
			}
			std::remove(line.begin(), line.end(), ' ');
			delim_pos = line.find(',');
			date = line.substr(0, delim_pos);
			rate = line.substr(delim_pos + 1, line.size());
			_exchange_rate[date] = std::strtod(rate.c_str(), 0);
		}
	}
}

double BitcoinExchange::performExchange(const std::string &date, double amount) {
	double rate = getClosestRate(date);
	return amount * rate;
}

void BitcoinExchange::parseFile(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
	} else {
		std::string line;

		size_t delim_pos;
		std::string date;
		std::string str_amount;
		while (std::getline(file, line)) {
			
			if (line.empty()) {
				continue;
			}
			if (line == "date | value") {
				continue;
			}
			delim_pos = line.find(" | ");
			if (delim_pos == std::string::npos) {
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}
			date = line.substr(0, delim_pos);
			str_amount = line.substr(delim_pos + 3, line.size());
			if (!validDate(date)) {
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}
			if (!validRate(str_amount)) {
				std::cerr << "Error: not a positive number" << std::endl;
				continue;
			}
			double amount = std::strtod(str_amount.c_str(), 0);
			if (amount > 1000) {
				std::cerr << "Error: too large number" << std::endl;
				continue;
			}
			double res = performExchange(date, amount);
			std::cout << date << " => " << amount << " = " << res << std::endl;
		}
	}
}

bool BitcoinExchange::validDate(const std::string &date) {
	// Format is YYYY-MM-DD
  if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    return false;
  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (month == 2 && day > 29)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2 && day == 29 && year % 4 != 0)
        return false;
    return true;
}

bool BitcoinExchange::validRate(const std::string &rate) {
	for (size_t i = 0; i < rate.size(); i++) {
		if ((rate[i] < '0' || rate[i] > '9') && rate[i] != '.')
			return false;
	}
	return true;
}

double BitcoinExchange::getClosestRate(const std::string &date) {
	std::map<std::string, double>::iterator it = _exchange_rate.find(date);
	if (it != _exchange_rate.end()) {
		return it->second;
	}
	it = _exchange_rate.lower_bound(date);
	it--;
	return it->second;
}
