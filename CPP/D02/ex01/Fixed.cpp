/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 18:49:59 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/17 18:50:01 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ): _RawBits( 0 ) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( int n ) {
	std::cout << "Int constructor called" << std::endl;
	int i = roundf(n * (1 << this->_Nbits));
	this->_RawBits = i;
	return;
}

Fixed::Fixed( float f ) {
	std::cout << "Float constructor called" << std::endl;
	int n = roundf( f * (1 << this->_Nbits) );
	this->_RawBits = n;
	return;
}

Fixed::Fixed( Fixed const &rhs ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
	return;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed	&Fixed::operator=( Fixed const &rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_RawBits = rhs.getRawBits();
	return *this;
}

std::ostream	&operator<<( std::ostream &o, Fixed const &rhs ) {
	float f = rhs.toFloat();
	o << f;
	return o;
}

int		Fixed::toInt( void ) const {
	int		n = this->_RawBits / (1 << this->_Nbits);
	return n;
}

float	Fixed::toFloat( void ) const {
	float	f = float(this->_RawBits) / (1 << this->_Nbits);
	return f;
}

int		Fixed::getRawBits( void ) const {
	return this->_RawBits;
}

void	Fixed::setRawBits( int const raw ) {
	this->_RawBits = raw;
	return;
}
