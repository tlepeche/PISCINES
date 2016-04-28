/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 14:08:21 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/21 11:02:05 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define WIDTH 364
# define HEIGHT 84

# include <iostream>

# include "ncurses.h"
# include "Player.hpp"
# include "MenuTop.hpp"
# include "MenuStart.hpp"
# include "Bckgd.hpp"
# include "HorEnemy.hpp"
# include "ShootEnemy.hpp"
# include "DiagEnemy.hpp"
# include "MiniDiagEnemy.hpp"
# include "CircleEnemy.hpp"
# include "Boss.hpp"

class Game
{

	public:

		Game( void );
		~Game( void );

		void	startCurses( void );
		void	endCurses( void );

		void	mainLoop(void);
		Player	*getPlayer( void ) const;
		void	displayMenu( void ) const;
		void	displayMessage( int n );
		void	enemySpawn(int time);
		void	displayBckgd( void );
		int		getLife(void) const;
		int		getBomb(void) const;

		void	setLife(int	val);
		void	setBomb(int val);
		static int	_boss;
	private:

		Game( Game const &rhs );
		Game	&operator=( Game const &rhs );
		bool	_curses_started;
		Player	*_p;
		MenuTop *_men;
		Bckgd	*_top;
		Bckgd	*_bot;
		Squad	*_sq;
		bool	_go;
		int		_timer;
		int		_life;
		int		_bomb;


};

#endif
