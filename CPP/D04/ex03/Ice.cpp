/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 23:02:05 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/20 00:02:44 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : _Type("ice"), xp_(0) {
	std::cout << "Ice created" << std::endl;
}

Ice::Ice(Ice & src) : _Type(src.getType()), xp_(src.getXP()) {
	std::cout << "Ice copied" << std::endl;
}
/*
Ice::Ice(std::string const & type) : _Type(type), xp_(0) {
	std::cout << "Ice " << this->getType() << " created." << std::endl;
}
*/
Ice::~Ice() {
	std::cout << "Ice " << this->getType() << " destroyed." << std::endl;
}

AMateria * Ice::clone() const{
	AMateria *pop;
	return (pop);
}

/// GETTERS ///
std::string const &	Ice::getType() const { return this->_Type; }
unsigned int		Ice::getXP() const { return this->xp_; }

/// FUNCTIONS ///
void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at *" << target.getName() << std::endl;
	this->xp_ += 10;
}
