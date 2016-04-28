/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HorAmmo.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:31:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 07:45:51 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HORAMMO_HPP
#define HORAMMO_HPP

#include "AEntity.hpp"

class	HorAmmo : public AEntity
{
	public:
		HorAmmo(int x, int y);
		virtual ~HorAmmo();

		HorAmmo &		operator=(HorAmmo const & rhs);
		virtual void	entMove(void);
		virtual void	display(void) const;
		virtual void	destroy(void);

		virtual int	getY() const;

	private:
		HorAmmo(HorAmmo & src);
		HorAmmo();
};

#endif
