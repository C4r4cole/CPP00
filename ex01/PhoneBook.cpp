/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:43:07 by fmoulin           #+#    #+#             */
/*   Updated: 2025/12/29 18:35:52 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _nextIndex(0), _count(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

static bool	isOnlySpaces(const std::string& s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (false);
	}
	return (true);
}

int PhoneBook::add()
{
	std::string	contact_fields[5];
	std::string prompt[5] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};
	int			first;
		
	for (int i = 0; i < 5; i++)
	{
		first = 1;
		while (contact_fields[i].empty() || isOnlySpaces(contact_fields[i]))
		{
			if (first == 0)
				std::cout << "Field cannot be empty\n";
			std::cout << prompt[i];
			if (!std::getline(std::cin, contact_fields[i]))
			{
				std::cout << std::endl;
				return (1);
			}
			first = 0;
		}
	}
	this->_contacts[this->_nextIndex].setContact(contact_fields[0], contact_fields[1], contact_fields[2], contact_fields[3], contact_fields[4]);
	this->_nextIndex = (this->_nextIndex + 1) % 8;
	if (this->_count < 8)
		this->_count = this->_count + 1;
	return (0);
}

static std::string	format10(const std::string& s)
{
	if (s.length() > 10)
		return (s.substr(0, 9) + ".");
	return (s);
}

static bool	isNumeric(const std::string& s)
{
	if (s.empty())
		return (false);
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return (false);
	}
	return (true);
}

int PhoneBook::search() const
{
	std::string	line;
	int			index;
	if (this->_count == 0)
	{
		std::cout << "The phonebook is empty !\n";
		return (1);
	}
	for (int i = 0; i < this->_count; i++)
	{
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;

		first_name = this->_contacts[i].getFirstName();
		last_name = this->_contacts[i].getLastName();
		nickname = this->_contacts[i].getNickname();
		first_name = format10(first_name);
		last_name = format10(last_name);
		nickname = format10(nickname);
		
		std::cout << i + 1 << " | " << first_name << " | " << last_name << " | " << nickname << std::endl; 
	}
	std::cout << "What contact do you want to see? (fill in its index): ";
	if (!std::getline(std::cin, line))
	{
		std::cout << std::endl;
		return (1);
	}
	while (!isNumeric(line))
	{
		std::cout << "Please enter a numeric value: ";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return (1);
		}
	}
	index = std::atoi(line.c_str());
	while (index < 1 || index > this->_count)
	{
		std::cout << "Invalid index ! Please enter a valid index: ";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return (1);
		}
		while (!isNumeric(line))
		{
			std::cout << "Please enter a numeric value: ";
			if (!std::getline(std::cin, line))
			{
				std::cout << std::endl;
				return (1);
			}
		}
		index = std::atoi(line.c_str());
	}
	this->printContact(index);
	return (0);
}

void PhoneBook::printContact(int index) const
{
	int	idx;
	
	idx = index - 1;
	std::cout << this->_contacts[idx].getFirstName() << std::endl;
	std::cout << this->_contacts[idx].getLastName() << std::endl;
	std::cout << this->_contacts[idx].getNickname() << std::endl;
	std::cout << this->_contacts[idx].getPhoneNumber() << std::endl;
	std::cout << this->_contacts[idx].getDarkestSecret() << std::endl;
}
