/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 14:12:02 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/21 02:13:19 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include "Game.hpp"

#include "HorEnemy.hpp"
#include "Squad.hpp"
#include "Bckgd.hpp"

int		main( void )
{

	Game	game;

	std::srand(time(0));	

	game.mainLoop();

	game.endCurses();
	return 0;
}
