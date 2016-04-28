/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 10:38:26 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 11:55:20 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void) {
	std::cout << "I dont do this" << std::endl;
}

Sorcerer::Sorcerer(std::string name, std::string title) : _Name(name), _Title(title) {
	std::cout << this->getName() << ", " << this->getTitle() << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer & src) {
	*this = src;
	std::cout << "Clone created" << std::endl;
}

Sorcerer::~Sorcerer(void) {
	std::cout << this->getName() << ", " << this->getTitle() << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer &	Sorcerer::operator=(Sorcerer const & rhs) {
	this->setName(rhs.getName());
	this->setTitle(rhs.getTitle());
	return *this;
}

///// FUNCTIONS /////
std::string	Sorcerer::introduce(void) const {
	std::string intro;

	intro = "I am "	+ this->getName() + ", " + this->getTitle() + ", and I like ponies !";
	return intro;
}

void	Sorcerer::polymorph(Victim const & vic) const {
	vic.getPolymorphed();
}
///// SETTERS /////
void	Sorcerer::setName(std::string name) {
	this->_Name = name;
}

void	Sorcerer::setTitle(std::string title) {
	this->_Title = title;
}

///// GETTERS /////
std::string Sorcerer::getName(void) const {
	return this->_Name;
}

std::string Sorcerer::getTitle(void) const {
	return this->_Title;
}

std::ostream	&operator<<(std::ostream & lhs, Sorcerer const & rhs) {
	lhs << rhs.introduce();
	lhs << std::endl;
	return lhs;
}
