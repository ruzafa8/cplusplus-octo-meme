#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &other) {
  *this = other;
}

Intern::~Intern() {}

Intern Intern::operator=(Intern const &other) {
  if (this != &other) {}
  return (*this);
}


AForm *Intern::makePresidentialPardonForm(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreationForm(std::string target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
  AForm *(*complaintPtr[3])(std::string) = {
    &Intern::makePresidentialPardonForm, &Intern::makeRobotomyRequestForm, &Intern::makeShrubberyCreationForm
  };
  std::string matchString[3] = { "presidential", "robotomy", "shrubbery" };
  std::stringstream ss(formName);
  std::string token;

  while (ss >> token) {
    for (size_t i = 0; i < matchString->length(); i++) {
      if (token == matchString[i])
        return (complaintPtr[i])(target);
    }
  }
  throw FormNotFoundException();
}
