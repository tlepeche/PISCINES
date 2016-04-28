/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 13:01:22 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 18:12:48 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern		I;
	Form *A;
	Form *B;
	Form *C;
	Form *D;
	Bureaucrat *Bob = new Bureaucrat("Bob", 2);
	srand(time(0));

	try
	{
		A = I.makeForm("robotomy request", "Pirate");
		B = I.makeForm("shrubbery creation", "tree");
		C = I.makeForm("presidential pardon", "monkeys");
		D = I.makeForm("formulaire B-14", "Boss");
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bob->signForm(*A);
		Bob->signForm(*B);
		Bob->signForm(*C);
		Bob->executeForm(*A);
		Bob->executeForm(*B);
		Bob->executeForm(*C);
	}
	catch  (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
