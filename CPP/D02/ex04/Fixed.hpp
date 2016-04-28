/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:46:02 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/17 18:20:20 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(int const nb);
		Fixed(float const nb);
		~Fixed(void);

		Fixed &	operator=(Fixed const & rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator<(Fixed const rhs);		
		bool	operator>(Fixed const rhs);		
		bool	operator<=(Fixed const rhs);		
		bool	operator>=(Fixed const rhs);		
		bool	operator==(Fixed const rhs);		
		bool	operator!=(Fixed const rhs);		
		Fixed	operator+(Fixed const rhs) const;
		Fixed	operator-(Fixed const rhs) const;
		Fixed	operator*(Fixed const rhs) const;
		Fixed	operator/(Fixed const rhs) const;
		Fixed &	operator++(void);
		Fixed	operator++(int);
		Fixed &	operator--(void);
		Fixed	operator--(int);

		static const Fixed &	min(Fixed const & lhs, Fixed const & rhs);
		static Fixed &	min(Fixed & lhs, Fixed & rhs);
		static const Fixed &	max(Fixed const & lhs, Fixed const & rhs);
		static Fixed &	max(Fixed & lhs, Fixed & rhs);


	private:
		int					_RawBits;
		static const int	_Nbits = 8;

};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);
#endif
