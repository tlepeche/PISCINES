/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACourbeb.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:30:27 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 18:30:28 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACOURBEB_CLASS_HPP
#define ACOURBEB_CLASS_HPP

#include "AMonitorDisplay.class.hpp"
#include <list>

class ACourbeb : public AMonitorDisplay {
	private:
	protected:
		std::list<float>		_data1;
		std::list<float>		_data2;
		std::list<float>		_data3;
		std::list<float>		_data4;
		int						_y;
	public:
		ACourbeb(void);
		void	acquireData(std::list<float> data1, std::list<float> data2,
		std::list<float> data3, std::list<float> data4);
};

#endif
