/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 18:50:15 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/17 18:50:17 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ): _RawBits( 0 ) {
	return;
}

Fixed::Fixed( int n ) {
	int i = roundf(n * (1 << this->_Nbits));
	this->_RawBits = i;
	return;
}

Fixed::Fixed( float f ) {
	int n = roundf( f * (1 << this->_Nbits));
	this->_RawBits = n;
	return;
}

Fixed::Fixed( Fixed const &rhs ) {
	*this = rhs;
	return;
}

Fixed::~Fixed( void ) {
	return;
}

Fixed	&Fixed::operator=( Fixed const &rhs ) {
	this->_RawBits = rhs.getRawBits();
	return *this;
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

/////// OPERATORS ////////
bool	Fixed::operator<(Fixed const rhs) {
	return (this->_RawBits < rhs.getRawBits()) ? true : false;
}

bool	Fixed::operator>(Fixed const rhs) {
	return (this->_RawBits > rhs.getRawBits()) ? true : false;
}

bool	Fixed::operator<=(Fixed const rhs) {
	return (this->_RawBits <= rhs.getRawBits()) ? true : false;
}

bool	Fixed::operator>=(Fixed const rhs) {
	return (this->_RawBits >= rhs.getRawBits()) ? true : false;
}

bool	Fixed::operator==(Fixed const rhs) {
	return (this->_RawBits == rhs.getRawBits()) ? true : false;
}

bool	Fixed::operator!=(Fixed const rhs) {
	return (this->_RawBits != rhs.getRawBits()) ? true : false;
}

Fixed	Fixed::operator+(Fixed const rhs) const {
	return	this->toFloat() + rhs.toFloat();
}

Fixed	Fixed::operator-(Fixed const rhs)  const{
	return	this->toFloat() - rhs.toFloat();
}

Fixed	Fixed::operator*(Fixed const rhs) const {
	return	this->toFloat() * rhs.toFloat();
}

Fixed	Fixed::operator/(Fixed const rhs) const {
	return	this->toFloat() / rhs.toFloat();
}

Fixed &	Fixed::operator++(void) {
	this->_RawBits += 1;
	return 	*this;
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return 	tmp;
}

Fixed &	Fixed::operator--(void) {
	this->_RawBits -= 1;
	return 	*this;
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return 	tmp;
}

///////// NON_MEMBER ///////////
std::ostream	&operator<<( std::ostream &o, Fixed const &rhs ) {
	float f = rhs.toFloat();
	o << f;
	return o;
}

Fixed const & Fixed::min(Fixed const & lhs, Fixed const & rhs) {
	return (lhs.getRawBits() < rhs.getRawBits()) ? lhs : rhs;
}

Fixed & Fixed::min(Fixed & lhs, Fixed & rhs) {
	Fixed & ret = (lhs.getRawBits() < rhs.getRawBits()) ? lhs : rhs;
	return ret;
}

Fixed const & Fixed::max(Fixed const & lhs, Fixed const & rhs) {
	return (lhs.getRawBits() > rhs.getRawBits()) ? lhs : rhs;
}

Fixed & Fixed::max(Fixed & lhs, Fixed & rhs) {
	Fixed & ret = (lhs > rhs) ? lhs : rhs;
	return ret;
}
