/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 15:05:04 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 09:53:28 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

class AEntity;
#include "AEntity.hpp"
#include "Squad.hpp"

class Weapon
{
	public:
		Weapon();
		Weapon(Weapon & src);
		virtual ~Weapon();

		virtual int		 	getCount(void) const;
		virtual AEntity		*getAmmo(int i) const;

		void				display( void );
		virtual void		push(AEntity *add);
		virtual void		destroy(AEntity *dead);
		int					checkEnemy( Squad &sq );
		int					checkHit( AEntity *p );

		static int			_score;

	private:
		Weapon &	operator=(Weapon const &);
		AEntity 			*_ent[20];
		int					_count;
		int					_mf;
};

#endif
