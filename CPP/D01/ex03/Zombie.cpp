/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 11:41:37 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 14:47:31 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void) {
	std::cout << "Zombie constructed" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_type << " " << this->_name << " destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}

void	Zombie::init(std::string name, std::string type) {
	this->_name = name;
	this->_type = type;
}
