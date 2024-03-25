#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void firmAndExecute(AForm &f, Bureaucrat &b) {
	b.signForm(f);
	b.executeForm(f);
}

/**
 * Sustituimos la función que nos inventamos en el otro tests para generar Forms por la de Intern.
*/
void testOneBureaucrat(int bureaucratGrade, std::string bureaucratKind) {
	try {
		Bureaucrat b("Burócrata", bureaucratGrade);
		std::cout << b << std::endl;
		Intern i;
		AForm *f = i.makeForm(bureaucratKind, "home");
		firmAndExecute(*f, b);
		delete f;
	} catch (std::exception &e) {
		std::cerr << e.what();
	}
}

void testTwoBureaucrats(int bGrade1, int bGrade2, std::string bureaucratKind) {
	try { 
		Bureaucrat b1("Burócrata 1", bGrade1);
		Bureaucrat b2("Burócrata 2", bGrade2);
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		Intern i;
		AForm *f = i.makeForm(bureaucratKind, "home");
		b1.signForm(*f);
		b2.executeForm(*f);
		delete f;
	} catch (std::exception &e) {
		std::cerr << e.what();
	} 
}

int main() {
	std::cout << "--- ShrubberyCreationForm tests--- " << std::endl;
	{
		std::cout << "Test 1: Bureaucrat signs and execute ShrubberyCreationForm" << std::endl;
		testOneBureaucrat(1, "shrubbery");
		std::cout << std::endl;
	} {
		std::cout << "Test 2: Bureaucrat can't sign ShrubberyCreationForm" << std::endl;
		testOneBureaucrat(150, "shrubbery request");
		std::cout << std::endl;
	} {
		std::cout << "Test 3: Bureaucrat can't execute ShrubberyCreationForm" << std::endl;
		testOneBureaucrat(142, "shrubbery creation form");
		std::cout << std::endl;
	} {
		std::cout << "Test 4: One Bureaucrat signs and another execute ShrubberyCreationForm" << std::endl;
		testTwoBureaucrats(1, 1, "creation form shrubbery");
		std::cout << std::endl;
	} {
		std::cout << "Test 5: Bureaucrat signs and another can't execute ShrubberyCreationForm" << std::endl;
		testTwoBureaucrats(1, 150, "creation form shrubbery request");
		std::cout << std::endl;
	} {
		std::cout << "Test 6: Bureaucrat can't signs and another could execute ShrubberyCreationForm" << std::endl;
		testTwoBureaucrats(146, 3, "shrubbery request creation form");
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "--- PresidentialPardonForm tests--- " << std::endl;
	{
		std::cout << "Test 1: Bureaucrat signs and execute PresidentialPardonForm" << std::endl;
		testOneBureaucrat(1, "presidential pardon form");
		std::cout << std::endl;
	} {
		std::cout << "Test 2: Bureaucrat can't sign PresidentialPardonForm" << std::endl;
		testOneBureaucrat(150, "presidential");
		std::cout << std::endl;
	} {
		std::cout << "Test 3: Bureaucrat can't execute PresidentialPardonForm" << std::endl;
		testOneBureaucrat(25, "presidential form");
		std::cout << std::endl;
	} {
		std::cout << "Test 4: One Bureaucrat signs and another execute PresidentialPardonForm" << std::endl;
		testTwoBureaucrats(1, 1, "presidential pardon");
		std::cout << std::endl;
	} {
		std::cout << "Test 5: Bureaucrat signs and another can't execute PresidentialPardonForm" << std::endl;
		testTwoBureaucrats(1, 42, "presidential form");
		std::cout << std::endl;
	} {
		std::cout << "Test 6: Bureaucrat can't signs and another could execute PresidentialPardonForm" << std::endl;
		testTwoBureaucrats(25, 6, "presidential");
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "--- RobotomyRequestForm tests--- " << std::endl;
	{
		std::cout << "Test 1: Bureaucrat signs and execute RobotomyRequestForm" << std::endl;
		testOneBureaucrat(20, "robotomy form");
		std::cout << std::endl;
	} {
		std::cout << "Test 2: Bureaucrat can't sign RobotomyRequestForm" << std::endl;
		testOneBureaucrat(100, "robotomy request form");
		std::cout << std::endl;
	} {
		std::cout << "Test 3: Bureaucrat can't execute RobotomyRequestForm" << std::endl;
		testOneBureaucrat(60, "request form robotomy");
		std::cout << std::endl;
	} {
		std::cout << "Test 4: One Bureaucrat signs and another execute RobotomyRequestForm" << std::endl;
		testTwoBureaucrats(13, 20, "robotomy request");
		std::cout << std::endl;
	} {
		std::cout << "Test 5: Bureaucrat signs and another can't execute RobotomyRequestForm" << std::endl;
		testTwoBureaucrats(1, 150, "request robotomy");
		std::cout << std::endl;
	} {
		std::cout << "Test 6: Bureaucrat can't signs and another could execute RobotomyRequestForm" << std::endl;
		testTwoBureaucrats(73, 3, "robotomy");
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "--- Tests Intern ---" << std::endl;
	{
		std::cout << "Test 1: INTERN should fail" << std::endl;
		Intern i;
		testOneBureaucrat(1, "baja cliente");
	}
	{
		std::cout << std::endl << "Test 2: Intern returns the first occurrence" << std::endl;
		Intern i;
		testOneBureaucrat(1, "robotomy presidential");
	}
	return 0;
}
