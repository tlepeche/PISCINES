/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TArray.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 15:55:20 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/24 17:43:10 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "TArray.hpp"
#include <iostream>

template <typename T>
Array< T >::Array(void) : _array(0), _size(0) {}

template <typename T>
Array< T >::Array(unsigned int const &n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array<T> & src) : _array(new T[src.size()]), _size(src.size()) {
	unsigned int i = 0;
	while (i < this->_size)
	{
		this->_array[i] = src[i];
		i++;
	}
}

template <typename T>
Array<T>::~Array (void) {
	delete [] _array;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array<T> const & rhs) {
	unsigned int i = 0;

	this->_array = new T[rhs.size()];
	while (i < this->_size)
	{
		this->_array[i] = rhs[i];
		i++;
	}
	this->_size = rhs.size();
	return *this;
}

template <typename T>
unsigned int	Array<T>::size(void) {
	return this->_size;
}

template <typename T>
T &		Array< T >::operator[](unsigned int const &i) const {
	if (i >= this->_size)
		throw Array<T>::OOBException();
	else
		return (this->_array)[i];
}
