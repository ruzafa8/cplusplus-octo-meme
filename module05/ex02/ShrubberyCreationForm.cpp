#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm() {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other): AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	if (this != &other) {
		this->sign = other.sign;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137) {}

void ShrubberyCreationForm::createFileAndPrintTree() {
	std::string filename;
	filename = this->name + "_shrubbery";
	std::ofstream file(filename);
	if (!file.is_open()) {
        std::cout << "Error: could not open " <<  filename << " file" << std::endl;
	} else {
		file << "ASCII trees";
	}
	file.close();
}
