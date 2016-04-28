/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:15:05 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 19:22:20 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_CLASS_HPP
#define IMONITORDISPLAY_CLASS_HPP

class IMonitorDisplay
{
	private:
	protected:
	public:
		virtual void	displayRender(void) = 0;
};

#endif
