#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other): AForm(other) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
  if (this == &other) return (*this);
  AForm::operator=(other);
  return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  AForm::execute(executor);
  std::cout << this->name << " has been pardoned by Zafod Beeblebrox" << std::endl;
}