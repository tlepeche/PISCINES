/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:38:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 11:37:42 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "Boss.hpp"
#include "Squad.hpp"
#include "Game.hpp"

Boss::Boss() {
}

Boss::Boss(Boss & src) { (void)src ;}

Boss::Boss(int x, int y, int w, int h) : AEntity(100, x, y, w, h), _way(true) {
	this->_weap = new Weapon;
	this->_boss = true;
}

Boss::~Boss() {
}

Boss &	Boss::operator=(Boss const & rhs) {
	this->_hp = rhs.getHP();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_w = rhs.getW();
	this->_h = rhs.getH();
	return *this;
}

/// FUNCTIONS ///
void		Boss::entMove(void) {
	if (this->_way)
	{
		if (this->_y > (10 + this->_h / 2))
			this->_y -= 1;
		else
			this->_way = false;
	}
	else
	{
		if (this->_y < (73 - this->_h / 2))
			this->_y += 1;
		else
			this->_way = true;
	}
}

void		Boss::display(void) const {
	int	x = this->getX();
	int	y = this->getY();

	attron(COLOR_PAIR(5));
	mvprintw(y - 12, x + 14 , "%d / %d", this->_hp, 100);
	attroff(COLOR_PAIR(5));
	mvprintw(y - 11, x, "              #########");
	mvprintw(y - 10, x, "             ## ``````@");
	mvprintw(y - 9, x, "            ## ```````#");
	mvprintw(y - 8, x, "           ## ```````@#");
	mvprintw(y - 7, x, "          ## `.``````##");
	mvprintw(y - 6, x, "         ## ````````@##");
	mvprintw(y - 5, x, "       ##@@@@@@@@@@@## ");
	mvprintw(y - 4, x, "      ## ```````````@##");
	mvprintw(y - 3, x, "       ##@@@........@##");
	mvprintw(y - 2, x, "   @ @``@```````````## ");
	mvprintw(y - 1, x, "  #``++``@@@@@@@@@@@@@@");
	mvprintw(y - 0, x, " #```++``@@@@@@@@@@@@@@");
	mvprintw(y + 1, x, "  #``++`.@@@@@@@@@@@@@@");
	mvprintw(y + 2, x, "   @.@`.@...........## ");
	mvprintw(y + 3, x, "       ##@@@........@##");
	mvprintw(y + 4, x, "      ## `````......@##");
	mvprintw(y + 5, x, "       ##@@@@@@@@@@@## ");
	mvprintw(y + 6, x, "         ## ````````@##");
	mvprintw(y + 7, x, "          ## `.``````##");
	mvprintw(y + 8, x, "           ## ```.```@#");
	mvprintw(y + 9, x, "            ## `````.`#");
	mvprintw(y + 10, x, "             ## ``````@");
	mvprintw(y + 11, x, "              #########");
}

void		Boss::destroy(void) {
	delete this;
	Squad::_score += 1000;
	Game::_boss = 2;
}

void		Boss::shoot(void) {
	if (std::rand() % 100 < 20)
		this->_weap->push(new MegaAmmo(this->_x - 11, this->_y));
	attron(COLOR_PAIR(6));
	this->_weap->display();
	attroff(COLOR_PAIR(6));
}

Weapon	*Boss::getWeap(void) const { return this->_weap; }
