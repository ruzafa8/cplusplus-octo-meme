#include "Bureaucrat.hpp"

int main() {
	{
		std::cout << "[TEST] Create valid Bureacrats:" << std::endl;
		Bureaucrat b("Alex", 42);
		Bureaucrat c("Andres", 2);

		std::cout << b << std::endl << c << std::endl;
	}
	{
		std::cout << std::endl << "[Test] Create invalid Bureaucrats:" << std::endl;
		try {
			Bureaucrat b("Hantonia", 0);
			Bureaucrat c("This bureaucrat should not be created!", 42);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "[Test] Invalid Bureaucrats, exceptions:" << std::endl;
		try {
			Bureaucrat b("Hantonia", 0);
			Bureaucrat c("This bureaucrat should not be created!", 42);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "When I am at this line, I know the exception was due to the value was too high";
		}	
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "When I am at this line, I know the exception was due to the value was too low";
		}
	}
	{
		std::cout << std::endl << "[Test] Increase Bureucrats grade:" << std::endl;
		try {
			Bureaucrat b("Juanan", 10);
			std::cout << b << std::endl;
			b.incrementGrade();
			b.incrementGrade();
			std::cout << b << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}	
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "[Test] Increase Bureucrats grade till error:" << std::endl;
		try {
			Bureaucrat b("javi", 5);
			std::cout << "Initial bureaucrat: " << b << std::endl;
			while (true)
			{
				b.incrementGrade();
				std::cout << "Incremented grade: " << b << std::endl;
			}
		} 
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}	
	}
	{
		std::cout << std::endl << "[Test] Increase and decreaseBureucrats grade till error:" << std::endl;
		try {
			Bureaucrat b("el de los peces", 5);
			Bureaucrat c("el de la tierra", 148);
			std::cout << "Initial bureaucrat: " << b << std::endl;
			std::cout << "Initial bureaucrat: " << c << std::endl;
			while (true)
			{
				b.incrementGrade();
				std::cout << "Incremented grade: " << b << std::endl;
				c.decrementGrade();
				std::cout << "Decremented grade: " << c << std::endl;
			}
		} 
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}	
	}
}