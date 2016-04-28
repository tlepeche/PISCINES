/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AText.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:30:27 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/27 16:41:24 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATEXT_CLASS_HPP
#define ATEXT_CLASS_HPP

#include "AMonitorDisplay.class.hpp"

class AText : public AMonitorDisplay {
	private:
	protected:
		std::string		_data;
	public:
		AText(void);
		void		acquireData(std::string data);
};

#endif
