#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>

class BitcoinExchange {
	private:
		std::map<std::string, std::string> _exchange_rate;

		void loadData();

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);

		BitcoinExchange &operator=(const BitcoinExchange &other);
};

#endif