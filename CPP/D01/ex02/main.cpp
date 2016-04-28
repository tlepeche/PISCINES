/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 12:04:23 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 12:32:34 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieEvent.hpp"
#include "Zombie.hpp"


int main(void)
{
	ZombieEvent *bob = new ZombieEvent();
	Zombie		*Rick;

	bob->randomChump();
	bob->setZombieType("Hunter");
	Rick = bob->newZombie("Rick");
	Rick->announce();
	bob->randomChump();
	bob->setZombieType("Boomer");
	bob->randomChump();
	bob->setZombieType("touillette");
	Rick = bob->newZombie("Remy");
	Rick->announce();
	delete Rick;
	delete bob;
	return 0;
}
