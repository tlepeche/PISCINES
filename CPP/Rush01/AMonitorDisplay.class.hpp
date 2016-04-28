/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorDisplay.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:20:34 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 16:41:07 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMONITORDISPLAY_CLASS_HPP
#define AMONITORDISPLAY_CLASS_HPP

#include <iostream>
#include "IMonitorDisplay.class.hpp"

class AMonitorDisplay : public IMonitorDisplay
{
	private:
	protected:
		std::string	_name;

	public:
		AMonitorDisplay(void);
		~AMonitorDisplay(void);

		AMonitorDisplay(std::string name);
		AMonitorDisplay(AMonitorDisplay const &rhs);
		AMonitorDisplay &operator=(AMonitorDisplay const &rhs);

		std::string		getName(void) const;
};

#endif
