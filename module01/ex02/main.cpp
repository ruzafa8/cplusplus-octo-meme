#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "memory address of str: " << &str << std::endl;
    std::cout << "memory address contained in stringPTR: " << stringPTR << std::endl;
    std::cout << "memory address contained in stringREF: " << &stringREF << std::endl;

    std::cout << "str value: " << str << std::endl;
    std::cout << "stringPTR value of pointed memory address: " << *stringPTR << std::endl;
    std::cout << "stringREF value of pointed memory address: " << stringREF << std::endl;
}