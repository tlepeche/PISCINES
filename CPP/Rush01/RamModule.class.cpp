/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:33:16 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 20:27:40 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.class.hpp"
#include "TextNcurses.class.hpp"
#include "TextSfml.class.hpp"
#include <mach/mach.h>
#include <cstdio>
#include <stdint.h>
#include <unistd.h>
#include <mach/vm_statistics.h>
#include <sys/sysctl.h>
#include <sys/types.h>

RamModule::RamModule(void) : AMonitorModule("RamModule", NULL) {
}

RamModule::RamModule(AWindow *win) : AMonitorModule("RamModule", win) {
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
}

RamModule	&RamModule::operator=(RamModule const &rhs) {
	_display = rhs._display;
	return (*this);
}

void	RamModule::acquireData(void) {
	size_t total = 0;
	size_t size = sizeof(total);
	int	arg[2];
	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	this->_name = "RAM:";
	arg[0] = CTL_HW;
	arg[1] = HW_MEMSIZE;
	sysctl(arg, 2 , &total, &size, NULL, 0);
	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
			KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
				(host_info64_t)&vm_stats, &count))
	{
		long long used_memory = bytes_to_mb((static_cast<long long>(vm_stats.active_count) +
					static_cast<long long>(vm_stats.inactive_count) +
					static_cast<long long>(vm_stats.wire_count)) *  static_cast<int64_t>(page_size));
		long long m_active_ram = bytes_to_mb(static_cast<long long>(vm_stats.active_count) * static_cast<int64_t>(page_size));
		//long long m_inactive_ram = bytes_to_mb(static_cast<long long>(vm_stats.inactive_count * (int64_t)page_size);
		m_active_ram = bytes_to_mb(static_cast<long long>(vm_stats.wire_count) * static_cast<int64_t>(page_size));

		this->_CRam.push_front(static_cast<float>(used_memory + m_active_ram));
		this->_TRam.push_front(static_cast<float>(total/1024/1024));

	if (_TRam.size() > 60)
	{
		this->_CRam.pop_back();
		this->_TRam.pop_back();
	}
		this->_nameDisplay->acquireData(this->_name);
		this->_display->acquireData(this->_CRam, this->_TRam);
	}
}

void	RamModule::displayRender(void) {
	this->_nameDisplay->displayRender();
	this->_display->displayRender();
}

long long       bytes_to_mb(long long bytes)
{
	return (bytes >> 10 >> 10);
}

