/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:46:00 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/17 15:25:37 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) {
	this->_RawBits = 0;
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src) {
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const nb) {
	this->_RawBits = nb << this->_Nbits;
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const nb) {
	float	tmp = nb;
	int		i = 0;

	this->_RawBits = (int)nb;
	this->_RawBits = this->_RawBits << this->_Nbits;
	while(tmp != (int)tmp)
	{
		tmp *= 10;
		i++;
	}
	tmp = nb;
	tmp -= (int)tmp;
	while (i != 0)
	{
		tmp *= 10;
		i--;
	}
	tmp = roundf(tmp);
	int pow = 2;
	int tmp2 = this->_Nbits;
	while(tmp2 != 1)
	{
		pow *= 2;
		tmp2--;
	}
	while (tmp > pow)
		tmp /= 10;
	this->_RawBits += (int)tmp;
	return ;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & src) {
	std::cout << "Assignation operator called" << std::endl;
	this->_RawBits = src.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const {
	return this->_RawBits;
}

void	Fixed::setRawBits(int const raw) {
	this->_RawBits = raw;
}

float	Fixed::toFloat(void) const {
	int	i;
	int	d;
	float res;

	i = this->_RawBits >> this->_Nbits;
	d = this->_RawBits - (i << this->_Nbits);
	res = d;
	while ((int)res > 0)
		res /= 10;
	res += i;
	return res;
}

int		Fixed::toInt(void) const {
	return (this->_RawBits >> this->_Nbits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
