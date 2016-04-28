/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WindowSfml.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:13:35 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 18:56:02 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOWSFML_CLASS_HPP
#define WINDOWSFML_CLASS_HPP

# include "AWindow.class.hpp"
# include <SFML/Graphics.hpp>

class WindowSfml : public AWindow
{
	private:
	protected:
		sf::RenderWindow	*_win;
	public:
		WindowSfml(int x, int y, int w, int h, sf::RenderWindow *win);

		void		init(void);
		void		close(void);

		sf::RenderWindow	*getWin(void) const;
};

#endif
