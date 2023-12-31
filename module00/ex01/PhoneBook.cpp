#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook()
{
	nextContactIndex = 0;
	numContacts = 0;
}

void PhoneBook::add()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	do {
		std::cout << "First name: ";
		std::getline(std::cin, firstName);
	} while (firstName.length() == 0);

	do {
		std::cout << "Last name: ";
		std::getline(std::cin, lastName);
	} while (lastName.length() == 0);

	do {
		std::cout << "Nickname: ";
		std::getline(std::cin, nickname);
	} while (nickname.length() == 0);

	do {
		std::cout << "Phone number: ";
		std::getline(std::cin, phoneNumber);
	} while (phoneNumber.length() == 0);

	do {
		std::cout << "Darkest secret: ";
		std::getline(std::cin, darkestSecret);
	} while (darkestSecret.length() == 0);

	contacts[nextContactIndex].setFirstName(firstName);
	contacts[nextContactIndex].setLastName(lastName);
	contacts[nextContactIndex].setNickname(nickname);
	contacts[nextContactIndex].setPhoneNumber(phoneNumber);
	contacts[nextContactIndex].setDarkestSecret(darkestSecret);
	nextContactIndex++;
	if (nextContactIndex > 7)
		nextContactIndex = 0;
	if (numContacts < 8)
		numContacts++;
}

static std::string truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::search()
{
	int			index;
	std::string	strIndex;

	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i < numContacts; i++)
	{
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
			<< std::setw(10) << truncate(contacts[i].getLastName()) << "|"
			<< std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
	}
	std::cout << "Indice: ";
	std::getline(std::cin, strIndex);
	// Verify if strIndex is a number
	if (strIndex.length() == 0)
	{
		std::cout << "It's not a number" << std::endl;
		return ;
	}
	index = std::atoi(strIndex.c_str());
	if (index < 0 || index > 7 || index >= numContacts)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	for (int i = 0; i < (int) strIndex.length(); i++)
	{
		if (!std::isdigit(strIndex[i]))
		{
			std::cout << "It's not a number" << std::endl;
			return ;
		}
	}
	std::cout << "index: " << index << std::endl;
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::exit()
{
	std::exit(0);
}
