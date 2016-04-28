/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BossAmmo.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:38:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 09:26:36 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "BossAmmo.hpp"
#include "Squad.hpp"

BossAmmo::BossAmmo() {
}

BossAmmo::BossAmmo(BossAmmo & src) { (void)src ;}

BossAmmo::BossAmmo(int x, int y) : AEntity(1, x, y, 3, 1) {
}

BossAmmo::~BossAmmo() {
}

BossAmmo &	BossAmmo::operator=(BossAmmo const & rhs) {
	this->_hp = rhs.getHP();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_w = rhs.getW();
	this->_h = rhs.getH();
	return *this;
}

/// FUNCTIONS ///
void		BossAmmo::entMove(void) {
	this->_x -= 2;
	if (this->_x <= 0)
		this->_x = 0;
}

void		BossAmmo::display(void) const {
	move(this->getY(), this->getX());
	printw("(=)");
}

void		BossAmmo::destroy(void) {
	delete this;
}

int	BossAmmo::getY() const {return this->_y - 1;}
