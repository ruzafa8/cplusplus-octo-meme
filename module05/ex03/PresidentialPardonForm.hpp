#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
  private:
    PresidentialPardonForm();
  
  public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const &other);
    ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
		virtual void execute(Bureaucrat const &executor) const;
};

#endif