/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SessionModule.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:34:09 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 16:45:10 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SESSIONMODULE_CLASS_HPP
#define SESSIONMODULE_CLASS_HPP

#include "AMonitorModule.class.hpp"
#include "AWindow.class.hpp"
#include "AText.class.hpp"
#include <unistd.h>
#include <cstdlib>

class	SessionModule : public AMonitorModule
{
	private:
		std::string		_data;
		SessionModule(void);

	protected:
		AText	*_display;

	public:
		SessionModule(AWindow *win);
		virtual SessionModule	&operator=(SessionModule const &rhs);

		virtual void	acquireData(void);
		virtual void	displayRender(void);

};

#endif
