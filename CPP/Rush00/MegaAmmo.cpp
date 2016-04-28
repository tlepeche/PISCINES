/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaAmmo.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:38:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 11:05:31 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "MegaAmmo.hpp"
#include "Squad.hpp"

MegaAmmo::MegaAmmo() {
}

MegaAmmo::MegaAmmo(MegaAmmo & src) { (void)src ;}

MegaAmmo::MegaAmmo(int x, int y) : AEntity(1, x, y, 9, 3) {
}

MegaAmmo::~MegaAmmo() {
}

MegaAmmo &	MegaAmmo::operator=(MegaAmmo const & rhs) {
	this->_hp = rhs.getHP();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_w = rhs.getW();
	this->_h = rhs.getH();
	return *this;
}

/// FUNCTIONS ///
void		MegaAmmo::entMove(void) {
	this->_x -= 2;
	if (this->_x <= 0)
		this->_x = 0;
}

void		MegaAmmo::display(void) const {
	mvprintw(this->getY(), this->getX(), " /~~~~~~~");
	mvprintw(this->getY()+1, this->getX(), "{========");
	mvprintw(this->getY()+2, this->getX(), " \\~~~~~~~");
}

void		MegaAmmo::destroy(void) {
	delete this;
}

int	MegaAmmo::getY() const {return this->_y - 1;}
