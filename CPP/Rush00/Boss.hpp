/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:31:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 10:49:07 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_HPP
#define BOSS_HPP

#include "AEntity.hpp"
#include "Weapon.hpp"
#include "MegaAmmo.hpp"

class	Boss : public AEntity
{
	public:
		Boss(int x, int y, int w, int h);
		virtual ~Boss();

		Boss &		operator=(Boss const & rhs);
		virtual void	entMove(void);
		virtual void	display(void) const;
		virtual void	destroy(void);
		virtual Weapon	*getWeap(void) const;
		virtual void	shoot(void);

	private:
		Boss(Boss & src);
		Boss();
		int	_way;
		Weapon	*_weap;
};

#endif
