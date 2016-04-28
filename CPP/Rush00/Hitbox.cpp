/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hitbox.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 05:32:08 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/21 09:54:20 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hitbox.hpp"

Hitbox::Hitbox( void )
{
	return;
}

Hitbox::Hitbox( Hitbox const &rhs )
{
	*this = rhs;
	return;
}

Hitbox::~Hitbox( void )
{
	return;
}

Hitbox	&Hitbox::operator=( Hitbox const &rhs )
{
	*this = rhs;
	return *this;
}

int	Hitbox::collision( AEntity *a, AEntity *b )
{

	int ax = a->getX();
	int ay = a->getY();
	int aw = a->getW();
	int ah = a->getH();

	int bx = b->getX();
	int by = b->getY();
	int bw = b->getW();
	int bh = b->getH();

	if (ax < bx + bw &&	ax + aw > bx &&	ay < by + bh &&	ah + ay > by)
		return 1;
	return 0;
}
