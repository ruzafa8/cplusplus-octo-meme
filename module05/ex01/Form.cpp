#include "Form.hpp"

Form::Form(): gradeToSign(1), gradeToExecute(1) {}

Form::Form(const Form &other)
	: name(other.name), sign(other.sign), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

Form::Form(const std::string name, bool sign, int gradeToSign, int gradeToExecute)
	: name(name), sign(sign), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{}

Form::~Form() {}

Form &Form::operator=(Form const &other) {
	if (this != &other) {
		this->sign = other.sign;
	}
	return (*this);
}

const std::string Form::getName() const { return name; }

bool Form::isSign() const { return sign; }

int Form::getGradeToSign() const { return gradeToSign; }

int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	sign = true;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs) {
	o << "Form " << rhs.getName() << ": min grade to sign: " << rhs.getGradeToSign()
		<< ". min grade to exec: " << rhs.getGradeToExecute();
	return o;
}