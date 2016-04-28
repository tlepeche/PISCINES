/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:48:12 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/23 17:17:29 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter() {}

Converter::Converter(Converter & src) { (void)src; }

Converter::Converter(char *str) : _str(str) {
}

Converter::~Converter() {
}

Converter &	Converter::operator=(Converter const & rhs) {
	(void)rhs;
	return *this;
}

Converter::operator char(void) {
	try
	{
		int		i;
		char c;

		i = *this;
		c = static_cast<char>(i);
		if (std::isprint(c))
			return c;
		else
			throw Converter::PrintException();
	}
	catch (Converter::PrintException &e)
	{
		throw Converter::PrintException();
	}
	catch (std::exception & e)
	{
		throw Converter::UncastException();
	}
}

Converter::operator int(void) {
	try
	{
		int		i;

		i = std::stoi(this->_str);
		return i;
	}
	catch (std::exception & e)
	{
		if (this->_str.size() == 1 && std::isprint(this->_str[0]))
		{
			int		i;

			i = static_cast<int>(this->_str[0]);
			return i;
		}
		else
			throw Converter::UncastException();
	}
}

Converter::operator double(void) {
	try
	{
		double		d;

		d = std::stod(this->_str);
		return d;
	}
	catch (std::exception & e)
	{
		if (this->_str.size() == 1 && std::isprint(this->_str[0]))
		{
			double	d;

			d = static_cast<double>(this->_str[0]);
			return d;
		}
		else
			throw Converter::UncastException();
	}
}

Converter::operator float(void) {
	try
	{
		float 		f;

		f = std::stof(this->_str);
		return f;
	}
	catch (std::exception & e)
	{
		if (this->_str.size() == 1 && std::isprint(this->_str[0]))
		{
			float	f;

			f = static_cast<float>(this->_str[0]);
			return f;
		}
		else
			throw Converter::UncastException();
	}
}
