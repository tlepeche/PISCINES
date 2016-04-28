/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MenuStart.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 03:23:50 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/21 11:45:02 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MenuStart.hpp"

MenuStart::MenuStart( void ): _select( 1 )
{
	return;
}

MenuStart::MenuStart( MenuStart const &rhs )
{
	*this = rhs;
	return;
}

MenuStart::~MenuStart( void )
{
	return;
}

MenuStart	&MenuStart::operator=( MenuStart const &rhs )
{
	this->_select = rhs._select;
	return *this;
}

void	MenuStart::display( void )
{

	int w = (364 / 2) - 50;
	int h = (84 / 2) - 10;
	mvprintw(h + 0, w, " _______ .___________.     .______       _______ .___________..______        ______    ");
	mvprintw(h + 1, w, "|   ____||           |     |   _  \\     |   ____||           ||   _  \\      /  __  \\  ");
	mvprintw(h + 2, w, "|  |__   `---|  |----`     |  |_)  |    |  |__   `---|  |----`|  |_)  |    |  |  |  | ");
	mvprintw(h + 3, w, "|   __|      |  |          |      /     |   __|      |  |     |      /     |  |  |  | ");
	mvprintw(h + 4, w, "|  |         |  |          |  |\\  \\----.|  |____     |  |     |  |\\  \\----.|  `--'  | ");
	mvprintw(h + 5, w, "|__|         |__|     _____| _| `._____||_______|    |__|     | _| `._____| \\______/  ");
	mvprintw(h + 6, w, "                     |______|                                                         ");

	mvprintw(50, 160, "Play");
	mvprintw(51, 160, "Quit");
	if (this->_select == 1)
		mvprintw(50, 158, "#");
	else
		mvprintw(51, 158, "#");
}

int MenuStart::mainLoop( void )
{
	nodelay(stdscr, false);
	while (42)
	{
		int ch = 0;

		clear();
		this->display();
		refresh();
		ch = getch();
		if (ch == KEY_UP)
			this->_select = 1;
		else if (ch ==  KEY_DOWN)
			this->_select = 0;
		else if (ch == ' ')
			return this->_select;
		else if (ch == 'q')
			return 0;
	}
	return 0;
}
