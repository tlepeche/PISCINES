/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 11:04:12 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 11:25:37 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string name) : _name(name) 
{
	std::cout << "Pony " << this->_name << " created" << std::endl;
}

Pony::~Pony(void)
{
	std::cout << "Pony " << this->_name << " destroyed" << std::endl;
}

void	Pony::Dostuff(void)
{
	std::cout << this->_name << " do stuff." << std::endl;
}
