/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 16:20:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 11:00:17 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "Hitbox.hpp"
#include <ncurses.h>

Weapon::Weapon() : _count(0), _mf(20) {
	this->_mf =20;
	int i = 0;
	while (i < this->_mf)
	{
		this->_ent[i] = NULL;
		i++;
	}
}

Weapon::Weapon(Weapon & src) {
	*this = src;
}

Weapon::~Weapon() {}

Weapon	&	Weapon::operator=(Weapon const & rhs) {
	this->_count = rhs.getCount();
	return *this;
}

/// GETTERS ///
int				Weapon::getCount() const { return this->_count; }

int				Weapon::checkEnemy( Squad &sq )
{
	int j = 0;
	while (j < this->_mf)
	{
		if (this->getAmmo(j) != NULL)
		{
			int	i = 0;
			while (i < 15)
			{
				AEntity	*e = sq.getUnit(i);
				if (e != NULL)
				{
					Hitbox	hb;
					if (hb.collision(this->getAmmo(j), e) == 1)
					{
						e->takeDamage(1);
						if (e->getHP() == 0)
						{
							this->destroy(this->getAmmo(j));
							sq.destroy(e, true);
							sq.bombEffect(e->getX(), e->getY());
						}
						return 1;
					}
				}
				i++;
			}
		}
		j++;
	}
	return 0;
}

int				Weapon::checkHit( AEntity *e) {
	int j = 0;

	while (j < this->_mf)
	{
		if (this->getAmmo(j) != NULL)
		{
			Hitbox	hb;
			if (hb.collision(this->getAmmo(j), e) == 1)
				return 1;
		}
		j++;
	}
	return 0;
}

AEntity			*Weapon::getAmmo(int i) const {
	int		j = 0;

	while (j < this->_mf)
	{
		if (this->_ent[j] != NULL && j == i)
			return this->_ent[j];
		j++;
	}
	return NULL;
}

/// FUNCTIONS ///
void		Weapon::destroy(AEntity *dead) {
	int		i = 0;

	if (dead != NULL)
	{
		while (i < this->_mf)
		{
			if (this->_ent[i] != NULL && this->_ent[i]->getID() == dead->getID())
			{
				delete this->_ent[i];
				this->_ent[i] = NULL;
				this->_count--;
				return ;
			}
			i++;
		}
	}
}

void		Weapon::display( void )
{
	int i = 0;
	while (i < this->_mf)
	{
		if (this->getAmmo(i) != NULL)
		{
			this->getAmmo(i)->display();
			this->getAmmo(i)->entMove();
			if (this->getAmmo(i)->getX() > 360 || this->getAmmo(i)->getX() <= 0)
				this->destroy(this->getAmmo(i));
		}
		i++;
	}
}

void		Weapon::push(AEntity *add) {
	int		i = 0;
	bool	ok = true;

	if (add != NULL && this->getCount() <= this->_mf)
	{
		while (i < this->_mf)
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
			while (i < this->_mf)
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
