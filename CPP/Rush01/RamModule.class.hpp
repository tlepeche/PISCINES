/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:34:09 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 20:20:16 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_CLASS_HPP
#define RAMMODULE_CLASS_HPP

#include "AMonitorModule.class.hpp"
#include "AWindow.class.hpp"
#include "CourbeNCurses.class.hpp"
#include "CourbeSfml.class.hpp"
#include <unistd.h>
#include <cstdlib>
#include "TextSfml.class.hpp"
#include "TextNCurses.class.hpp"
#include <list>

class	RamModule : public AMonitorModule
{
	private:
		std::list<float>	_TRam;
		std::list<float>	_CRam;
		std::string			_name;
		RamModule(void);

	protected:
		ACourbe	*_display;
		AText	*_nameDisplay;

	public:
		RamModule(AWindow *win);
		virtual RamModule	&operator=(RamModule const &rhs);

		virtual void	acquireData(void);
		virtual void	displayRender(void);
};

long long       bytes_to_mb(long long bytes);

#endif
