/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextNCurses.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:37:46 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 19:25:58 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTNCURSE_CLASS_HPP
#define TEXTNCURSE_CLASS_HPP

#include "AText.class.hpp"
#include "WindowNCurses.class.hpp"

class	TextNCurses : public AText
{
	private:
	protected:
		WindowNCurses			*_win;

	public:
		TextNCurses(WindowNCurses *win);
		void		displayRender(void);
};

#endif
