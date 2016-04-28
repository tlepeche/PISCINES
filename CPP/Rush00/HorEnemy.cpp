/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HorEnemy.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:38:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 08:14:18 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "HorEnemy.hpp"
#include "Squad.hpp"

HorEnemy::HorEnemy() {
}

HorEnemy::HorEnemy(HorEnemy & src) { (void)src ;}

HorEnemy::HorEnemy(int x, int y, int w, int h) : AEntity(1, x, y, w, h) {
}

HorEnemy::~HorEnemy() {
}

HorEnemy &	HorEnemy::operator=(HorEnemy const & rhs) {\
	this->_hp = rhs.getHP();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_w = rhs.getW();
	this->_h = rhs.getH();
	return *this;
}

/// FUNCTIONS ///
void		HorEnemy::entMove(void) {
	this->_x -= 1;
}

void		HorEnemy::display(void) const {
	mvprintw(this->_y - 1, this->_x, "/-\\");
	mvprintw(this->_y, this->_x, "{o}");
	mvprintw(this->_y + 1, this->_x, "\\-/");
}

void		HorEnemy::destroy(void) {
	delete this;
	Squad::_score += 100;
}
