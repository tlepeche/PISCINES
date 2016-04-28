/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 10:35:41 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 12:03:05 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
#define VICTIM_HPP

class Victim
{
	public:
		Victim(std::string name);
		Victim(Victim & src);
		~Victim(void);

		Victim & operator=(Victim const & rhs);

		std::string	getName(void) const;

		void		setName(std::string name);

		std::string	introduce(void) const;
		virtual void		getPolymorphed(void) const;

	protected:
		Victim(void);
		std::string	_Name;
};

std::ostream	&operator<<(std::ostream & lhs, Victim const & rhs);
#endif
