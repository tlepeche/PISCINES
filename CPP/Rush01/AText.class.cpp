/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AText.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:34:18 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 16:41:41 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AText.class.hpp"

AText::AText(void) : AMonitorDisplay("TextDisplay") {
}

void		AText::acquireData(std::string data) { _data = data; }
