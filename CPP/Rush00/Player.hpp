/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:09:25 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/21 09:39:33 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

class Weapon;
# include "AEntity.hpp"
# include "Weapon.hpp"
# include "HorAmmo.hpp"


class Player: public AEntity
{

	public:

		Player( void );
		virtual ~Player( void );

		void	entMove( void ) {}
		void	destroy(void) {}

		void	playerMove( int input );

		void	display( void ) const;
		bool	playerUpdate( int x, int y );
		void	playerExplodes( void ) const;
		void	setPos( int x, int y );

		int		getY() const;
		int		getX() const;
		int		getW() const;
		int		getH() const;
		Weapon	*getWeapon( void );

	private:

		Weapon	*_weap;

};

#endif
