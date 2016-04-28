/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiagEnemy.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:38:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 10:10:13 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "DiagEnemy.hpp"
#include "Squad.hpp"

DiagEnemy::DiagEnemy() {
}

DiagEnemy::DiagEnemy(DiagEnemy & src) { (void)src ;}

DiagEnemy::DiagEnemy(int x, int y, int w, int h) : AEntity(1, x, y, w, h),
	_yMin(4 + 5), _yMax(84 - 7), _way(true)  {
}

DiagEnemy::~DiagEnemy() {
}

DiagEnemy &	DiagEnemy::operator=(DiagEnemy const & rhs) {\
	this->_hp = rhs.getHP();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_w = rhs.getW();
	this->_h = rhs.getH();
	return *this;
}

/// FUNCTIONS ///
void		DiagEnemy::entMove(void) {
	this->_x -= 2;
	if (this->_way)
	{
		this->_y -= 1;
		if (this->_y == this->_yMin)
			this->_way = false;
	}
	else
	{
		this->_y += 1;
		if (this->_y == this->_yMax)
			this->_way = true;
	}
}

void		DiagEnemy::display(void) const {
	mvprintw(this->_y - 1, this->_x, "-//");
	mvprintw(this->_y, this->_x, "<-{");
	mvprintw(this->_y + 1, this->_x, "-\\\\");
}

void		DiagEnemy::destroy(void) {
	delete this;
	Squad::_score += 150;
}
