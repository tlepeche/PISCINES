/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:40:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/23 17:27:57 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Converter C(av[1]);

		std::cout << "char: ";
		try
		{
			char c = C;
			std::cout << "'" << c << "'" << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << "int: ";
		try
		{
			int i = C;
			std::cout << i << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << "float: ";
		try
		{
			float f = C;
			std::cout << f;
			if (f == static_cast<int>(f))
				std::cout << ".0f" << std::endl;
			else
				std::cout << "f" << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << "double: ";
		try
		{
			double d = C;

			std::cout << d;
			if (d == static_cast<int>(d))
				std::cout << ".0" << std::endl;
			else
				std::cout << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage <value to convert>" << std::endl;
	return 0;
}
