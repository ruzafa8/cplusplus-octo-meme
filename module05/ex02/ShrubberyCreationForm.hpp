#ifndef SHRUBBERY_CREATION_FORM
# define SHRUBBERY_CREATION_FORM

# include "AForm.hpp"

class ShrubberyCreationForm: AForm {
	private:
		ShrubberyCreationForm();
		void createFileAndPrintTree();
	
	public:
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(std::string target);
};

#endif