/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bckgd.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:36:11 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/20 15:28:08 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BCKGD_HPP
# define BCKGD_HPP

class Bckgd
{
	public:
		Bckgd(int, int);
		~Bckgd( void );

		void	refresh( void );

		int		getTab( int ) const;
		int		getLen( void ) const;
		int		getY( void ) const;

	private:
		Bckgd( void );
		Bckgd( Bckgd &rhs );
		Bckgd &operator=( Bckgd const &rhs );
		int		*_Tab;
		int		_Len;
		int		_Ymax;
};

#endif
