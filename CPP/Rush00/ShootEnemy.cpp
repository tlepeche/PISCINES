/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShootEnemy.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:38:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 11:40:35 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "ShootEnemy.hpp"
#include "Squad.hpp"

ShootEnemy::ShootEnemy() {
}

ShootEnemy::ShootEnemy(ShootEnemy & src) { (void)src ;}

ShootEnemy::ShootEnemy(int x, int y, int w, int h) : AEntity(1, x, y, w, h),
	_yMin(15), _yMax(74)  {
		this->_boss = true;
		this->_weap = new Weapon;
}

ShootEnemy::~ShootEnemy() {
}

ShootEnemy &	ShootEnemy::operator=(ShootEnemy const & rhs) {\
	this->_hp = rhs.getHP();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_w = rhs.getW();
	this->_h = rhs.getH();
	return *this;
}

/// FUNCTIONS ///
void		ShootEnemy::entMove(void) {
	this->_x -= 1;
		this->_y += (std::rand() % 3) - 1;
		if (this->_y <= this->_yMin)
			this->_y = this->_yMin;
		if (this->_y >= this->_yMax)
			this->_y = this->_yMax;
}

void		ShootEnemy::display(void) const {
	mvprintw(this->getY() - 1, this->getX(),"/^\\");
	mvprintw(this->getY() - 0, this->getX(), "|o|");
	mvprintw(this->getY() + 1, this->getX(), "\\_/");
}

void		ShootEnemy::destroy(void) {
	delete this;
	Squad::_score += 200;
}

void	ShootEnemy::shoot(void) {
	if (std::rand() % 100 < 10)
		this->_weap->push(new BossAmmo(this->_x - 1, this->_y));
	attron(COLOR_PAIR(6));
	this->_weap->display();
	attroff(COLOR_PAIR(6));
}

Weapon *ShootEnemy::getWeap(void) const {return this->_weap;}
