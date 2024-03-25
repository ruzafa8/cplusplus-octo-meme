#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <cstdlib>

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
  private:
    RobotomyRequestForm();
  
  public:
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    ~RobotomyRequestForm();

    RobotomyRequestForm(std::string target);
		virtual void execute(Bureaucrat const &executor) const;
};

#endif