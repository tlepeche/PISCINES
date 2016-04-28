/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorModule.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:06:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 16:43:03 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMONITORMODULE_CLASS_HPP
#define AMONITORMODULE_CLASS_HPP

#include <iostream>
#include "IMonitorModule.class.hpp"
#include "AWindow.class.hpp"

class AMonitorModule : public IMonitorModule
{
	private:
	protected:
		bool				_die;
		std::string			_name;
		AWindow				*_win;

	public:
		virtual ~AMonitorModule(void);
		AMonitorModule(std::string name, AWindow *win);

		AMonitorModule(IMonitorModule const &rhs);

		std::string		getName(void) const;
		virtual bool	isDie(void);
};

#endif

