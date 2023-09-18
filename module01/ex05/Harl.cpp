#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::complain(std::string level) {
    void (Harl::*complaintPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string complaint[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        if (level == complaint[i]) {
            (this->*complaintPtr[i])();
            return;
        }
    }
}

void Harl::debug(void) {
    std::cout << "[DEBUG] I'm a debug message." << std::endl;
}

void Harl::info(void) {
    std::cout << "[INFO] I'm an info message." << std::endl;
}

void Harl::warning(void) {
    std::cout << "[WARNING] I'm a warning message." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ERROR] I'm an error message." << std::endl;
}