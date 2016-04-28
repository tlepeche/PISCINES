/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 13:01:22 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 17:45:08 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat *Bob = new Bureaucrat("Bob", 2);
	Bureaucrat *Bob2 = new Bureaucrat("John", 142);
	Form *A = new ShrubberyCreationForm("test");
	Form *B = new PresidentialPardonForm("Obama");
	Form *C = new RobotomyRequestForm("Remy");
	srand(time(0));

	try
	{

		Bob->signForm(*A);
		Bob->signForm(*B);
		Bob->signForm(*C);
		Bob->executeForm(*A);
		Bob->executeForm(*B);
		Bob->executeForm(*C);
		Bob->executeForm(*C);
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bob2->executeForm(*A);

	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bob2->executeForm(*B);
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bob2->executeForm(*C);
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
