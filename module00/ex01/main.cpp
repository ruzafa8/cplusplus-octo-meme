#include <iostream>
#include <string>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int	main()
{
	PhoneBook	phone_book;
	std::string	command;

	while (true)
	{
		std::getline(std::cin, command);
		if (command == "ADD")
			phone_book.add();
		else if (command == "SEARCH")
			phone_book.search();
		else if (command == "EXIT")
			phone_book.exit();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}