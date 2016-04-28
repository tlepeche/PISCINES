/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACourbe.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:34:18 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 12:06:08 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ACourbe.class.hpp"

ACourbe::ACourbe(void) : AMonitorDisplay("CourbeDisplay") {
}

void		ACourbe::acquireData(std::list<float> data, std::list<float> data2) {
	_data = data;
	_data2 = data2;
}
