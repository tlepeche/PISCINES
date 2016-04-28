/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 11:44:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/18 17:49:10 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

NinjaTrap::NinjaTrap(void) {
	std::cout << "Normalement je dis jamais ca" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) :  ClapTrap(name, 60, 60, 120, 120, 1, 60, 5, 0) {
	std::cout << "Hi, I'm "
		<< this->_Name
		<< " an Interplanetary Ninja Assassin CL4P-TR4P. Viva La Robolution!"
		<< std::endl;
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) {
	*this = src;
	std::cout << "OMG I'm a clone !" << std::endl;
	return;
}

NinjaTrap::~NinjaTrap(void) {
	std::cout << std::endl << "I'm afraid. My mind is going. I can feel it. My mind is going! There's no question about it. I can feel it. I'm a... fraid." << std::endl;
}

NinjaTrap &	NinjaTrap::operator=(NinjaTrap const & rhs) {
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

void	NinjaTrap::rangedAttack(std::string const & target) {
	std::cout << std::endl << "INAC " << this->getName()
		<< " attacks " << target << "  at range, causing "
		<< this->getRatkdmg() << " points of damage! It's super effective!" << std::endl;
	return;
}

void	NinjaTrap::meleeAttack(std::string const & target) {
	std::cout << std::endl << "INAC " << this->getName()
		<< " attacks " << target << " on melee, causing "
		<< this->getMatkdmg() << " points of damage! It's super effective!" << std::endl;
}

void	NinjaTrap::takeDamage(unsigned int amount) {
	ClapTrap::takeDamage(amount);
	std::cout << std::endl
		<< "Oh my God, I'm leaking! I think I'm leaking! Ahhhh, I'm leaking! There's oil everywhere!"
		<< std::endl;
	std::cout << "INAC " << this->getName() << " health is now at " << this->getHP() << "." << std::endl;
}

void	NinjaTrap::beRepaired(unsigned int amount) {
	ClapTrap::beRepaired(amount);
	std::cout << std::endl << "Health! Ooh, what flavor is red?" << std::endl;
	std::cout << "INAC " << this->getName() << " health is now at " << this->getHP() << "." << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap & target) {
	if (this->getEnergy() >= 25)
	{
		std::cout <<std::endl << "INAC " << this->getName()
			<< " engaged the fight with " << target.getName()
			<< std::endl << "Punch punch! Fight!" << std::endl;
	}
	else
	{
		std::cout << "Nonono! You'll never take me alive!" << std::endl;
		std::cout << "FR4G-TP " << this->getName() << " need 25 energy to do special atk (current: "
			<< this->getEnergy() << ")." << std::endl;
	}
}

void	NinjaTrap::ninjaShoebox(NinjaTrap & target) {
	if (this->getEnergy() >= 25)
	{
		std::cout <<std::endl << "INAC " << this->getName()
			<< " engaged the fight with " << target.getName()
			<< std::endl << "A claptrap feels no pain- ow! Quit it!" << std::endl;
	}
	else
	{
		std::cout << "Nonono! You'll never take me alive!" << std::endl;
		std::cout << "FR4G-TP " << this->getName() << " need 25 energy to do special atk (current: "
			<< this->getEnergy() << ")." << std::endl;
	}
}

void	NinjaTrap::ninjaShoebox(FragTrap & target) {
	if (this->getEnergy() >= 25)
	{
		std::cout <<std::endl << "INAC " << this->getName()
			<< " engaged the fight with " << target.getName()
			<< std::endl << "Shoryuken!" << std::endl;
	}
	else
	{
		std::cout << "Nonono! You'll never take me alive!" << std::endl;
		std::cout << "FR4G-TP " << this->getName() << " need 25 energy to do special atk (current: "
			<< this->getEnergy() << ")." << std::endl;
	}
}

void	NinjaTrap::ninjaShoebox(ScavTrap & target) {
	if (this->getEnergy() >= 25)
	{
		std::cout <<std::endl << "INAC " << this->getName()
			<< " engaged the fight with " << target.getName()
			<< std::endl << "Target disassembled." << std::endl;
	}
	else
	{
		std::cout << "Nonono! You'll never take me alive!" << std::endl;
		std::cout << "FR4G-TP " << this->getName() << " need 25 energy to do special atk (current: "
			<< this->getEnergy() << ")." << std::endl;
	}
}
