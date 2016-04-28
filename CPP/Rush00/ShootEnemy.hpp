/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShootEnemy.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:31:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 10:27:25 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOTENEMY_HPP
#define SHOOTENEMY_HPP

#include "AEntity.hpp"
#include "Weapon.hpp"
#include "BossAmmo.hpp"

class	ShootEnemy : public AEntity
{
	public:
		ShootEnemy(int x, int y, int w, int h);
		virtual ~ShootEnemy();

		ShootEnemy &		operator=(ShootEnemy const & rhs);
		virtual void	entMove(void);
		virtual void	display(void) const;
		virtual void	destroy(void);
		virtual	Weapon	*getWeap(void) const;
		virtual void	shoot(void);

	private:
		ShootEnemy(ShootEnemy & src);
		ShootEnemy();
		int		_yMin;
		int		_yMax;
		Weapon *_weap;
};

#endif
