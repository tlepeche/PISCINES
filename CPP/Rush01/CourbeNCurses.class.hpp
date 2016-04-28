/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourbeNCurses.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 11:39:24 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/28 15:05:30 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COURBENCURSES_CLASS_HPP
# define COURBENCURSES_CLASS_HPP

# include "ACourbe.class.hpp"
# include "WindowNCurses.class.hpp"

class CourbeNCurses: public ACourbe
{

	public:

		CourbeNCurses( WindowNCurses *win );
		void	displayRender( void );
		void	displayRender2( void );

	private:

		WindowNCurses	*_win;

};

#endif
