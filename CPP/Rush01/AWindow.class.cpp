/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWindow.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:13:29 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/27 18:28:55 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWindow.class.hpp"

// ############################## CTOR // DTOR #################################

AWindow::AWindow( void )
{
	return;
}

AWindow::AWindow( int x, int y, int w, int h , std::string type):
	_x( x ), _y( y ), _w( w ), _h( h ), _type(type)
{
	return;
}

AWindow::AWindow( AWindow const &rhs )
{
	*this = rhs;
	return;
}

AWindow::~AWindow( void )
{
	return;
}

// ############################## OPERATOR OVERLOAD ############################

AWindow	&AWindow::operator=( AWindow const &rhs )
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_w = rhs.getW();
	this->_h = rhs.getH();
	return *this;
}

// ############################## MEMBER FUNCTIONS #############################

// ############################## GETTERS // SETTERS ###########################

int		AWindow::getX( void ) const { return this->_x; }
int		AWindow::getY( void ) const { return this->_y; }
int		AWindow::getW( void ) const { return this->_w; }
int		AWindow::getH( void ) const { return this->_h; }

void	AWindow::setX( int x ) { this->_x = x; }
void	AWindow::setY( int y ) { this->_y = y; }
void	AWindow::setW( int w ) { this->_w = w; }
void	AWindow::setH( int h ) { this->_h = h; }

std::string		AWindow::getType( void ) const { return this->_type; }
void	AWindow::setType( std::string type ) { this->_type = type; }
