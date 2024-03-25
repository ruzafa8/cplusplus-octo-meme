#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		const std::string name;
		bool sign;
		const int gradeToSign;
		const int gradeToExecute;
	

	public:

		AForm();
		AForm(const AForm &other);
		AForm(const std::string name, int gradeToSign, int gradeToExecute);
		AForm &operator=(const AForm &other);
		virtual ~AForm();


		const std::string getName() const;
		bool isSign() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat const &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const;

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

		class FormNotSignedException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Form is not signed";
				}
		};
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif