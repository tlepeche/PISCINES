/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CircleEnemy.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:38:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 05:45:15 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "CircleEnemy.hpp"
#include "Squad.hpp"

CircleEnemy::CircleEnemy() {
}

CircleEnemy::CircleEnemy(CircleEnemy & src) { (void)src ;}

CircleEnemy::CircleEnemy(int x, int y, int w, int h) : AEntity(1, x, y, w, h), _initX(x), _initY(y) {
}

CircleEnemy::~CircleEnemy() {
}

CircleEnemy &	CircleEnemy::operator=(CircleEnemy const & rhs) {\
	this->_hp = rhs.getHP();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_w = rhs.getW();
	this->_h = rhs.getH();
	return *this;
}

/// FUNCTIONS ///
void		CircleEnemy::entMove(void) {
	if (CircleEnemy::_turn == true)
	{
		if (CircleEnemy::_way == 0)
		{
			this->_x -= 3;
			this->_y -= 1;
			if (this->_y == this->_initY - 10)
				CircleEnemy::_way = 1;
		}
		else if (CircleEnemy::_way == 1)
		{
			this->_x -= 3;
			this->_y += 1;
			if (this->_y == this->_initY)
				CircleEnemy::_way = 2;
		}
		else if (CircleEnemy::_way == 2)
		{
			this->_x += 3;
			this->_y += 1;
			if (this->_y == this->_initY + 10)
				CircleEnemy::_way = 3;
		}
		else if (CircleEnemy::_way == 3)
		{
			this->_x += 3;
			this->_y -= 1;
			if (this->_y == this->_initY)
				CircleEnemy::_way = 0;
		}
	}
	else
	{
		this->_x -= 1;
	}
	if (this->_x < 300)
		CircleEnemy::_turn = true;
	(void)this->_initX;
}

void		CircleEnemy::display(void) const {
	move(this->getY(), this->getX());
	printw("@");
}

void		CircleEnemy::destroy(void) {
	delete this;
	Squad::_score += 200;
}

bool	CircleEnemy::_turn = false;
int		CircleEnemy::_way = 0;
