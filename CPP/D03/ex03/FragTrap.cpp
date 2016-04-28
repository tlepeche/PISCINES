/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 11:44:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/18 16:45:34 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(void) {
	std::cout << "Normalement je dis jamais ca" << std::endl;
}

FragTrap::FragTrap(std::string name) :  ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5) {
	std::cout << "Hi, I am a CL4P-TP steward robot, but my friends call me "
		<< this->_Name
		<< "! Or they would, if any of them were still alive. Or had existed in the first place!"
		<< std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const & src) {
	*this = src;
	std::cout << "OMG I'm a clone !" << std::endl;
	return;
}

FragTrap::~FragTrap(void) {
	std::cout << std::endl << "Selfdestruction countdown: 3... 2... 5... 1... BOOOOM !" << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap const & rhs) {
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

void	FragTrap::rangedAttack(std::string const & target) {
	std::cout << std::endl << "FR4G-TP " << this->getName()
		<< " attacks " << target << "  at range, causing "
		<< this->getRatkdmg() << " points of damage! It's super effective!" << std::endl;
	return;
}

void	FragTrap::meleeAttack(std::string const & target) {
	std::cout << std::endl << "FR4G-TP " << this->getName()
		<< " attacks " << target << " on melee, causing "
		<< this->getMatkdmg() << " points of damage! It's super effective!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	ClapTrap::takeDamage(amount);
	std::cout << std::endl
	   << "Oh my God, I'm leaking! I think I'm leaking! Ahhhh, I'm leaking! There's oil everywhere!"
	   << std::endl;
	std::cout << "FR4G-TP " << this->getName() << " health is now at " << this->getHP() << "." << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {
	ClapTrap::beRepaired(amount);
	std::cout << std::endl << "Health! Ooh, what flavor is red?" << std::endl;
	std::cout << "FR4G-TP " << this->getName() << " health is now at " << this->getHP() << "." << std::endl;
}

void	FragTrap::_Seppuku(std::string const & target) {
	unsigned int	new_hp;

	(void)target;
	new_hp = (this->getHP() <= 5) ? 0 : this->getHP() - 5;
	this->setHP(new_hp);
	std::cout << std::endl << "For you.. I commit.. seppuku" <<	std::endl;
	std::cout << "FR4G-TP " << this->getName() << " cut himself up and loose 5 hp (current health: "
		<< this->getHP() << ") (Energy left: " << this->getEnergy() << ")." << std::endl;
}

void	FragTrap::_HeavyMachineGun(std::string const & target) {
	std::cout << std::endl << "YOU GET A BULLET! YOU GET A BULLET! EVERYBODY GETS A BULLET!" <<	std::endl;
	std::cout << "FR4G-TP " << this->getName() << " take his Heavy MachineGun a deals " << (this->getRatkdmg() * 2)
		<< " to " << target 
		<< " (Energy left: " << this->getEnergy() << ")." << std::endl;
}

void	FragTrap::_MegaMelee(std::string const & target) {
	std::cout << std::endl << "This is my power! Fear me, bitches!" <<	std::endl;
	std::cout << "FR4G-TP " << this->getName() << " go to melee and deals " << (this->getMatkdmg() * 2)
		<< " to " << target
		<< " (Energy left: " << this->getEnergy() << ")." << std::endl;
}

void	FragTrap::_Dance(std::string const & target) {
	(void)target;
	std::cout << std::endl << "Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance! Commencing directive three! Uhntssuhntssuhntss." << std::endl;
	std::cout << "FR4G-TP " << this->getName() << " starts to dance"
		<< " (Energy left: " << this->getEnergy() << ")." << std::endl;
}

void	FragTrap::_Burn(std::string const & target) {
	std::cout << std::endl << "I am Fire! I am Death! BURN ALL THE BABIES!!!!!!!" << std::endl;
	std::cout << "FR4G-TP " << this->getName() << " burns " << target << " and deals him "
		<< (this->getMatkdmg() + this->getRatkdmg()) << " damages"
		<< " (Energy left: " << this->getEnergy() << ")." << std::endl;
}


typedef	void	(FragTrap::*f)(std::string const &);

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	f	action[5];

	action[0] = &FragTrap::_Seppuku;
	action[1] = &FragTrap::_HeavyMachineGun;
	action[2] = &FragTrap::_MegaMelee;
	action[3] = &FragTrap::_Dance;
	action[4] = &FragTrap::_Burn;

	if (this->getEnergy() >= 25)
	{
		this->setEnergy(this->getEnergy() - 25);
		f chosen = action[(std::rand() % 5)];
		(this->*chosen)(target);
	}
	else
	{
		std::cout << std::endl << "I don't have enough energy do to that MORON!" << std::endl;
		std::cout << "FR4G-TP " << this->getName() << " need 25 energy to do special atk (current: "
			<< this->getEnergy() << ")." << std::endl;
	}
}
