/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACourbeb.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:34:18 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 19:23:37 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ACourbeb.class.hpp"

ACourbeb::ACourbeb(void) : AMonitorDisplay("CourbeDisplay") {
}

void		ACourbeb::acquireData(std::list<float> data1, std::list<float> data2,
		std::list<float> data3, std::list<float> data4) {
	_data1 = data1;
	_data2 = data2;
	_data3 = data3;
	_data4 = data4;
}
