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

	std::cout << "First name: ";
	std::cin >> firstName;
	std::cout << "Last name: ";
	std::cin >> lastName;
	std::cout << "Nickname: ";
	std::cin >> nickname;
	std::cout << "Phone number: ";
	std::cin >> phoneNumber;
	std::cout << "Darkest secret: ";
	std::cin >> darkestSecret;
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

void PhoneBook::search()
{
	int			index;

	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i < numContacts; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << contacts[i].getFirstName() << "|";
		std::cout << std::setw(10) << contacts[i].getLastName() << "|";
		std::cout << std::setw(10) << contacts[i].getNickname() << std::endl;
	}
	std::cout << "Indice: ";
	std::cin >> index;
	std::cout << index << std::endl;
	if (index < 0 || index > 7)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::exit()
{
	(void) this->nextContactIndex;
}
