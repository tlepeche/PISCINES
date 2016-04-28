/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HorAmmo.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:38:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 11:27:36 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "HorAmmo.hpp"
#include "Squad.hpp"

HorAmmo::HorAmmo() {
}

HorAmmo::HorAmmo(HorAmmo & src) { (void)src ;}

HorAmmo::HorAmmo(int x, int y) : AEntity(1, x, y, 1, 1) {
}

HorAmmo::~HorAmmo() {
}

HorAmmo &	HorAmmo::operator=(HorAmmo const & rhs) {
	this->_hp = rhs.getHP();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_w = rhs.getW();
	this->_h = rhs.getH();
	return *this;
}

/// FUNCTIONS ///
void		HorAmmo::entMove(void) {
	this->_x += 2;
}

void		HorAmmo::display(void) const {
	move(this->getY(), this->getX());

	attron(COLOR_PAIR(4));
	printw("+");
	attroff(COLOR_PAIR(4));
}

void		HorAmmo::destroy(void) {
	delete this;
	//	Squad::_score += 1;
}

int	HorAmmo::getY() const {return this->_y - 1;}
