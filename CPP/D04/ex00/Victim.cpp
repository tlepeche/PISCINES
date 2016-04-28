/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 10:38:26 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 11:57:12 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Victim.hpp"

Victim::Victim(void) {
	std::cout << "I dont do this" << std::endl;
}

Victim::Victim(std::string name) : _Name(name) {
	std::cout << "Some random victim called " << this->getName() << " just popped." << std::endl;
}

Victim::Victim(Victim & src) {
	*this = src;
	std::cout << "Clone created" << std::endl;
}

Victim::~Victim(void) {
	std::cout << "Victim " << this->getName() << " just died for no apparent reason!" << std::endl;
}

Victim &	Victim::operator=(Victim const & rhs) {
	this->setName(rhs.getName());
	return *this;
}

///// FUNCTIONS /////
std::string	Victim::introduce(void) const {
	std::string intro;
	
	intro = "I am " + this->getName() + " and I like otters!";
	return intro;
}

void	Victim::getPolymorphed(void) const {
	std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
}

///// SETTERS /////
void	Victim::setName(std::string name) {
	this->_Name = name;
}

///// GETTERS /////
std::string Victim::getName(void) const {
	return this->_Name;
}

std::ostream	&operator<<(std::ostream & lhs, Victim const & rhs) {
	lhs << rhs.introduce();
	lhs << std::endl;
	return lhs;
}
