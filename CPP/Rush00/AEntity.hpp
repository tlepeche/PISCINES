/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:31:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 10:39:34 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
#define AENTITY_HPP

class Weapon;
class Squad;
#include <ncurses.h>
#include "Weapon.hpp"

class	AEntity
{
	public:
		AEntity();
		AEntity(int hp, int x, int y, int w, int h);
		AEntity(AEntity & src);
		virtual ~AEntity();

		AEntity &		operator=(AEntity const & rhs);
		virtual void	entMove(void) = 0;
		virtual void	display(void) const = 0;
		virtual void	destroy(void) = 0;
		void			takeDamage(int amount);
		virtual void	shoot(void) {}

		int				getID() const;
		int				getHP() const;
		int				getX() const;
		int				getY() const;
		int				getW() const;
		int				getH() const;
		bool			getBoss()  const;
		virtual Weapon *		getWeap(void) const;

	protected:
		int			_id;
		int			_hp;
		int			_x;
		int			_y;
		int			_w;
		int			_h;
		static int	_built;
		bool		_boss;
};

#endif
