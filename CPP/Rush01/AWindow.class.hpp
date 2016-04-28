/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWindow.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:01:42 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/27 18:40:39 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWINDOW_CLASS_HPP
# define AWINDOW_CLASS_HPP

# include <iostream>

class AWindow
{

	public:

		AWindow( void );
		AWindow( int x, int y, int w, int h, std::string type );
		~AWindow( void );
		
		virtual void	init( void ) = 0;
		virtual void	close( void ) = 0;

		int		getX( void ) const;
		int		getY( void ) const;
		int		getW( void ) const;
		int 	getH( void ) const;

		void	setX( int x );
		void	setY( int y );
		void	setW( int w );
		void	setH( int h );
		
		void	setType( std::string type );
		std::string 	getType( void ) const;

	private:

		AWindow	&operator=( AWindow const &rhs );
		AWindow( AWindow const &rhs );

		int	_x;
		int	_y;
		int	_w;
		int	_h;
		std::string		_type;

};

#endif
