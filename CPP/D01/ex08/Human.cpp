/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 18:27:16 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 20:31:54 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

void	Human::meleeAttack(std::string const & target) {
	std::cout << "Do a melee attack on " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target) {
	std::cout << "Do a ranged attack on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target) {
	std::cout << "Do an initimidating shout on " << target << std::endl;
}

typedef void	(Human::*f)(std::string const &);

void	Human::action(std::string const & action_name, std::string const & target) {
	struct s_choice
	{
		std::string	action;
		f ptr;
	};

	s_choice	list[3];

	list[0].action = "melee";
	list[0].ptr = &Human::meleeAttack;
	list[1].action = "ranged";
	list[1].ptr = &Human::rangedAttack;
	list[2].action = "intimidate";
	list[2].ptr = &Human::intimidatingShout;

	int i = 0;
	while (i < 3)
	{
		if (action_name == list[i].action)
		{
			f selected = list[i].ptr;
			(this->*selected)(target);
		}
		i++;
	}
}
