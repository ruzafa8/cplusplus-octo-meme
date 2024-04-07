#include "iter.hpp"

void printDouble(const int &x) {
	std::cout << (x * 2) << " ";
}

void capitalize(std::string &name) {
	if (name.length() > 0) {
		name[0] = toupper(name[0]);
		for (size_t i = 1; i < name.length(); i++) {
			name[i] = tolower(name[i]);
		}
	}
}

void print(const std::string &str) {
	std::cout << str << " ";
}

int main() {
	{
		std::cout << "Test 1: Array de enteros. Imprimimos el doble." << std::endl;
		int numbers[10] = {
			1, 2, 3, 4, 5, 6, 7, 8, 9, 10
		};
		iter<int>(numbers, 10, printDouble);
		std::cout << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Test 2: Array de strings. Normalizamos los nombres y los imprimimos." << std::endl;
		std::string names[5] = {
			"aLeX", "juAnAn", "anDRes", "jOSE", "VICTOR"
		};
		iter(names, 5, capitalize);
		iter(names, 5, print);
	}
}