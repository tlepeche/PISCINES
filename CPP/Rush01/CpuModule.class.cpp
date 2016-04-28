/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:33:16 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 20:45:32 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CpuModule.class.hpp"
#include "TextNCurses.class.hpp"
#include "TextSfml.class.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <mach/mach.h>
#include <stdint.h>
#include <cstdio>
#include <unistd.h>
#include <stdio.h>
#include <sstream>

CpuModule::CpuModule(void) : AMonitorModule("CpuModule", NULL) {
}

CpuModule::CpuModule(AWindow *win) : AMonitorModule("CpuModule", win) {
	yolo1 = new CpuUsage(0);
	yolo2 = new CpuUsage(1);
	yolo3 = new CpuUsage(2);
	yolo4 = new CpuUsage(3);

	if (win->getType() == "ncurses")
	{
		this->_nameDisplay = new TextNCurses(reinterpret_cast<WindowNCurses *>(win));
		this->_display = new CourbebNCurses(reinterpret_cast<WindowNCurses *>(win));
	}
	else
	{
		this->_nameDisplay = new TextSfml(reinterpret_cast<WindowSfml *>(win));
		this->_display = new CourbeSfmlb(reinterpret_cast<WindowSfml *>(win));
	}
}

CpuModule	&CpuModule::operator=(CpuModule const &rhs) {
	_display = rhs._display;
	return (*this);
}

void	CpuModule::acquireData(void) {
	uint64_t nbCores = 0;
	char *name = new char[100];
	size_t size = sizeof(nbCores);
	size_t size2 = 100; 
	int lenght = 60;
	std::stringstream ss;

	if (sysctlbyname("machdep.cpu.brand_string", name, &size2, NULL, 0) < 0)
		perror("sysctl");
	if (sysctlbyname("machdep.cpu.core_count", &nbCores, &size, NULL, 0) < 0)
		perror("sysctl");

	this->_core1.push_front(yolo1->get());
	this->_core2.push_front(yolo2->get());
	this->_core3.push_front(yolo3->get());
	this->_core4.push_front(yolo4->get());
	ss << name << " " << nbCores << " cores." << std::endl;
	this->_name =  ss.str();

	if (_core1.size() > static_cast<unsigned int>(lenght))
	{
		_core1.pop_back();
		_core2.pop_back();
		_core3.pop_back();
		_core4.pop_back();
	}
	this->_display->acquireData(this->_core1, this->_core2, this->_core3, this->_core4);
	this->_nameDisplay->acquireData(this->_name);
}

void	CpuModule::displayRender(void) {
	this->_nameDisplay->displayRender();
	this->_display->displayRender();
}
