#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <algorithm>
# include <cstdlib>
# include <map>

class BitcoinExchange {
	private:
		std::map<std::string, double> _exchange_rate;

		void loadData();
		double performExchange(const std::string &date, double amount);
		bool validDate(const std::string &date);
		bool validRate(const std::string &rate);
		double getClosestRate(const std::string &date);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);

		BitcoinExchange &operator=(const BitcoinExchange &other);
		void parseFile(const std::string &filename);
		
};

#endif