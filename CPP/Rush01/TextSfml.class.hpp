/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextSfml.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:37:46 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 19:51:45 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTSFML_CLASS_HPP
#define TEXTSFML_CLASS_HPP

#include "AText.class.hpp"
#include "WindowSfml.class.hpp"

class	TextSfml : public AText
{
	private:
	protected:
		WindowSfml			*_win;
		sf::Text			_text;

	public:
		TextSfml(WindowSfml *win);
		void		displayRender(void);
};

#endif
