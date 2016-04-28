/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 12:26:48 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 13:42:22 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("PowerFist", 8, 50) {}

PowerFist::PowerFist(PowerFist & src) {
	*this = src;
	std::cout << "Weapon copied." << std::endl;
}

PowerFist &	PowerFist::operator=(PowerFist const & rhs) {
	this->_Name = rhs.getName();
	this->_AP = rhs.getAPCost();
	this->_Dmg =rhs.getDamage();
	return *this;
}

/// FUNCTIONS ///
void	PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
