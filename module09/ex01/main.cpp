#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: Usage ./RPN \"[numbers|+|-|*|/]\"";
		return 1;
	}
	try {
		RPN r;
		r.insertData(std::string(argv[1]));
		int res = r.pop();
		std::cout << res << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}