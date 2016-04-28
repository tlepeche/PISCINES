/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 14:54:19 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 16:08:25 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <iostream>

Human::Human(void) { 
}

Human::~Human(void) {
}

std::string Human::identify(void) {
	return this->_Mybrain.identify();
}

Brain &Human::getBrain(void) {
	return this->_Mybrain;
}
