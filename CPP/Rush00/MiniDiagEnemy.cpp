/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniDiagEnemy.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:38:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 08:53:06 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "MiniDiagEnemy.hpp"
#include "Squad.hpp"

MiniDiagEnemy::MiniDiagEnemy() {
}

MiniDiagEnemy::MiniDiagEnemy(MiniDiagEnemy & src) { (void)src ;}

MiniDiagEnemy::MiniDiagEnemy(int x, int y, int w, int h) : AEntity(1, x, y, w, h),
	_yMin(15), _yMax(74)  {
}

MiniDiagEnemy::~MiniDiagEnemy() {
}

MiniDiagEnemy &	MiniDiagEnemy::operator=(MiniDiagEnemy const & rhs) {\
	this->_hp = rhs.getHP();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_w = rhs.getW();
	this->_h = rhs.getH();
	return *this;
}

/// FUNCTIONS ///
void		MiniDiagEnemy::entMove(void) {
	this->_x -= 1;
		this->_y += (std::rand() % 3) - 1;
		if (this->_y <= this->_yMin)
			this->_y = this->_yMin;
		if (this->_y >= this->_yMax)
			this->_y = this->_yMax;
}

void		MiniDiagEnemy::display(void) const {
	mvprintw(this->getY() - 1, this->getX(), "/=[");
	mvprintw(this->getY() - 0, this->getX(), " ()");
	mvprintw(this->getY() + 1, this->getX(), "\\=[");
}

void		MiniDiagEnemy::destroy(void) {
	delete this;
	Squad::_score += 100;
}
