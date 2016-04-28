/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 14:00:02 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 14:47:33 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieHorde.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde(int N) {
	std::cout << "Horde constructed" << std::endl;
	this->_Horde = new Zombie[N];
	this->_size = N;
	int i = 0;	
	while (i < N)
	{
		std::string name = "zombie_";
		name += 65 + (std::rand() % 26);
		this->_Horde[i].init(name, "standard");
		i++;
	}
}

ZombieHorde::~ZombieHorde(void) {
	delete [] this->_Horde;
	std::cout << "Horde destroyed" << std::endl;
}

void ZombieHorde::announce(void) const{
	int i = 0;
	while(i < this->_size)
	{
		this->_Horde[i].announce();
		i++;
	}
}
