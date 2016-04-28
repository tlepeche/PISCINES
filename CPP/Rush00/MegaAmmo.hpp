/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaAmmo.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:31:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 10:48:32 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAAMMO_HPP
#define MEGAAMMO_HPP

#include "AEntity.hpp"

class	MegaAmmo : public AEntity
{
	public:
		MegaAmmo(int x, int y);
		virtual ~MegaAmmo();

		MegaAmmo &		operator=(MegaAmmo const & rhs);
		virtual void	entMove(void);
		virtual void	display(void) const;
		virtual void	destroy(void);

		virtual int	getY() const;

	private:
		MegaAmmo(MegaAmmo & src);
		MegaAmmo();
};

#endif
