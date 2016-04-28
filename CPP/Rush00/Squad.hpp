/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 15:05:04 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/21 10:50:36 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
#define SQUAD_HPP

class AEntity;
#include "AEntity.hpp"

class Squad
{
	public:
		Squad();
		Squad(Squad & src);
		virtual ~Squad();

		virtual int		 	getCount(void) const;
		virtual AEntity		*getUnit(int i) const;
		virtual	int			getScore() const;

		void				bombEffect( int x, int y);
		void				useBomb( void );
		virtual void		push(AEntity *add);
		virtual void		destroy(AEntity *dead, bool shot);

		int					checkPlayer( AEntity *p );


		static int			_score;
	private:
		
		Squad &	operator=(Squad const &);
		AEntity 			*_ent[15];
		int					_count;
};

#endif
