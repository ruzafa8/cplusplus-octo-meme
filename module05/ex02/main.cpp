#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	{
		Bureaucrat b("Bureaucrat", 1);
		std::cout << b << std::endl;
		AForm *f = new ShrubberyCreationForm("home");
		b.signForm(*f);
		b.executeForm(*f);
	}
	return 0;
}
