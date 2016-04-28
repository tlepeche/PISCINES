/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 10:36:27 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 16:45:45 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_CLASS_HPP
#define IMONITORMODULE_CLASS_HPP

class IMonitorModule
{
	private:
	protected:
	public:
//		virtual IMonitorModule(void) = 0;
//		virtual ~IMonitorModule(void) = 0;
//		virtual IMonitorModule(IMonitorModule const &rhs) = 0;
//		virtual IMonitorModule	&operator=(IMonitorModule const &rhs) = 0;

		virtual void	acquireData(void) = 0;
		virtual void	displayRender(void) = 0;
		virtual bool	isDie(void) = 0;
};

#endif
