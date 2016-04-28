/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:44:46 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/23 17:13:00 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <stdexcept>
# include <iostream>

class Converter
{
	public:
		Converter(char *str);
		~Converter();

		operator char();
		operator int();
		operator float();
		operator double();

		class UncastException: public std::exception
		{
			public:
				virtual const char * what() const throw()
				{ return "Impossible"; }
		};

		class PrintException: public std::exception
		{
			public:
				virtual const char * what() const throw()
				{ return "Non displayable"; }
		};

	private:
		Converter();
		Converter(Converter & src);

		Converter & operator=(Converter const & rhs);

		std::string	_str;
};

#endif
