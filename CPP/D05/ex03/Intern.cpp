/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:36:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 18:12:30 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern() {}

Intern::Intern(Intern & src)  {(void)src;}

Intern::~Intern() {}

Intern &	Intern::operator=(Intern const & rhs) {
	(void)rhs;
	return *this;
}

/// FUNCTIONS ///
Form	*Intern::makeForm(std::string fName, std::string target) {
	Form	*NForm;

	if (fName == "robotomy request")
	{
		NForm = new RobotomyRequestForm(target);
		std::cout << "Intern creates " << NForm->getName() << std::endl;
		return NForm;
	}
	else if (fName == "shrubbery creation")
	{
		NForm = new ShrubberyCreationForm(target);
		std::cout << "Intern creates " << NForm->getName() << std::endl;
		return NForm;
	}
	else if (fName == "presidential pardon")
	{
		NForm = new PresidentialPardonForm(target);
		std::cout << "Intern creates " << NForm->getName() << std::endl;
		return NForm;
	}
	else
		throw Intern::UnknownFormException();
}
