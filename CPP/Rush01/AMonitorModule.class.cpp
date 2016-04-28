/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorModule.class.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:11:45 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 16:22:51 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMonitorModule.class.hpp"

AMonitorModule::~AMonitorModule(void) {
}

AMonitorModule::AMonitorModule(std::string name, AWindow *win) : _name(name), _win(win) {

}

/*
AMonitorModule::AMonitorModule(AMonitorModule const &rhs) {
	*this = rhs;
}
*/
bool			AMonitorModule::isDie(void) { return (_die); }
