/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WindowNCurses.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:31:51 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/27 18:42:33 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WindowNCurses.class.hpp"

# include <ncurses.h>

WindowNCurses::WindowNCurses( int x, int y, int w, int h ):
	AWindow( x, y, w, h, "ncurses" )
{
	return;
}

void	WindowNCurses::init( void )
{
	return;
}

void	WindowNCurses::close( void )
{
	return;
}

/*
WINDOW	*WindowNCurses::getWindow( void ) const
{
	return this->_win;
}
*/
