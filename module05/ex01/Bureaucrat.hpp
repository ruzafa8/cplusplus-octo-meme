#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
		Bureaucrat();
		Bureaucrat(Bureaucrat const &other);

	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &other);

		int getGrade() const;
		std::string getName() const;
		void incrementGrade();
		void decrementGrade();

		void signForm(Form &form) const;

		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too high";
				}
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too low";
				}
		};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif