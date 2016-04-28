/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 12:26:48 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 14:01:29 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("PlasmaRifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(PlasmaRifle & src) {
	*this = src;
	std::cout << "Weapon copied." << std::endl;
}

PlasmaRifle &	PlasmaRifle::operator=(PlasmaRifle const & rhs) {
	this->_Name = rhs.getName();
	this->_AP =rhs.getAPCost();
	this->_Dmg =rhs.getDamage();
	return *this;
}

/// FUNCTIONS ///
void	PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
