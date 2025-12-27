/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:58:53 by fmoulin           #+#    #+#             */
/*   Updated: 2025/12/28 00:11:20 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"

Contact::Contact(void)
{	
}

void	Contact::setContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	this->_first_name = fn;
	this->_last_name = ln;
	this->_nickname = nn;
	this->_phone_number = pn;
	this->_darkest_secret = ds;	
}

std::string	Contact::getFirstName(void) const
{
	return (this->_first_name);
}

std::string	Contact::getLastName(void) const
{
	return (this->_last_name);
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_phone_number);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkest_secret);
}
