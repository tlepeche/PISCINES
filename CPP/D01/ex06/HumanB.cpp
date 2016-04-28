/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:18:02 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 16:49:13 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _Name(name) {
}

HumanB::~HumanB(void) {
}

void	HumanB::attack(void) {
	std::cout << this->_Name << " attacks with his " << this->_W->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weap) {
	this->_W = &weap;
	return ;
}
