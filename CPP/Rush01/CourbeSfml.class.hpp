/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourbeSfml.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:37:46 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 11:55:37 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COURBESFML_CLASS_HPP
#define COURBESFML_CLASS_HPP

#include "ACourbe.class.hpp"
#include "WindowSfml.class.hpp"

class	CourbeSfml : public ACourbe
{
	private:
	protected:
		WindowSfml			*_win;
		float					_max;

	public:
		CourbeSfml(WindowSfml *win);
		void		displayRender(void);
};

#endif
