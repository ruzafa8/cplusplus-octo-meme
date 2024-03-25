#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &other) { *this = other; }

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	return (*this);
}

int Bureaucrat::getGrade() const { return grade; }

std::string Bureaucrat::getName() const { return name; }

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooLowException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooHighException();
	grade++;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}

void Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
		std::cout << *this << ". Signed ." << form << std::endl;
	} catch (std::exception &e)
	{
		std::cout << *this << ". Couldn't sign " << form << " because " << e.what() << ".";
	}
}
