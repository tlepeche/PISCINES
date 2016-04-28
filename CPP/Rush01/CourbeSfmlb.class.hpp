/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourbeSfmlb.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:37:46 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 18:24:24 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COURBESFML_CLASS_HPP
#define COURBESFML_CLASS_HPP

#include "ACourbeb.class.hpp"
#include "WindowSfml.class.hpp"

class	CourbeSfmlb : public ACourbeb
{
	private:
	protected:
		WindowSfml			*_win;
		float					_max;

	public:
		CourbeSfmlb(WindowSfml *win);
		void		displayRender(void);
};

#endif
