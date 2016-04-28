/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MenuTop.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 19:06:35 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/21 00:24:42 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENUTOP_H
# define MENUTOP_H

#include "Squad.hpp"
#include <ncurses.h>

class MenuTop
{

	public:
		MenuTop( void );
		~MenuTop( void );
		void	display(int timer, int life, int bomb);

	private:
		MenuTop( MenuTop const &rhs );
		MenuTop	&operator=( MenuTop const &rhs );
};

#endif
