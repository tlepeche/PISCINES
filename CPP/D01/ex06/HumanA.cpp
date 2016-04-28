/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:18:02 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 16:50:35 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weap) : _Name(name), _W(weap) {
}

HumanA::~HumanA(void) {
}

void	HumanA::attack(void) {
	std::cout << this->_Name << " attacks with his " << this->_W.getType() << std::endl;
}
