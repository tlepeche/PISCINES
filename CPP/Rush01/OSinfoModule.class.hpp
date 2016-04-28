/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSinfoModule.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:34:09 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 16:55:20 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_CLASS_HPP
#define OSINFOMODULE_CLASS_HPP

#include "AMonitorModule.class.hpp"
#include "AWindow.class.hpp"
#include "AText.class.hpp"
#include <sys/utsname.h>

class	OSinfoModule : public AMonitorModule
{
	private:
		std::string		_data;

	protected:
		AText	*_display;

	public:
		OSinfoModule(void);
		OSinfoModule(AWindow *win);
		OSinfoModule	&operator=(OSinfoModule const &rhs);

		virtual void	acquireData(void);
		virtual void	displayRender(void);
};

#endif
