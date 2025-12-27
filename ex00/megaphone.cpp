/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:10:04 by fmoulin           #+#    #+#             */
/*   Updated: 2025/12/27 17:59:54 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	is_lower_case(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	capital;
	
	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if (is_lower_case(argv[i][j]))
				{
					capital = argv[i][j] -= 32;
					std::cout << capital;
					j++;
				}
				else
				{
					std::cout << argv[i][j];
					j++;
				}
			}
			std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return (0);
}