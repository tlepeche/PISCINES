/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 10:02:53 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 11:08:25 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Squad.hpp"
#include <ncurses.h>
#include "Hitbox.hpp"

Squad::Squad() : _count(0) {
	int i = 0;
	while (i < 15)
	{
		this->_ent[i] = NULL;
		i++;
	}
}

Squad::Squad(Squad & src) {
	*this = src;
}

Squad::~Squad() {}

Squad	&	Squad::operator=(Squad const & rhs) {
	this->_count = rhs.getCount();
	return *this;
}

/// GETTERS ///
int				Squad::getCount() const { return this->_count; }

int				Squad::getScore() const { return Squad::_score; }

int				Squad::checkPlayer( AEntity *p )
{
	int	i = 0;
	while (i < 15)
	{
		AEntity	*e = this->getUnit(i);
		if (e != NULL)
		{
			Hitbox hb;
			if (hb.collision(p, e) == 1)
			{
				this->destroy(e, false);
				this->bombEffect(e->getX(), e->getY());
				return 1;
			}
		}
		i++;
	}
	return 0;
}

void	Squad::useBomb( void )
{
	int i = 0;
	while (i < 15)
	{
		AEntity *e = this->getUnit(i);
		if (e != NULL)
		{
			if (e->getBoss() == false)
				this->destroy(e, true);
			else
			{
				e->takeDamage(25);
				if (e->getHP() == 0)
					this->destroy(e, true);
			}
			this->bombEffect(e->getX(), e->getY());
		}
		i++;
	}
}

void	Squad::bombEffect( int x, int y)
{
	attron(COLOR_PAIR(1));
	mvprintw(y - 2, x, "\\*|*/");
	mvprintw(y - 1, x, "*\\|/*");
	mvprintw(y, x, "--O--");
	mvprintw(y + 1, x, "*/|\\*");
	mvprintw(y + 2, x, "/*|*\\");
	attroff(COLOR_PAIR(1));
}

AEntity			*Squad::getUnit(int i) const {
	int		j = 0;

	while (j < 15)
	{
		if (this->_ent[j] != NULL && j == i)
			return this->_ent[j];
		j++;
	}
	return NULL;
}

/// FUNCTIONS ///
void		Squad::destroy(AEntity *dead, bool shot) {
	int		i = 0;

	if (dead != NULL)
	{
		while (i < 15)
		{
			if (this->_ent[i] != NULL && this->_ent[i]->getID() == dead->getID())
			{
				if (shot)
					this->_ent[i]->destroy();
				else
					delete this->_ent[i];
				this->_ent[i] = NULL;
				this->_count--;
				return ;
			}
			i++;
		}
	}
}

void		Squad::push(AEntity *add) {
	int		i = 0;
	bool	ok = true;

	if (add != NULL && this->getCount() <= 15)
	{
		while (i < 15)
		{
			if (this->_ent[i] == add)
			{
				ok = false;
				break;
			}
			i++;
		}
		if (ok)
		{
			i = 0;
			while (i < 15)
			{
				if (this->_ent[i] == NULL)
				{
					this->_ent[i] = add;
					this->_count++;
					return ;
				}
				i++;
			}
		}
	}
}

int		Squad::_score = 0;
