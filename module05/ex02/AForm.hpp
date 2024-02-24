#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		AForm();
		const std::string name;
		bool sign;
		const int gradeToSign;
		const int gradeToExecute;
	

	public:

		AForm(const AForm &other);
		AForm(const std::string name, int gradeToSign, int gradeToExecute);
		AForm &operator=(const AForm &other);
		virtual ~AForm();


		const std::string getName() const;
		bool isSign() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat const &bureaucrat);

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

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif