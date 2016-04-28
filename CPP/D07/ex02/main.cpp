/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 16:11:39 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/24 17:39:37 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TArray.hpp"

int	main(void)
{
	Array<int> tab(10);

	std::cout << "Array of int, size: " <<  tab.size()
		<<", content:" << std::endl;

	unsigned int i = 0;
	while (i < tab.size() + 2)
	{
		try
		{
			std::cout << i << ": " << tab[i];
			if (i < tab.size() - 1)
				std::cout << " ";
			std::cout << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		i++;
	}

	std::cout << std::endl;

	Array<char *> tab2(10);
	std::cout << "Array of char * tab2, size: " <<  tab2.size()
		<<", content:" << std::endl;

	i = 0;
	while (i < tab2.size() + 2)
	{
		try
		{
			std::cout << i << ": ";
			if (tab2[i] == NULL)
				std::cout << "NULL";
			else
				std::cout << tab2[i];
			if (i < tab2.size() - 1)
				std::cout << " ";
			std::cout << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		i++;
	}
	
	std::cout << std::endl;

	Array<char *> tab3(tab2);
	std::cout << "Array of char * tab3(tab2), size: " <<  tab3.size()
		<<", content:" << std::endl;
	i = 0;
	while (i < tab3.size() + 2)
	{
		try
		{
			std::cout << i << ": ";
			if (tab3[i] == NULL)
				std::cout << "NULL";
			else
				std::cout << tab3[i];
			if (i < tab3.size() - 1)
				std::cout << " ";
			std::cout << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		i++;
	}
	
	std::cout << std::endl;

	Array<char *> tab4 = tab2;
	std::cout << "Array of char * tab4 = tab2, size: " <<  tab4.size()
		<<", content:" << std::endl;

	i = 0;
	while (i < tab4.size() + 2)
	{
		try
		{
			std::cout << i << ": ";
			if (tab4[i] == NULL)
				std::cout << "NULL";
			else
				std::cout << tab4[i];
			if (i < tab4.size() - 1)
				std::cout << " ";
			std::cout << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		i++;
	}
	return 0;
}
