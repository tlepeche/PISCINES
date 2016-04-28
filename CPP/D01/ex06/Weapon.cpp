/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:13:20 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 16:49:34 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _Type(type) {
}

Weapon::~Weapon(void) {
}

std::string Weapon::getType(void) const {
	return this->_Type;
}

void	Weapon::setType(std::string type) {
	this->_Type = type;
	return ;
}
