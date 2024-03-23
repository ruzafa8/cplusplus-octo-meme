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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);
	std::string filename;
	filename = this->name + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open()) {
        std::cout << "Error: could not open " <<  filename << " file" << std::endl;
	} else {
		file << "ASCII trees";
	}
	file.close();
}
