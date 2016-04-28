/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 11:44:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/18 20:20:55 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	std::cout << "hi" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int H, unsigned int Hm, unsigned int E, unsigned int Em,
		unsigned int lvl, unsigned int M, unsigned int R, unsigned int A) :
   	_Name(name), _HP(H), _HP_max(Hm), _Energy(E), _Energy_max(Em), _Level(lvl), _M_atkdmg(M),
	_R_atkdmg(R), _Armor(A) {
	std::cout << "A new CL4P-TP IS BORN!" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	*this = src;
	std::cout << "A new CL4P-TP CLONE IS BORN!" << std::endl;
	return;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "AND NOW IT'S DEAD!" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs) {
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
void	ClapTrap::rangedAttack(std::string const & target) {
	std::cout << std::endl << "FR4G-TP " << this->getName()
		<< " attacks " << target << "  at range, causing "
		<< this->getRatkdmg() << " points of damage! It's super effective!" << std::endl;
	return;
}

void	ClapTrap::meleeAttack(std::string const & target) {
	std::cout << std::endl << "FR4G-TP " << this->getName()
		<< " attacks " << target << " on melee, causing "
		<< this->getMatkdmg() << " points of damage! It's super effective!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	unsigned int	dmg;
	unsigned int	new_hp;

	dmg = amount - this->getArmor();
	new_hp = (dmg > this->getHP()) ? 0 : this->getHP() - dmg;
	this->setHP(new_hp);
}

void	ClapTrap::beRepaired(unsigned int amount) {
	unsigned int	heal;

	heal = this->getHP() + amount;
	this->setHP(heal);
}

////////// GETTERS //////////
std::string		ClapTrap::getName(void) const {
	return this->_Name;
}

unsigned int	ClapTrap::getHP(void) const {
	return this->_HP;
}

unsigned int	ClapTrap::getHP_max(void) const {
	return this->_HP_max;
}

unsigned int	ClapTrap::getEnergy(void) const {
	return this->_Energy;
}

unsigned int	ClapTrap::getEnergy_max(void) const {
	return this->_Energy_max;
}

unsigned int	ClapTrap::getLevel(void) const {
	return this->_Level;
}

unsigned int	ClapTrap::getRatkdmg(void) const {
	return this->_R_atkdmg;
}

unsigned int	ClapTrap::getMatkdmg(void) const {
	return this->_M_atkdmg;
}

unsigned int	ClapTrap::getArmor(void) const {
	return this->_Armor;
}


//////////	 SETTTERS //////////
void	ClapTrap::setName(std::string name) {
	this->_Name = name;
}

void	ClapTrap::setHP(unsigned int hp) {
	if (hp > this->getHP_max())
		hp = this->getHP_max(); 
	this->_HP = hp;
}

void	ClapTrap::setHP_max(unsigned int hpmax) {
	this->_HP_max = hpmax;
}

void	ClapTrap::setEnergy(unsigned int en) {
	this->_Energy = en;
}

void	ClapTrap::setEnergy_max(unsigned int enmax) {
	this->_Energy_max = enmax;
}

void	ClapTrap::setLevel(unsigned int lvl) {
	this->_Level = lvl;
}

void	ClapTrap::setRatkdmg(unsigned int atk) {
	this->_R_atkdmg = atk;
}

void	ClapTrap::setMatkdmg(unsigned int atk) {
	this->_M_atkdmg = atk;
}

void	ClapTrap::setArmor(unsigned int armor) {
	this->_Armor = armor;
}
