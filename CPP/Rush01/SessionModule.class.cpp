/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SessionModule.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:33:16 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 20:22:52 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SessionModule.class.hpp"
#include "TextNcurses.class.hpp"
#include "TextSfml.class.hpp"

SessionModule::SessionModule(void) : AMonitorModule("SessionModule", NULL) {
}

SessionModule::SessionModule(AWindow *win) : AMonitorModule("SessionModule", win) {
	if (win->getType() == "ncurses")
		this->_display = new TextNCurses(reinterpret_cast<WindowNCurses *>(win));
	else
		this->_display = new TextSfml(reinterpret_cast<WindowSfml *>(win));
}

SessionModule	&SessionModule::operator=(SessionModule const &rhs) {
	_display = rhs._display;
	return (*this);
}

void	SessionModule::acquireData(void) {
	char	host[128];

	gethostname(host, 128);
	this->_data = static_cast<std::string>(getenv("USER")) + " " + host;
	this->_display->acquireData(this->_data);
}

void	SessionModule::displayRender(void) {
	this->_display->displayRender();
}
