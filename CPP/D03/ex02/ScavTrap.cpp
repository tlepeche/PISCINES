/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 11:44:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/18 16:46:16 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void) {
	std::cout << "Normalement je dis jamais ca" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3) {
	std::cout << "Hi I'm " << this->getName()
	<< " a noble-yet-dangerous robot, alone, mysterious and desperate to be love..."	<< std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const & src) {
	*this = src;
	std::cout << "OMG i'm another clone!" << std::endl;
	return;
}

ScavTrap::~ScavTrap(void) {
	std::cout << std::endl << "I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs) {
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


////////// functions //////////
void	ScavTrap::rangedAttack(std::string const & target) {
	std::cout << std::endl << "SC4V-TP " << this->getName()
		<< " attacks " << target << "  at range, causing "
		<< this->getRatkdmg() << " points of damage! Fear his next rageous attack!" << std::endl;
	return;
}

void	ScavTrap::meleeAttack(std::string const & target) {
	std::cout << std::endl << "SC4V-TP " << this->getName()
		<< " attacks " << target << " on melee, causing "
		<< this->getMatkdmg() << " points of damage! Fear his next fierce attack!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	ClapTrap::takeDamage(amount);
	std::cout << std::endl
		<< "oh my god, i'm leaking! i think i'm leaking! ahhhh, i'm leaking! there's oil everywhere!"
		<< std::endl;
	std::cout << "SC4V-TP " << this->getName() << " health is now at " << this->getHP() << "." << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	ClapTrap::beRepaired(amount);
	std::cout << std::endl << "Health! Ooh, what flavor is red?" << std::endl;
	std::cout << "SC4V-TP " << this->getName() << " health is now at " << this->getHP() << "." << std::endl;
}

void	ScavTrap::_Stairs(std::string const & target) {
	(void)target;

	std::cout << "Climb stairs? NOOOOOOOOOOOOOOOOOOOOO! DAMN YOU, STAIRS!" <<	std::endl;
}

void	ScavTrap::_Cookie(std::string const & target) {
	(void)target;

	std::cout << "EAT A COOKIE! Well that's an easy one I'm sure to win this time!" <<	std::endl;
	std::cout << "Wait a minute. Those cookies aren't chocolate chip. Those...are...raisins. WHYYYYYY-HY-HYYYYY?! SHAWTY, DESTROY ALL THE FOOD DISPENSERS! WIPE THE RAISIN ABOMINATIONS OFF THE MAP! I JUST WANTED CHOCOLATE CHIP COOKIES! WHY DO BAD THINGS HAPPEN TO GOOD PEOPLE?" << std::endl;
}

void	ScavTrap::_Momjoke(std::string const & target) {
	(void)target;

	std::cout << "Do a \"mom joke\"! Easy, I'm gonna blow your mind!" <<	std::endl;
	std::cout << "Your momma is so dumb, she couldn't think of a good ending to this 'yo momma' joke! ... " << std::endl;
}



typedef	void	(ScavTrap::*f)(std::string const &);

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	f	action[5];

	action[0] = &ScavTrap::_Stairs;
	action[1] = &ScavTrap::_Cookie;
	action[2] = &ScavTrap::_Momjoke;

	if (this->getEnergy() >= 25)
	{
		std::cout << std::endl << "Oh my gosh, a challenge! Okay, we'll have to ..." << std::endl;
		this->setEnergy(this->getEnergy() - 25);
		f chosen = action[(std::rand() % 3)];
		(this->*chosen)(target);
		std::cout << "Okay " << target << ", you win this one (Energy left: " << this->getEnergy() << ")." << std::endl;
	}
	else
	{
		std::cout << std::endl << "I can't challenge anyone anymore... Alright " << target
			<< " you can enter to my boss evil lair!" << std::endl;
		std::cout << "SC4V-TP " << this->getName() << " need 25 energy to do a challenge (current: "
			<< this->getEnergy() << ")." << std::endl;
	}
}
