/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACourbe.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:30:27 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 12:05:37 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACOURBE_CLASS_HPP
#define ACOURBE_CLASS_HPP

#include "AMonitorDisplay.class.hpp"
#include <list>

class ACourbe : public AMonitorDisplay {
	private:
	protected:
		std::list<float>		_data;
		std::list<float>		_data2;
		int						_y;
	public:
		ACourbe(void);
		void		acquireData(std::list<float> data, std::list<float> data2);
};

#endif
