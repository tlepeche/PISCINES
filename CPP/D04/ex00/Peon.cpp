/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 10:38:26 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 12:03:46 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Peon.hpp"

Peon::Peon(void) {
	std::cout << "I dont do this" << std::endl;
}

Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon & src) {
	*this = src;
	std::cout << "Clone created" << std::endl;
}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
}

Peon &	Peon::operator=(Peon const & rhs) {
	this->setName(rhs.getName());
	return *this;
}

///// FUNCTIONS /////
void	Peon::getPolymorphed(void) const {
	std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}
