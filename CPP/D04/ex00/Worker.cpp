/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 10:38:26 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 12:12:42 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Worker.hpp"

Worker::Worker(void) {
	std::cout << "I dont do this" << std::endl;
}

Worker::Worker(std::string name) : Victim(name) {
	std::cout << "Yes milord?" << std::endl;
}

Worker::Worker(Worker & src) {
	*this = src;
	std::cout << "Clone created" << std::endl;
}

Worker::~Worker(void) {
	std::cout << "Yaaah..." << std::endl;
}

Worker &	Worker::operator=(Worker const & rhs) {
	this->setName(rhs.getName());
	return *this;
}

///// FUNCTIONS /////
void	Worker::getPolymorphed(void) const {
	std::cout << this->getName() << " has been turned into a pig!" << std::endl;
}
