/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourbeNCurses.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 11:44:21 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/28 20:40:05 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CourbeNCurses.class.hpp"

CourbeNCurses::CourbeNCurses( WindowNCurses *win ): ACourbe(), _win( win ) {
}

#define  HAUTEUR 10

void	CourbeNCurses::displayRender( void )
{
	int ox = 0;
	int oy = getcury( stdscr );
	int h = 2 + oy + HAUTEUR;

	if (_win->getX() == 0) // NOOOOOOOOOO
		ox = 0;

	std::list< float >::iterator	it;
	std::list< float >::iterator	ite;
	it = this->_data.begin();
	ite = this->_data.end();

	int vmin = static_cast< int >(*it);
	ite--;
	int vmax = static_cast< int >(*ite);
	ite++;

	std::string	info;
	if ( *(this->_data2.begin()) != 8192 ) // PLIZ NOOOOOooo
	{
		info = std::to_string(vmin)
			+ " / " + std::to_string(vmax);
	}
	else
	{
		info = std::to_string(vmin)
			+ " / 8192";
	}


	float max = *(std::max_element(it, ite));

	int w = 0;
	while ( it != ite )
	{
		int val = static_cast< int >((HAUTEUR - ( *it / max ) * HAUTEUR));
		int g = val + oy;
			int c;
			if ( val >  HAUTEUR * 0.75)
			{c = 1;}
			else if ( val >  HAUTEUR * 0.25)
			{c = 2;}
			else
			{c = 3;}
		while ( g < h )
		{
			attron(COLOR_PAIR(c));
			mvprintw( g, w, "#" );
			attroff(COLOR_PAIR(c));
			g++;
		}
		w++;
		it++;
	}

	mvprintw( oy + 1, ox + 1, info.c_str());
	int x, y, i;
	x = 60;
	int len = x;
	y = h;
	mvprintw(oy, ox, "+");
	mvprintw(y - 1, ox, "+");
	mvprintw(oy, x - 1, "+");
	mvprintw(y - 1, x - 1, "+");
	for (i = ox + 1; i < ( x - 1); i++) {
		mvprintw(oy, i, "-");
		mvprintw(h - 1, i, "-");
	}
	for (i = oy + 1; i < ( h - 1); i++) {
		mvprintw(i, ox, "|");
		mvprintw(i, len - 1, "|");
	}
	move(h, 0);
	if ( *(this->_data2.begin()) != 8192 ) // PLIZ NOOOOOooo
	{
		move(h - 1, 0);
		this->displayRender2();
	}
}

void	CourbeNCurses::displayRender2( void )
{
	int ox = 0;
	int oy = getcury( stdscr );
	int h = 2 + oy + HAUTEUR;

	std::list< float >::iterator	it;
	std::list< float >::iterator	ite;
	it = this->_data2.begin();
	ite = this->_data2.end();

	int vmin = static_cast< int >(*it);
	ite--;
	int vmax = static_cast< int >(*ite);
	ite++;

	std::string	info = std::to_string(vmin)
		+ " / " + std::to_string(vmax);
	float max = *(std::max_element(it, ite));

	int w = 0;
	while ( it != ite )
	{
		int val = static_cast< int >((HAUTEUR - ( *it / max ) * HAUTEUR));	
		int g = val + oy;
			int c;
		if (g < 0)
			break ;
			if ( val >  HAUTEUR * 0.75)
			{	c = 1;}
			else if ( val >  HAUTEUR * 0.25)
			{c = 2;}
			else
			{	c = 3;}
		while ( g < h )
		{
			attron(COLOR_PAIR(c));
			mvprintw( g, w, "#" );
			attroff(COLOR_PAIR(c));
			g++;
		}
		w++;
		it++;
	}
	mvprintw( oy + 1, ox + 1, info.c_str());

	int x, y, i;
	x = 60;
	int len = x;
	y = h;
	mvprintw(oy, ox, "+");
	mvprintw(y - 1, ox, "+");
	mvprintw(oy, x - 1, "+");
	mvprintw(y - 1, x - 1, "+");
	for (i = ox + 1; i < ( x - 1); i++) {
		mvprintw(oy, i, "-");
		mvprintw(h - 1, i, "-");
	}
	for (i = oy + 1; i < ( h - 1); i++) {
		mvprintw(i, ox, "|");
		mvprintw(i, len - 1, "|");
	}
	move(h , 0);

}
