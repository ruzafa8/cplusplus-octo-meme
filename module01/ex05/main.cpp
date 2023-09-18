#include "Harl.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "usage: ./harl [WARNING|INFO|DEBUG|ERROR]" << std::endl;
		return 1;
	}
	if (std::string(argv[1]) != "WARNING" && std::string(argv[1]) != "INFO" && std::string(argv[1]) != "DEBUG" && std::string(argv[1]) != "ERROR") {
		std::cout << "usage: ./harl [WARNING|INFO|DEBUG|ERROR]" << std::endl;
		return 1;
	}

    Harl harl;

    harl.complain(argv[1]);
    return 0;
}