#include <iostream>
#include <string>
#include <fstream>

std::string replace(std::string line, std::string s1, std::string s2) {
    std::string result = "";
    std::string::size_type pos;
    size_t i = 0;
    size_t s1_len = s1.length();

    while (i < line.length()) {
        pos = line.find(s1, i);
        if (pos == std::string::npos) {
            return result + line.substr(i);
        }
        result += line.substr(i, pos - i) + s2;
        i = pos + s1_len;
    }
    return result;
}

bool validateArgs(int argc) {
    if (argc != 4) {
        std::cout << "usage: ./convert [filename] [string_to_replace] [string_replacement]" << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (!validateArgs(argc)) 
        return 1;

    std::string filename = argv[1];
    std::string c1 = argv[2];
    std::string c2 = argv[3];

    std::ifstream iFile(filename);
    if (!iFile.is_open()) {
        std::cout << "Error: could not open input file" << std::endl;
        return 1;
    }

    std::ofstream oFile(filename + ".replace");
    if (!oFile.is_open()) {
        std::cout << "Error: could not open output file" << std::endl;
        iFile.close();
        return 1;
    }

    std::string line;
    while (std::getline(iFile, line)) {
        oFile << replace(line, c1, c2) << std::endl;
    }
    iFile.close();
    oFile.close();
    return 0;
}