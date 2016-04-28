/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 13:01:22 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 20:34:19 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

int main(void)
{
	srand(time(0));
	CentralBureaucracy cb;

	int i = 0;

	try
	{		
		while (i < 20)
		{
			std::stringstream ss;
			std::string	name;
			ss << i;
			ss >> name;
			name = "Bob" + name;
			cb.feed(new Bureaucrat(name, rand() % 150));
			i++;
		}
		cb.queueUp("Bender");
		cb.queueUp("Remy");
		cb.queueUp("Zaz");
		cb.queueUp("Pirate");
		cb.queueUp("Den");
		std::cout << std::endl;
		cb.doBureaucracy();
	}
	catch  (std::exception & e)
	{	
		std::cout << e.what() << std::endl;
	}
	return 0;
}
