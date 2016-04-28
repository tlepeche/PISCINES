/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 21:22:10 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 23:58:58 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() { std::cout << "Empty AMateria created" << std::endl; }

AMateria::AMateria(AMateria & src) : _Type(src.getType()), xp_(src.getXP()) {
	std::cout << "AMateria copied" << std::endl;
}

AMateria::AMateria(std::string const & type) : _Type(type), xp_(0) {
	std::cout << "AMateria " << this->getType() << " created." << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria " << this->getType() << " destroyed." << std::endl;
}

AMateria &	AMateria::operator=(AMateria const & rhs) {
	this->xp_ = rhs.getXP();
	return *this;
}


/// GETTERS ///
std::string const &	AMateria::getType() const { return this->_Type; }
unsigned int		AMateria::getXP() const { return this->xp_; }

/// FUNCTIONS ///
void	AMateria::use(ICharacter& target) {
	(void)target;
/*	if (this->getType() == "ice")
	{
		this->_xp += 10;
		std::cout << "* shoots an ice bolt at *" << target.getName() << std::endl;
	}
	else if (this->getType() == "cure")
	{
		this->_xp += 10;
		std::cout << "* heals " << targer.getName() << "’s wounds *" << std::endl;
	}*/
}
