/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:10:04 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/21 11:09:38 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

# define KEY_SPACE ' '

Player::Player( void )
{
	this->_hp = 1;
	this->_y = 45;
	this->_x = 10;
	this->_w = 3;
	this->_h = 3;
	this->_weap = new Weapon;
}

Player::~Player( void )
{
	return;
}

void	Player::playerMove( int input )
{
	switch ( input )
	{
		case KEY_UP:
			this->_y--;
			break;
		case KEY_DOWN:
			this->_y++;
			break;
		case KEY_LEFT:
			if (this->_x > 10)
				this->_x--;
			break;
		case KEY_RIGHT:
			if (this->_x < 350)
				this->_x++;
			break;
		case KEY_SPACE:
			this->_weap->push(new HorAmmo(this->_x + 3, this->_y + 1));
			break;
	}
}

void	Player::setPos( int x, int y )
{
	this->_y = x;
	this->_x = y;
}

bool	Player::playerUpdate( int x, int y )
{
	int i = this->_y;
	int	j = this->_x;
	if ((x >= i - 1 && x <= i + 1) && (y >= j - 1 && y <= j + 1))
		return true;
	return false;
}

void	Player::playerExplodes( void ) const
{
	attron(COLOR_PAIR(1));
	mvprintw(this->_y - 1, this->_x, "\\|/");
	mvprintw(this->_y, this->_x, "-O-");
	mvprintw(this->_y + 1, this->_x, "/|\\");
	attroff(COLOR_PAIR(1));
}

void	Player::display( void ) const
{
	attron(COLOR_PAIR(2));
	mvprintw(this->_y - 1, this->_x, "|\\");
	mvprintw(this->_y, this->_x, "=o>");
	mvprintw(this->_y + 1, this->_x, "|/");
	attroff(COLOR_PAIR(2));
}

int	Player::getX() const {return this->_y; }
int	Player::getY() const {return this->_x; }
int	Player::getW() const {return this->_w; }
int	Player::getH() const {return this->_h; }

Weapon	*Player::getWeapon( void ) { return this->_weap; }
