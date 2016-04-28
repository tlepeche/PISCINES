/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                       	                          +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:38:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 10:01:24 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "AEntity.hpp"

AEntity::AEntity() {AEntity::_built++;}

AEntity::AEntity(AEntity & src) { 
	*this = src;
	AEntity::_built++;
}

AEntity::AEntity(int hp, int x, int y, int w, int h) : _id(AEntity::_built), _hp(hp), _x(x), _y(y), _w(w), _h(h) {
	AEntity::_built++;
	this->_boss = false;
}

AEntity::~AEntity() {
}

AEntity &	AEntity::operator=(AEntity const & rhs) {
	this->_hp = rhs.getHP();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	return *this;
}

/// GETTERS ///
int		AEntity::getID() const { return this->_id; }
int		AEntity::getHP() const { return this->_hp; }
int		AEntity::getX() const { return this->_x; }
int		AEntity::getY() const { return this->_y; }
int		AEntity::getW() const { return this->_w; }
int		AEntity::getH() const { return this->_h; }
bool	AEntity::getBoss() const { return this->_boss; }

void	AEntity::takeDamage(int amount) {
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
}

Weapon		*AEntity::getWeap(void) const {
	return NULL;
}

int	AEntity::_built = 0;
