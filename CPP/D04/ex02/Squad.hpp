/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 15:05:04 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 20:09:59 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISquad.hpp"

class Squad : public ISquad
{
	public:
		Squad();
		Squad(Squad & src);
		virtual ~Squad();

		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int) const;
		virtual int push(ISpaceMarine*);
		
		Squad &	operator=(Squad const &);

	private:
		ISpaceMarine *		_Mar;
		Squad *				_Next;
		static int			_Count;
};

#endif
