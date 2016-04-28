/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 16:20:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 23:43:38 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Squad.hpp"

Squad::Squad() : _Mar(NULL), _Next(NULL) {}

Squad::Squad(Squad & src) {
	*this = src;
}

Squad::~Squad() {
	delete this->_Mar;
	delete this->_Next;
}

Squad	&	Squad::operator=(Squad const & rhs) {
	this->_Mar = rhs.getUnit(Squad::_Count);
	if (rhs._Next)
	{
		Squad::_Count += 1;
		this->_Next = rhs._Next;
	}
	Squad::_Count = 0;
	return *this;
}

/// GETTERS ///
int				Squad::getCount() const {
	if (this->_Next)
		return (this->_Next->getCount() + 1);
	return 0;
}

ISpaceMarine *	Squad::getUnit(int N) const {
	if (N > this->getCount() || N < 0)
		return NULL;
	else if (N == 0)
		return this->_Mar;
	else
		return this->_Next->Squad::getUnit(N-1);
}

/// FUNCTIONS ///
int	Squad::push(ISpaceMarine *New) {
	Squad::_Count = 0;
	Squad*	tmp = this;
	bool		ok = 1;

	while (tmp->_Next)
	{
		if (tmp->_Mar == New)
		{
			ok = 0;
			break;
		}		
		tmp = tmp->_Next;
	}
	if (New != NULL && ok == 1)
	{
		if (this->_Mar == NULL)
		{
			this->_Mar = New;
			this->_Next = new Squad;
		}
		else
		{
			this->_Next->push(New);
			Squad::_Count += 1;
		}
		return (Squad::_Count);
	}
	return 0;
}

int	Squad::_Count = 0;
