/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextSfml.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:39:25 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 12:45:37 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextSfml.class.hpp"

#include <unistd.h>

TextSfml::TextSfml(WindowSfml *win) : AText(), _win(win) {
	sf::Font		*font = new sf::Font();

	if (!(font->loadFromFile("sansation.ttf")))
		throw	(std::exception());
	_text.setFont(*font);
	_text.setCharacterSize(16);
	_text.setColor(sf::Color::White);
	_text.setStyle(sf::Text::Bold);
	_text.setPosition(win->getX(), win->getY());
	win->setY(win->getY() + 20);
}

void		TextSfml::displayRender(void) {
	_text.setString(_data);
	_win->getWin()->draw(_text);
}
