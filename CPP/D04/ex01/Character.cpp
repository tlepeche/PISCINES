/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 12:26:48 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/20 11:50:57 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Character.hpp"

Character::Character(void) {}

Character::Character(std::string const & name) : _Name(name), _AP(40), _Weap(NULL) {
}

Character::Character(Character & src) {
	*this = src;
	std::cout << "Weapon copied." << std::endl;
}

Character::~Character(void) {
	std::cout << "Weapon " << this->getName() << " destroyed."  << std::endl;
}

Character &	Character::operator=(Character const & rhs) {
	this->_AP = rhs.getAP();
	this->_Weap = rhs.getWeapon();
	return *this;
}

/// FUNCTIONS ///
void	Character::attack(Enemy *Enemy) {
	if (this->getWeapon() != NULL)
	{
		if (this->getAP() >= this->getWeapon()->getAPCost())
		{
			std::cout << this->getName() << " attacks "
				<< Enemy->getType() << " with a "
				<< this->getWeapon()->getName() << std::endl;
			this->getWeapon()->attack();

			this->_AP -= this->getWeapon()->getAPCost();

			Enemy->takeDamage(this->getWeapon()->getDamage());
			if (Enemy->getHP() == 0)
				delete Enemy;
		}
		else
			std::cout << "Not enough AP ( " << this->getAP()
				<< "/" << this->getWeapon()->getAPCost() << ")." << std::endl;
	}
}

void	Character::equip(AWeapon *Weap) {
	this->_Weap = Weap;
}

void	Character::recoverAP() {
	this->_AP += 10;
	this->_AP = (this->_AP > 40) ? 40 : this->_AP;
	std::cout << this->getName() << " recover 10 AP (AP = " << this->getAP() << ")." << std::endl;
}

/// GETTERS ///
std::string	Character::getName(void) const {
	return this->_Name;
}

int			Character::getAP(void) const {
	return this->_AP;
}

AWeapon *	Character::getWeapon(void) const {
	return this->_Weap;
}

std::ostream &operator<<(std::ostream & lhs, Character const & rhs) {
	std::string intro;
	std::string AP;
	std::stringstream str;

	str << rhs.getAP();
	str >> AP;
	intro = rhs.getName() + " has " + AP + " AP and ";
	if (rhs.getWeapon() == NULL)
		intro += "is unarmed";
	else
		intro += "wields a " + rhs.getWeapon()->getName();
	lhs << intro;
	lhs << std::endl;
	return lhs;
}
