/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 10:47:10 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/15 13:55:47 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace	answer
{
	char	up(char c) { return toupper(c); }
	const char	*empty(void) { return ("* LOUD AND UNBEARABLE FEEDBACK NOISE *"); }
}

int main(int ac, char **av)
{
	int i = 1;
	int j;

	(void)ac;
	if (av[i])
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				std::cout << answer::up(av[i][j]);
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << answer::empty() << std::endl;
	return 0;
}
