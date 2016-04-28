/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 13:01:22 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 18:56:26 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main(void)
{
	Intern		I;
	Bureaucrat *Bob = new Bureaucrat("Bob", 55);
	Bureaucrat *Bob2 = new Bureaucrat("Bob2", 2);
	OfficeBlock ob;
	srand(time(0));


	try
	{		ob.doBureaucracy("presidential pardon", "Nintendo");	}
	catch  (std::exception & e)
	{		std::cout << e.what() << std::endl;	}

	std::cout << std::endl;

	ob.setIntern(I);
	try
	{		ob.doBureaucracy("presidential pardon", "Nintendo");	}
	catch  (std::exception & e)
	{		std::cout << e.what() << std::endl;	}

	std::cout << std::endl;

	ob.setSigner(Bob);
	try
	{		ob.doBureaucracy("presidential pardon", "Nintendo");	}
	catch  (std::exception & e)
	{		std::cout << e.what() << std::endl;	}

	std::cout << std::endl;

	ob.setExecutor(Bob2);
	try
	{		ob.doBureaucracy("presidential pardon", "Nintendo");	}
	catch  (std::exception & e)
	{		std::cout << e.what() << std::endl;	}

	std::cout << std::endl;
	
	Bureaucrat *Bob3 = new Bureaucrat("Bob3", 10);
	ob.setSigner(Bob3);
	try
	{		ob.doBureaucracy("presidential pardon", "Nintendo");	}
	catch  (std::exception & e)
	{		std::cout << e.what() << std::endl;	}

	return 0;
}
