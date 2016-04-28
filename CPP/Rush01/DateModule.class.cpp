/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:33:16 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 20:21:08 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateModule.class.hpp"
#include "TextNCurses.class.hpp"
#include "TextSfml.class.hpp"

DateModule::DateModule(void) : AMonitorModule("DateModule", NULL) {
}

DateModule::DateModule(AWindow *win) : AMonitorModule("DateModule", win) {
	if (win->getType() == "ncurses")
		this->_display = new TextNCurses(reinterpret_cast<WindowNCurses *>(win));
	else
		this->_display = new TextSfml(reinterpret_cast<WindowSfml *>(win));
}

DateModule	&DateModule::operator=(DateModule const &rhs) {
	this->_display = rhs._display;
	return (*this);
}

void	DateModule::acquireData(void) {
	std::time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct	std::tm *time = std::localtime(&tt);
	std::stringstream ss;

	ss << std::put_time(time, "%c");
	this->_data = ss.str();
	this->_display->acquireData(this->_data);
}

void	DateModule::displayRender(void) {
	this->_display->displayRender();
}
