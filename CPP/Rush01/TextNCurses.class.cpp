/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextNCurses.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:39:25 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 12:25:52 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TextNCurses.class.hpp"
#include <iostream>

TextNCurses::TextNCurses(WindowNCurses *win) : AText(), _win(win) {

}

void		TextNCurses::displayRender(void) {
	int len = this->_data.length() + 4;


	int ox = 0;
	int	oy = getcury( stdscr );
	int h = 5 + oy;
	mvprintw( oy + 2, ox + 2, this->_data.c_str() );
	
	int x, y, i;
	x = len;
	y = h;
	mvprintw(oy, ox, "+");
	mvprintw(y - 1, ox, "+");
	mvprintw(oy, x - 1, "+");
	mvprintw(y - 1, x - 1, "+");

	for ( i = ox + 1; i < (x - 1); i++) {
		mvprintw(oy, i, "-");
		mvprintw(h - 1, i, "-");
	}
	for (i = oy + 1; i < (h - 1); i++) {
		mvprintw(i, ox, "|");
		mvprintw(i, len - 1, "|");
	}
	move(h, 0);
}
