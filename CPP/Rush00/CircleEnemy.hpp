/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CircleEnemy.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:31:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 05:44:37 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLEENEMY_HPP
#define CIRCLEENEMY_HPP

#include "AEntity.hpp"

class	CircleEnemy : public AEntity
{
	public:
		CircleEnemy(int x, int y, int w, int h);
		virtual ~CircleEnemy();

		CircleEnemy &		operator=(CircleEnemy const & rhs);
		virtual void	entMove(void);
		virtual void	display(void) const;
		virtual void	destroy(void);

	private:
		CircleEnemy(CircleEnemy & src);
		CircleEnemy();
		int			_initX;
		int			_initY;
		static int	_way;
		static bool	_turn;
};

#endif
