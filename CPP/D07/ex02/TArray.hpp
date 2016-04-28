/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TArray.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 15:48:55 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/24 17:43:12 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARRAY_HPP
#define TARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	public:

		Array<T>();
		Array<T>(unsigned int const &n);
		Array<T>(Array<T> & src);
		~Array<T>();

		Array & operator=(Array<T> const & rhs);
		T &		 operator[](unsigned int const &i) const;

		unsigned int	size(void);

		class OOBException: public std::exception
		{
			const char * what() const throw()
			{ return "Out Of Bounds";}
		};

	private:
		T				*_array;
		unsigned int	_size;
};

# include "TArray.cpp"

#endif
