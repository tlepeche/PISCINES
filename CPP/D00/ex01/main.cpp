/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 13:51:33 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/15 18:19:24 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "phone.h"

void	choose(Contact *user)
{
	int		choose;
	std::string	buff;

	std::cout << "Choose contact ";
	std::getline (std::cin, buff);
	choose = buff[0] - 48;
	if (0 <= choose && choose < Contact::nbCont)
	{
		std::cout << "First Name: "			<< user[choose].getFname() << std::endl;
		std::cout << "Last Name: "			<< user[choose].getLname() << std::endl;
		std::cout << "Nickname: "			<< user[choose].getNick() << std::endl;
		std::cout << "Login: "				<< user[choose].getLog() << std::endl;
		std::cout << "Mail adress: "		<< user[choose].getMail() << std::endl;
		std::cout << "E-mail: "				<< user[choose].getEmail() << std::endl;
		std::cout << "Phone number: "		<< user[choose].getPhone() << std::endl;
		std::cout << "Birthday: "			<< user[choose].getBirth() << std::endl;
		std::cout << "Meal: "				<< user[choose].getMeal() << std::endl;
		std::cout << "Underwear color: "	<< user[choose].getPant() << std::endl;
		std::cout << "Darkest secret: "		<< user[choose].getSecr() << std::endl;
	}
	else
		std::cout << "Contact doesn't exist" << std::endl;
}

void	search(Contact *user)
{
	int	i;

	i = 1;
	if (Contact::nbCont != 0)
	{
		while (i < Contact::nbCont)
		{
			std::cout << std::setw(10) << i << "|";
			if (user[i].getFname().size() > 10)
				std::cout << std::string (user[i].getFname(), 0, 9) << ".";
			else
			{
				std::cout << std::setw(10);
				std::cout << user[i].getFname();
			}
			std::cout << "|";
			if (user[i].getLname().size() > 10)
				std::cout << std::string (user[i].getLname(),0 , 9) << ".";
			else
			{
				std::cout << std::setw(10);
				std::cout << user[i].getLname();
			}
			std::cout << "|";
			if (user[i].getNick().size() > 10)
				std::cout << std::string (user[i].getNick(),0 , 9) << ".";
			else
			{
				std::cout << std::setw(10);
				std::cout << user[i].getNick();
			}
			std::cout << "|";
			i++;
			std::cout << std::endl;
		}
		choose(user);
	}
}

int main(void)
{
	std::string	buff;
	Contact	user[8];

	while (42)
	{
		std::cout << "What do you want ? ";
		std::getline (std::cin, buff);
		if (!std::cin.fail())
		{
			if (buff == "ADD")
			{
				if (Contact::nbCont < 9)
					user[Contact::nbCont].init();
				else
					std::cout << "Already reach max contact" << std::endl;
			}
			else if (buff == "SEARCH")
				search(user);
			else if (buff == "EXIT")
				exit(0);
			else
				std::cout << "Invalid Command" << std::endl;
		}
		else
			exit(0);
		std::cout << std::endl;
	}
	return 0;
}
