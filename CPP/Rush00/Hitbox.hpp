/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hitbox.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 05:29:18 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/21 07:23:02 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITBOX_H
# define HITBOX_H

#include "AEntity.hpp"
#include "Player.hpp"

class Hitbox
{

	public:

		Hitbox( void );
		~Hitbox( void );

		int	collision( AEntity *a, AEntity *b );
//		int	pCollision( Player *a, AEntity *b );

	private:
		
		Hitbox( Hitbox const &rhs );
		
		Hitbox	&operator=( Hitbox const &rhs );

};

#endif
