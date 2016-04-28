/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 20:06:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 20:06:41 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_CLASS_HPP
#define CPUMODULE_CLASS_HPP

#include "AMonitorModule.class.hpp"
#include "AWindow.class.hpp"
#include "CourbebNCurses.class.hpp"
#include "CourbeSfmlb.class.hpp"
#include "TextNCurses.class.hpp"
#include "TextSfml.class.hpp"
#include <list>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "CpuUsage.class.hpp"

class	CpuModule : public AMonitorModule
{
	private:
		std::list<float>		_core1;
		std::list<float>		_core2;
		std::list<float>		_core3;
		std::list<float>		_core4;
		std::string				_name;
		CpuModule(void);
		CpuUsage *yolo1;	
		CpuUsage *yolo2;	
		CpuUsage *yolo3;	
		CpuUsage *yolo4;
	protected:
		ACourbeb	*_display;
		AText		*_nameDisplay;

	public:
		CpuModule(AWindow *win);
		virtual CpuModule	&operator=(CpuModule const &rhs);

		virtual void	acquireData(void);
		virtual void	displayRender(void);
};

#endif
