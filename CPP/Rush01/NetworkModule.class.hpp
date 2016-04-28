/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <tiboitel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 22:25:14 by tiboitel          #+#    #+#             */
/*   Updated: 2015/06/28 11:55:07 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_CLASS_HPP
#define NETWORKMODULE_CLASS_HPP

#include "AMonitorModule.class.hpp"
#include "AWindow.class.hpp"
#include <iomanip>
#include <ctime>
#include <list>
#include <sstream>

#include <sys/sysctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <net/if_var.h>
#include <net/if_dl.h>
#include <net/if_types.h>
#include <net/if_mib.h>
#include <net/route.h>
#include <netinet/in.h>
#include <netinet/in_var.h>

class	ACourbe;
class	AText;

class	NetworkModule : public AMonitorModule
{
	private:
		u_int64_t				_inBytes;
		u_int64_t				_outBytes;
		u_int64_t				_inPackets;
		u_int64_t				_outPackets;
		std::list<u_int64_t>	_inBytesSec;
		std::list<u_int64_t>	_outBytesSec;
		std::list<u_int64_t>	_inPacketsSec;
		std::list<u_int64_t>	_outPacketsSec;
		unsigned int			_secSmooth;
		std::list<u_int64_t>	_sec;
		int						_lenght;
	//	int				_count;
		unsigned int			_imax;
		unsigned int			_omax;
		std::list<float>		_inBytesGraph;
		std::list<float>		_outBytesGraph;
	protected:
				AText	*_nameDisplay;
				ACourbe	*_display;

	public:
		NetworkModule(void);
		NetworkModule(AWindow *win);
		NetworkModule	&operator=(NetworkModule const &rhs);

		virtual void	acquireData(void);
		virtual void	displayRender(void);
};

#endif
