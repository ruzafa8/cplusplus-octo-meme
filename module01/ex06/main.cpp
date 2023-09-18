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

int main(int argc, char **argv) {
    if (!validateArgs(argc, argv)) 
        return 1;

    Harl harl;
    std::string level = argv[1];
	std::string complaint[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int complaintIndex = -1;

    for (int i = 0; i < 4; i++) {
        if (level == complaint[i]) {
            complaintIndex = i;
			break;
        }
    }
	switch (complaintIndex)
	{
	case 0:
		harl.complain("DEBUG");
	case 1:
		harl.complain("INFO");
	case 2:
		harl.complain("WARNING");
	case 3:
		harl.complain("ERROR");
		break;
	}
	return 0;
}