/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 14:53:49 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 16:08:27 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"
#include <sstream>

Brain::Brain(void) {
}

Brain::~Brain(void) {
}

std::string Brain::identify(void) {
	std::stringstream address;
	address << this;
	address >> this->_Address;
	return this->_Address;
}
