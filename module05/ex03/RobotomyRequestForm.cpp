#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm() {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other): AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
  if (this != &other) {
    this->sign = other.sign;
  }
  return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 72, 45) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  AForm::execute(executor);
  std::cout << " *** DRILLING NOISE ***" << std::endl;
  srand((unsigned int)time(NULL));
  int random = rand() % 2;
  if (random == 0) {
    std::cout << this->name << " has not been robotomized successfully" << std::endl;
  } else {
    std::cout << this->name << " has been robotomized successfully" << std::endl;
  }
}