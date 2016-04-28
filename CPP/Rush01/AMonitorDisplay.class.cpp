/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorDisplay.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:27:51 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 20:18:23 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMonitorDisplay.class.hpp"

AMonitorDisplay::AMonitorDisplay(void) {}

AMonitorDisplay::AMonitorDisplay(std::string name) : _name(name) {}

AMonitorDisplay::~AMonitorDisplay(void) {}

AMonitorDisplay::AMonitorDisplay(AMonitorDisplay const &rhs) {
	*this = rhs;
}

AMonitorDisplay &AMonitorDisplay::operator=(AMonitorDisplay const &rhs) {
	this->_name = rhs.getName();
	return (*this);
}

std::string			AMonitorDisplay::getName(void) const { return (_name); }
