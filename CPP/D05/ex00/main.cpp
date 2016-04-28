/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 13:01:22 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 14:15:30 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat *Bob = new Bureaucrat("Bob", 43);

		std::cout << *Bob << std::endl;
		Bob->promote();
		Bob->promote();
		Bob->retrograde();
		std::cout << *Bob << std::endl;
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat *Pdt= new Bureaucrat("Pdt", 1);

		std::cout << *Pdt << std::endl;
		Pdt->promote();
		std::cout << *Pdt << std::endl;
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat *Stagiaire= new Bureaucrat("Stagiaire", 150);

		std::cout << *Stagiaire << std::endl;
		Stagiaire->retrograde();
		std::cout << *Stagiaire << std::endl;
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat *Cheat = new Bureaucrat("TEST", 0);
		(void)Cheat;
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat *Test = new Bureaucrat("TEST2", 156);
		(void)Test;
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
