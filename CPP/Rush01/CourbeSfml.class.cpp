/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourbeSfml.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:39:25 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 18:07:58 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "CourbeSfml.class.hpp"

#include <unistd.h>

CourbeSfml::CourbeSfml(WindowSfml *win) : ACourbe(), _win(win), _max(0.0) {
	_y = win->getY();
	win->setY(_y + 50);
}

void		CourbeSfml::displayRender(void) {
	{
		sf::RectangleShape rectangle(sf::Vector2f(_win->getW(), 50));
		rectangle.setFillColor(sf::Color(40, 40, 40));
		rectangle.setPosition(0, _y);
		_win->getWin()->draw(rectangle);
	}
	{
		std::list<float>::iterator	it = _data.begin();
		std::list<float>::iterator	ite = _data.end();
		float						max = *(std::max_element(it, ite));
		sf::Vector2f				va;
		sf::Vector2f				vb;

		max = std::max(max, *(std::max_element(_data2.begin(), _data2.end())));
		if (max > _max * 1.25 || max < _max * 0.75)
			_max = max;


		va.x = 0;
		va.y = ( 50 - (*it / _max * 0.85) * 50) + _y;
		++it;

		while (it != ite)
		{
			vb.x += _win->getW() / 60;
			vb.y = ( 50 - (*it / _max * 0.85) * 50) + _y;
			sf::Vertex line[] =
			{
				sf::Vertex(va, sf::Color(90, 250, 60)),
				sf::Vertex(vb, sf::Color(90, 250, 60)),
			};
			va = vb;
			_win->getWin()->draw(line, 2, sf::Lines);
			++it;
		}
	}
	{
		std::list<float>::iterator	it = _data2.begin();
		std::list<float>::iterator	ite = _data2.end();
		sf::Vector2f				va;
		sf::Vector2f				vb;


		va.x = 0;
		va.y = ( 50 - (*it / _max * 0.85) * 50) + _y;
		++it;

		while (it != ite)
		{
			vb.x += _win->getW() / 60;
			vb.y = ( 50 - (*it / _max * 0.85) * 50) + _y;
			sf::Vertex line[] =
			{
				sf::Vertex(va, sf::Color(60, 60, 180)),
				sf::Vertex(vb, sf::Color(60, 60, 180)),
			};
			va = vb;
			_win->getWin()->draw(line, 2, sf::Lines);
			++it;
		}
	}
}
