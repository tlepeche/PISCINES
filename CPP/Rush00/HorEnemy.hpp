/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HorEnemy.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:31:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 05:40:55 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HORENEMY_HPP
#define HORENEMY_HPP

#include "AEntity.hpp"

class	HorEnemy : public AEntity
{
	public:
		HorEnemy(int x, int y, int w, int h);
		virtual ~HorEnemy();

		HorEnemy &		operator=(HorEnemy const & rhs);
		virtual void	entMove(void);
		virtual void	display(void) const;
		virtual void	destroy(void);

	private:
		HorEnemy(HorEnemy & src);
		HorEnemy();
};

#endif
