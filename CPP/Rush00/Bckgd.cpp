/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bckgd.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:38:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 02:13:28 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bckgd.hpp"

Bckgd::Bckgd() {}

Bckgd::Bckgd(Bckgd & src) { (void)src ;}

Bckgd::Bckgd(int x, int y) :  _Len(x), _Ymax(y) {
	int	start = 1;

	this->_Tab = new int[this->_Len];
	this->_Tab[0] = this->_Ymax / 2;
	while (start <= this->_Len - 1)
	{
		this->_Tab[start] = this->_Tab[start - 1] + (std::rand() % 3) - 1;
		if (this->_Tab[start] >= this->getY())
			this->_Tab[start] = this->getY();	
		if (this->_Tab[start] < 0)
			this->_Tab[start] = 0;
		start++;
	}
}

Bckgd::~Bckgd() {
}

Bckgd &	Bckgd::operator=(Bckgd const & rhs) {
	////TOTALEMENT FAUX (MAIS NON UTILISEE) ////
	this->_Len = rhs.getLen();
	return *this;
}

/// FUNCTIONS ///
void	Bckgd::refresh(void) {
	int	start = 0;

	while (start < this->getLen() - 1)
	{
		this->_Tab[start] = this->_Tab[start + 1];
		if (this->_Tab[start] >= this->getY())
			this->_Tab[start] = this->getY();	
		start++;
	}
	this->_Tab[start] = this->_Tab[start - 1] + (std::rand() % 3) - 1;
	if (this->_Tab[start] >= this->getY())
		this->_Tab[start] = this->getY();	
	if (this->_Tab[start] < 0)
		this->_Tab[start] = 0;
}

/// GETTERS ///
int		Bckgd::getTab(int i) const { return this->_Tab[i]; }
int		Bckgd::getLen() const { return this->_Len; }
int		Bckgd::getY() const { return this->_Ymax; }
