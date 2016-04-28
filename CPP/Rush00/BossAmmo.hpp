/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BossAmmo.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:31:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 08:45:51 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSSAMMO_HPP
#define BOSSAMMO_HPP

#include "AEntity.hpp"

class	BossAmmo : public AEntity
{
	public:
		BossAmmo(int x, int y);
		virtual ~BossAmmo();

		BossAmmo &		operator=(BossAmmo const & rhs);
		virtual void	entMove(void);
		virtual void	display(void) const;
		virtual void	destroy(void);

		virtual int	getY() const;

	private:
		BossAmmo(BossAmmo & src);
		BossAmmo();
};

#endif
