/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 11:44:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/18 20:22:00 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SuperTrap.hpp"
#include "ClapTrap.hpp"

SuperTrap::SuperTrap(void) {
	std::cout << "Normalement je dis jamais ca" << std::endl;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name, NinjaTrap::getHP(), NinjaTrap::getHP_max(),
	NinjaTrap::getEnergy(), NinjaTrap::getEnergy_max(), 1, NinjaTrap::getMatkdmg(),
	NinjaTrap::getRatkdmg(), NinjaTrap::getArmor()), NinjaTrap(), FragTrap() {
	
	this->_Name = name;
	std::cout << "Hi, I'm "
		<< this->getName()
		<< " the best TR4P robot ever created!" << std::endl
		<< "HP: " << this->getHP() << std::endl
		<< "HP: " << FragTrap::getHP() << std::endl
		<< "HP: " << NinjaTrap::getHP() << std::endl
		<< "HP_max: " << this->getHP_max() << std::endl
		<< "Energy: " << this->getEnergy() << std::endl
		<< "Energy_max: " << this->getEnergy_max() << std::endl
		<< "M_atk: " << this->getMatkdmg() << std::endl
		<< "R_atk: " << this->getRatkdmg() << std::endl
		<< "Armor: " << this->getArmor() << std::endl

		<< "Sname: " << this->getName() << std::endl
		<< "Fname: " << FragTrap::getName() << std::endl
		<< "Nname: " << NinjaTrap::getName() << std::endl;
	return;
}

SuperTrap::SuperTrap(SuperTrap const & src) {
	*this = src;
	std::cout << "OMG I'm a clone !" << std::endl;
	return;
}

SuperTrap::~SuperTrap(void) {
	std::cout << std::endl << "I'm dying" << std::endl;
}

SuperTrap &	SuperTrap::operator=(SuperTrap const & rhs) {
	this->setName(rhs.getName());
	this->setHP(rhs.getHP());
	this->setHP_max(rhs.getHP_max());
	this->setEnergy(rhs.getEnergy());
	this->setEnergy_max(rhs.getEnergy_max());
	this->setRatkdmg(rhs.getRatkdmg());
	this->setMatkdmg(rhs.getMatkdmg());
	this->setArmor(rhs.getArmor());
	return *this;
}


////////// FUNCTIONS //////////
void	SuperTrap::rangedAttack(std::string const & target) {
	FragTrap::rangedAttack(target);
	return;
}

void	SuperTrap::meleeAttack(std::string const & target) {
	NinjaTrap::meleeAttack(target);
}

void	SuperTrap::takeDamage(unsigned int amount) {
	ClapTrap::takeDamage(amount);
	std::cout << std::endl
		<< "Oh my God, I'm leaking! I think I'm leaking! Ahhhh, I'm leaking! There's oil everywhere!"
		<< std::endl;
	std::cout << "SuperTrap " << this->getName() << " health is now at " << this->getHP() << "." << std::endl;
}

void	SuperTrap::beRepaired(unsigned int amount) {
	ClapTrap::beRepaired(amount);
	std::cout << std::endl << "Health! Ooh, what flavor is red?" << std::endl;
	std::cout << "SuperTrap " << this->getName() << " health is now at " << this->getHP() << "." << std::endl;
}
