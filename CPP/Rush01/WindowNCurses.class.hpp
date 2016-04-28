/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WindowNCurses.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:29:40 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/27 16:22:44 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOWNCURSES_CLASS_HPP
# define WINDOWNCURSES_CLASS_HPP

# include "AWindow.class.hpp"

# include <ncurses.h>

class WindowNCurses: public AWindow
{

	public:

		WindowNCurses( int x, int y, int w, int h );

		virtual void	init( void );
		virtual void	close( void );

		WINDOW	*getWindow( void ) const;

	private:

		WINDOW	*_win;

};

#endif
