/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourbeSfmlb.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:39:25 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 20:30:04 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "CourbeSfmlb.class.hpp"

#include <unistd.h>

CourbeSfmlb::CourbeSfmlb(WindowSfml *win) : ACourbeb(), _win(win), _max(0.0) {
	_y = win->getY();
	win->setY(_y + 55);
}

void		CourbeSfmlb::displayRender(void) {
	{
		sf::RectangleShape rectangle(sf::Vector2f(_win->getW(), 50));
		rectangle.setFillColor(sf::Color(40, 40, 40));
		rectangle.setPosition(0, _y);
		_win->getWin()->draw(rectangle);
	}
	{
		std::list<float>::iterator	it = _data1.begin();
		std::list<float>::iterator	ite = _data1.end();
		float						max = *(std::max_element(it, ite));
		sf::Vector2f				va;
		sf::Vector2f				vb;


		max = std::max(max, *(std::max_element(_data2.begin(), _data2.end())));
		max = std::max(max, *(std::max_element(_data3.begin(), _data3.end())));
		max = std::max(max, *(std::max_element(_data4.begin(), _data4.end())));
		if (max > _max * 1.25 || max < _max * 0.75)
			_max = 100;
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
		std::list<float>::iterator	it = _data3.begin();
		std::list<float>::iterator	ite = _data3.end();
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
				sf::Vertex(va, sf::Color(30, 10, 200)),
				sf::Vertex(vb, sf::Color(30, 10, 200)),
			};
			va = vb;
			_win->getWin()->draw(line, 2, sf::Lines);
			++it;
		}
	}
	{
		std::list<float>::iterator	it = _data4.begin();
		std::list<float>::iterator	ite = _data4.end();
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
				sf::Vertex(va, sf::Color(180, 40, 30)),
				sf::Vertex(vb, sf::Color(180, 40, 30)),
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
				sf::Vertex(va, sf::Color(180, 30, 180)),
				sf::Vertex(vb, sf::Color(180, 30, 180)),
			};
			va = vb;
			_win->getWin()->draw(line, 2, sf::Lines);
			++it;
		}
	}
}
