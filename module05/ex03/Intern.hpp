#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <sstream>

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
  private:
    static AForm *makePresidentialPardonForm(std::string target);
    static AForm *makeRobotomyRequestForm(std::string target);
    static AForm *makeShrubberyCreationForm(std::string target);

  public:
    Intern();
    Intern(Intern const &other);
    ~Intern();
    Intern operator=(Intern const &other);
  
    AForm *makeForm(std::string form, std::string target);

    class FormNotFoundException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Couldn't find the specified form";
				}
		};
};

#endif