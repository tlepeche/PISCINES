/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MenuStart.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 03:21:11 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/21 04:25:47 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENUSTART_H
# define MENUSTART_H

# include "ncurses.h"

class MenuStart
{
	public:

		MenuStart( void );
		~MenuStart( void );

		void	display( void );
		int		mainLoop( void );

	private:

		int	_select;

		MenuStart( MenuStart const &rhs );
		
		MenuStart &operator=( MenuStart const &rhs );

};

#endif
