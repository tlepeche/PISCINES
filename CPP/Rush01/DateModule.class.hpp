/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:34:09 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 16:55:35 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATEMODULE_CLASS_HPP
#define DATEMODULE_CLASS_HPP

#include "AMonitorModule.class.hpp"
#include "AWindow.class.hpp"
#include "AText.class.hpp"
#include <iomanip>
#include <ctime>
#include <sstream>

class	DateModule : public AMonitorModule
{
	private:
		std::string		_data;

	protected:
				AText	*_display;

	public:
		DateModule(void);
		DateModule(AWindow *win);
		DateModule	&operator=(DateModule const &rhs);

		virtual void	acquireData(void);
		virtual void	displayRender(void);
};

#endif
