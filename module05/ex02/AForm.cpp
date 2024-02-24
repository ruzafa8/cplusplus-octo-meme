#include "AForm.hpp"

AForm::AForm(): gradeToSign(1), gradeToExecute(1) {}

AForm::AForm(const AForm &other)
	: name(other.name), sign(other.sign), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
	: name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm &AForm::operator=(AForm const &other) {
	if (this != &other) {
		this->sign = other.sign;
	}
	return (*this);
}

const std::string AForm::getName() const { return name; }

bool AForm::isSign() const { return sign; }

int AForm::getGradeToSign() const { return gradeToSign; }

int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	sign = true;
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs) {
	o << "[Form " << rhs.getName() << ": min grade to sign: " << rhs.getGradeToSign()
		<< ". min grade to exec: " << rhs.getGradeToExecute() << ". Signed?: " << (rhs.isSign() ? "Yes" : "No") << "]";
	return o;
}