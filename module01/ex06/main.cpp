#include "Harl.hpp"

bool    validateArgs(int argc, char *argv[]) {
    std::string level;
    if (argc != 2) {
        std::cout << "usage: ./harl [WARNING|INFO|DEBUG|ERROR]" << std::endl;
        return false;
    }
    level = argv[1];

    if (level != "WARNING" && level != "INFO" && level != "DEBUG" && level != "ERROR") {
        std::cout << "usage: ./harl [WARNING|INFO|DEBUG|ERROR]" << std::endl;
        return false;
    }
    return true;
}

int main(void) {
    if (!validateArgs(argc, argv)) 
        return 1;

    Harl harl;
    std::string level = argv[1];

    switch (level) {
        case "DEBUG":   harl.debug();
        case "INFO":    harl.info();
        case "WARNING": harl.warning();
        case "ERROR":   harl.error();
    }
    return 0;
}