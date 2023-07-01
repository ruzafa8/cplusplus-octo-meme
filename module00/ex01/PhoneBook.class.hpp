#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.class.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		nextContactIndex;
		int		numContacts;

	public:

		PhoneBook();

		void add();

		void search();

		void exit();
};

#endif
