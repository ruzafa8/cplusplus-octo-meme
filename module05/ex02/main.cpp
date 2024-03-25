#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void firmAndExecute(AForm &f, Bureaucrat &b) {
	b.signForm(f);
	b.executeForm(f);
}

AForm *getFormByString(std::string formKind, std::string target) {
	if (formKind == "ShrubberyCreationForm") {
		return new ShrubberyCreationForm(target);
	} else if (formKind == "PresidentialPardonForm") {
		return new PresidentialPardonForm(target);
	} else if (formKind == "RobotomyRequestForm") {
		return new RobotomyRequestForm(target);
	} else {
		std::cout << "Invalid form kind" << std::endl;
		return NULL;
	}
}

/**
 * Todos los tests funcionan igual, se crea un burócrata con un grado y un tipo de formulario que se intenta firmar y ejecutar.
 * 
 * Para generalizar los tests, se crea una función que recibe el grado del burócrata y el tipo de formulario.
 * A partir del bureaucratKind se instancia un formulario y se intenta firmar y ejecutar.
 */
void testOneBureaucrat(int bureaucratGrade, std::string bureaucratKind) {
	Bureaucrat b("Burócrata", bureaucratGrade);
	std::cout << b << std::endl;
	AForm *f = getFormByString(bureaucratKind, "home");
	firmAndExecute(*f, b);
	delete f;
}

void testTwoBureaucrats(int bGrade1, int bGrade2, std::string bureaucratKind) {
	Bureaucrat b1("Burócrata 1", bGrade1);
	Bureaucrat b2("Burócrata 2", bGrade2);
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	AForm *f = getFormByString(bureaucratKind, "home");
	b1.signForm(*f);
	b2.executeForm(*f);
	delete f;
}

int main() {
	std::cout << "--- ShrubberyCreationForm tests--- " << std::endl;
	{
		std::cout << "Test 1: Bureaucrat signs and execute ShrubberyCreationForm" << std::endl;
		testOneBureaucrat(1, "ShrubberyCreationForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 2: Bureaucrat can't sign ShrubberyCreationForm" << std::endl;
		testOneBureaucrat(150, "ShrubberyCreationForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 3: Bureaucrat can't execute ShrubberyCreationForm" << std::endl;
		testOneBureaucrat(142, "ShrubberyCreationForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 4: One Bureaucrat signs and another execute ShrubberyCreationForm" << std::endl;
		testTwoBureaucrats(1, 1, "ShrubberyCreationForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 5: Bureaucrat signs and another can't execute ShrubberyCreationForm" << std::endl;
		testTwoBureaucrats(1, 150, "ShrubberyCreationForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 6: Bureaucrat can't signs and another could execute ShrubberyCreationForm" << std::endl;
		testTwoBureaucrats(146, 3, "ShrubberyCreationForm");
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "--- PresidentialPardonForm tests--- " << std::endl;
	{
		std::cout << "Test 1: Bureaucrat signs and execute PresidentialPardonForm" << std::endl;
		testOneBureaucrat(1, "PresidentialPardonForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 2: Bureaucrat can't sign PresidentialPardonForm" << std::endl;
		testOneBureaucrat(150, "PresidentialPardonForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 3: Bureaucrat can't execute PresidentialPardonForm" << std::endl;
		testOneBureaucrat(25, "PresidentialPardonForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 4: One Bureaucrat signs and another execute PresidentialPardonForm" << std::endl;
		testTwoBureaucrats(1, 1, "PresidentialPardonForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 5: Bureaucrat signs and another can't execute PresidentialPardonForm" << std::endl;
		testTwoBureaucrats(1, 42, "PresidentialPardonForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 6: Bureaucrat can't signs and another could execute PresidentialPardonForm" << std::endl;
		testTwoBureaucrats(25, 6, "PresidentialPardonForm");
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "--- RobotomyRequestForm tests--- " << std::endl;
	{
		std::cout << "Test 1: Bureaucrat signs and execute RobotomyRequestForm" << std::endl;
		testOneBureaucrat(20, "RobotomyRequestForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 2: Bureaucrat can't sign RobotomyRequestForm" << std::endl;
		testOneBureaucrat(100, "RobotomyRequestForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 3: Bureaucrat can't execute RobotomyRequestForm" << std::endl;
		testOneBureaucrat(60, "RobotomyRequestForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 4: One Bureaucrat signs and another execute RobotomyRequestForm" << std::endl;
		testTwoBureaucrats(13, 20, "RobotomyRequestForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 5: Bureaucrat signs and another can't execute RobotomyRequestForm" << std::endl;
		testTwoBureaucrats(1, 150, "RobotomyRequestForm");
		std::cout << std::endl;
	} {
		std::cout << "Test 6: Bureaucrat can't signs and another could execute RobotomyRequestForm" << std::endl;
		testTwoBureaucrats(73, 3, "RobotomyRequestForm");
		std::cout << std::endl;
	}
	return 0;
}
