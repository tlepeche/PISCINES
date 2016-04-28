/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 11:49:12 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 12:26:16 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieEvent.hpp"
#include "Zombie.hpp"

ZombieEvent::ZombieEvent(void) {
	this->_type = "minion";
	std::cout << "Event Created" << std::endl;
}

ZombieEvent::~ZombieEvent(void) {
	std::cout << "Event Destroyed" << std::endl;
}

void ZombieEvent::setZombieType(std::string type) {
	this->_type = type;
	return ;
}

Zombie*	ZombieEvent::newZombie(std::string name) {
	return (new Zombie(name, this->_type));
}

void	ZombieEvent::randomChump(void) {
	std::string	tab[3];

	tab[0] = "Pierre";
	tab[1] = "Paul";
	tab[2] = "Jack";
	
	std::srand(time(NULL));
	Zombie ZZ = Zombie(tab[std::rand() % 3], this->_type);
	ZZ.announce();
}

