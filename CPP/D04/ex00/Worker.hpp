/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 10:35:41 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 12:09:59 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
#define WORKER_HPP

#include "Victim.hpp"

class Worker : public Victim
{
	public:
		Worker(std::string name);
		Worker(Worker & src);
		~Worker(void);

		Worker & operator=(Worker const & rhs);

		virtual void		getPolymorphed(void) const;

	private:
		Worker(void);
};

#endif
