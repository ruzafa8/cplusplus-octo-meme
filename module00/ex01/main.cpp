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
		std::cout << "Insert a command (ADD/SEARCH/EXIT): ";
		std::getline(std::cin, command);

		for(int i = 0; i < (int) command.length(); i++)
			command[i] = (char) toupper(command[i]);
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