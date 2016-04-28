/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 10:35:41 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 12:04:14 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
	public:
		Peon(std::string name);
		Peon(Peon & src);
		~Peon(void);

		Peon & operator=(Peon const & rhs);

		virtual void		getPolymorphed(void) const;

	private:
		Peon(void);
};

#endif
