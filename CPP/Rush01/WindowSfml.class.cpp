/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WindowSfml.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:15:55 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 18:57:37 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WindowSfml.class.hpp"

WindowSfml::WindowSfml(int x, int y, int w, int h, sf::RenderWindow *win) : AWindow(x, y, w, h, "sfml"), _win(win){
}

void		WindowSfml::init(void) {
}

void		WindowSfml::close(void) {
}

sf::RenderWindow *WindowSfml::getWin(void) const { return (_win); }
