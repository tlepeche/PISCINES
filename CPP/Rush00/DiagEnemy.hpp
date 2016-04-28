/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiagEnemy.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:31:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 05:44:13 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAGENEMY_HPP
#define DIAGENEMY_HPP

#include "AEntity.hpp"

class	DiagEnemy : public AEntity
{
	public:
		DiagEnemy(int x, int y, int w, int h);
		virtual ~DiagEnemy();

		DiagEnemy &		operator=(DiagEnemy const & rhs);
		virtual void	entMove(void);
		virtual void	display(void) const;
		virtual void	destroy(void);

	private:
		DiagEnemy(DiagEnemy & src);
		DiagEnemy();
		int		_yMin;
		int		_yMax;
		bool	_way;
};

#endif
