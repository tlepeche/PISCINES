/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MenuTop.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 19:08:25 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/21 00:32:23 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MenuTop.hpp"

MenuTop::MenuTop( void ) {}

MenuTop::MenuTop( MenuTop const &rhs ) {
	*this = rhs;
	return;
}

MenuTop::~MenuTop( void ) {
	return;
}

MenuTop	&MenuTop::operator=( MenuTop const &rhs ) {
	*this = rhs;
	return *this;
}

/// FUNCTIONS ///
void	MenuTop::display(int timer, int life, int bomb) {
	int		i = 0;
	int		x = 2;

	mvprintw(0, 171, "SCORE : %d", Squad::_score);
	mvprintw(2, 173, "TIMER");
	mvprintw(3, 175 - (timer / 3000) , "%d", timer / 30);

	mvprintw(0, 1, "PLAYER 1");
	while (i < life)
	{
		mvprintw(1, x, "|\\");
		mvprintw(2, x, "=o>");
		mvprintw(3, x, "|/");
		x += 4;
		i++;
	}
	x = 2;
	mvprintw(1, 340, "BOMB :");
	i = 0;
	while (i < bomb)
	{
		mvprintw(1, 345 + x, "*");
		x += 2;
		i++;
	}
}
