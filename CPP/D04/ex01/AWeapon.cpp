/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 12:26:48 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 14:53:10 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AWeapon.hpp"

AWeapon::AWeapon(void) {}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _Name(name), _AP(apcost), _Dmg(damage) {
}

AWeapon::AWeapon(AWeapon & src) {
	*this = src;
}

AWeapon::~AWeapon(void) {
}

AWeapon &	AWeapon::operator=(AWeapon const & rhs) {
	this->_Name =rhs.getName();
	this->_AP =rhs.getAPCost();
	this->_Dmg =rhs.getDamage();
	return *this;
}

/// GETTERS ///
std::string	AWeapon::getName(void) const {
	return this->_Name;
}

int		AWeapon::getAPCost(void) const {
	return this->_AP;
}

int		AWeapon::getDamage(void) const {
	return this->_Dmg;
}
