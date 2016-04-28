/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 13:01:22 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 15:20:20 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat *Bob = new Bureaucrat("Bob", 43);
		Form *A = new Form("A", 50, 30);

		std::cout << *A << std::endl;
		Bob->signForm(*A);
		std::cout << *A << std::endl;
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat *Bob = new Bureaucrat("Bob", 43);
		Form *A = new Form("A", 40, 30);

		std::cout << *A << std::endl;
		Bob->signForm(*A);
		std::cout << *A << std::endl;
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat *Bob = new Bureaucrat("Bob", 43);
		Form *A = new Form("A", 50, 30);

		std::cout << *A << std::endl;
		Bob->signForm(*A);
		std::cout << *A << std::endl;
		Bob->signForm(*A);
		std::cout << *A << std::endl;
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
