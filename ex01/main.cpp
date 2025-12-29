/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:45:40 by fmoulin           #+#    #+#             */
/*   Updated: 2025/12/29 17:40:13 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	instance;
	std::string	line;

	while (1)
	{
		std::cout << "Please enter 'ADD', 'SEARCH' or 'EXIT': ";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return (1);
		}
		while (line != "ADD" && line != "SEARCH" && line != "EXIT")
		{
			std::cout << "Please enter 'ADD', 'SEARCH' or 'EXIT': ";
			if (!std::getline(std::cin, line))
			{
				std::cout << std::endl;
				return (1);
			}
		}
		if (line == "ADD")
			instance.add();
		else if (line == "SEARCH")
			instance.search();
		else if (line == "EXIT")
		{
			std::cout << std::endl;
			return (1);
		}
	}
	return (0);
}
