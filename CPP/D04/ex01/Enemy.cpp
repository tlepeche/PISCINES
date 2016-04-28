/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 12:26:48 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/20 11:49:10 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(void) {}

Enemy::Enemy(int hp, std::string const & type) : _HP(hp), _Type(type) {
}

Enemy::Enemy(Enemy & src) {
	*this = src;
}

Enemy::~Enemy(void) {
}

Enemy &	Enemy::operator=(Enemy const & rhs) {
	this->_HP =rhs.getHP();
	this->_Type = rhs.getType();
	return *this;
}

/// GETTERS ///
int			Enemy::getHP(void) const {
	return this->_HP;
}

std::string	Enemy::getType(void) const {
	return this->_Type;
}

/// FUNCTIONS ///
void	Enemy::takeDamage(int amount) {
		this->_HP = (amount > this->getHP()) ? 0 : this->getHP() - amount;
}
