/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <tiboitel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 22:45:49 by tiboitel          #+#    #+#             */
/*   Updated: 2015/06/28 20:21:38 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.class.hpp"
#include "TextNCurses.class.hpp"
#include "CourbeNCurses.class.hpp"
#include "TextSfml.class.hpp"
#include "CourbeSfml.class.hpp"
#include <fstream>

NetworkModule::NetworkModule(void) : AMonitorModule("NetworkModule", NULL) {
}

NetworkModule::NetworkModule(AWindow *win) : AMonitorModule("NetworkModule", win) {
	if (win->getType() == "ncurses")
	{
		this->_nameDisplay = new TextNCurses(reinterpret_cast<WindowNCurses *>(win));
		this->_display = new CourbeNCurses(reinterpret_cast<WindowNCurses *>(win));
	}
	else
	{
		this->_nameDisplay = new TextSfml(reinterpret_cast<WindowSfml *>(win));
		this->_display = new CourbeSfml(reinterpret_cast<WindowSfml *>(win));
	}
	_imax = 200;
	_omax = 200;
	_secSmooth = 10;
	_lenght = 60;

}

NetworkModule	&NetworkModule::operator=(NetworkModule const &rhs) {
	this->_imax = rhs._imax;
	return (*this);
}

void	NetworkModule::acquireData(void) 
{
	char				name[32];
	int					mib[6];
	char				*buffer = NULL, *lim, *next;
	size_t				lenght;
	struct if_msghdr	*ifm;
	unsigned int		ifindex = 0;
	char				interface[4] = "en0";
	
	ifindex = if_nametoindex(interface);
	mib[0] = CTL_NET;
	mib[1] = PF_ROUTE;
	mib[2] = 0;
	mib[3] = 0;
	mib[4] = NET_RT_IFLIST2;
	mib[5] = 0;
	std::ofstream file("debug.txt", std::ios::out | std::ios::trunc);
	if (sysctl(mib, 6, NULL, &lenght, NULL, 0) < 0)
		return ;
	if ((buffer = new char[lenght]) == NULL)
		return ;
	if (sysctl(mib, 6, buffer, &lenght, NULL, 0) < 0)
		return ;
	lim = buffer + lenght;
	for (next = buffer; next < lim;)
	{
		ifm = reinterpret_cast<struct if_msghdr *>(next);
		next += ifm->ifm_msglen;
		if (ifm->ifm_type == RTM_IFINFO2)
		{
			struct if_msghdr2	*if2m = reinterpret_cast<struct if_msghdr2 *>(ifm);
			struct sockaddr_dl	*socketaddr_dl = reinterpret_cast<struct sockaddr_dl *>(if2m + 1);
			strncpy(name, socketaddr_dl->sdl_data, socketaddr_dl->sdl_len);
			name[socketaddr_dl->sdl_nlen] = 0;
			if (if2m->ifm_index != ifindex)
				continue;
			_outPackets= if2m->ifm_data.ifi_opackets;
			_inPackets = if2m->ifm_data.ifi_ipackets;
			_outBytes = if2m->ifm_data.ifi_obytes;
			_inBytes = if2m->ifm_data.ifi_ibytes;
		}
	}
	_inBytesSec.push_front(_inBytes);
	_outBytesSec.push_front(_outBytes);
	_inPacketsSec.push_front(_inPackets);
	_outPacketsSec.push_front(_outPackets);
	_sec.push_front(time(NULL));
	if (_inBytesSec.size() > _secSmooth)
	{
		_inBytesSec.pop_back();
		_outBytesSec.pop_back();
		_inPacketsSec.pop_back();
		_outPacketsSec.pop_back();
		_inBytesSec.pop_back();
	}
	if (_sec.front() - _sec.back() > 0)
	{
		_inBytesGraph.push_front((_inBytesSec.front() - _inBytesSec.back()) / (_sec.front() - _sec.back()));
		_outBytesGraph.push_front((_outBytesSec.front() - _outBytesSec.back()) / (_sec.front() - _sec.back()));
		if (_inBytesGraph.front() > _imax)
			_imax = _inBytesGraph.front();
		if (_outBytesGraph.front() > _omax)
			_omax = _outBytesGraph.front();
	}
	if (_inBytesGraph.size() > static_cast<unsigned int>(_lenght))
	{
		_inBytesGraph.pop_back();
		_outBytesGraph.pop_back();
	}
	if (buffer)
		delete buffer;
	this->_nameDisplay->acquireData("Network bytes :");
	this->_display->acquireData(_inBytesGraph, _outBytesGraph);
	file.close();
}

void	NetworkModule::displayRender(void) {
	this->_nameDisplay->displayRender();
	this->_display->displayRender();
}
