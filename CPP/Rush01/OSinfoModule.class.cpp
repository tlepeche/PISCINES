/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSinfoModule.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:33:16 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 20:21:58 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSinfoModule.class.hpp"
#include "TextNCurses.class.hpp"
#include "TextSfml.class.hpp"

OSinfoModule::OSinfoModule(void) : AMonitorModule("OSinfoModule", NULL) {
}

OSinfoModule::OSinfoModule(AWindow *win) : AMonitorModule("OSinfoModule", win) {
	if (win->getType() == "ncurses")
		this->_display = new TextNCurses(reinterpret_cast<WindowNCurses *>(win));
	else
		this->_display = new TextSfml(reinterpret_cast<WindowSfml *>(win));
}

OSinfoModule	&OSinfoModule::operator=(OSinfoModule const &rhs) {
	_display = rhs._display;
	return (*this);
}

void	OSinfoModule::acquireData(void) {
	struct utsname uts;

	uname(&uts);
	this->_data = static_cast<std::string>(uts.sysname) + " "
		+ static_cast<std::string>(uts.release) + " "
		+ static_cast<std::string>(uts.machine);
	this->_display->acquireData(this->_data);
}

void	OSinfoModule::displayRender(void) {
	this->_display->displayRender();
}
