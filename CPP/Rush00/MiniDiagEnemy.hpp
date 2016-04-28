/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniDiagEnemy.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:31:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 08:23:26 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIDIAGENEMY_HPP
#define MINIDIAGENEMY_HPP

#include "AEntity.hpp"

class	MiniDiagEnemy : public AEntity
{
	public:
		MiniDiagEnemy(int x, int y, int w, int h);
		virtual ~MiniDiagEnemy();

		MiniDiagEnemy &		operator=(MiniDiagEnemy const & rhs);
		virtual void	entMove(void);
		virtual void	display(void) const;
		virtual void	destroy(void);

	private:
		MiniDiagEnemy(MiniDiagEnemy & src);
		MiniDiagEnemy();
		int		_yMin;
		int		_yMax;
};

#endif
