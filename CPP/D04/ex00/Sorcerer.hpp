/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 10:35:41 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 11:51:29 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include "Victim.hpp"

class Sorcerer
{
	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer & src);
		~Sorcerer(void);

		Sorcerer & operator=(Sorcerer const & rhs);

		std::string	getName(void) const;
		std::string	getTitle(void) const;

		void		setName(std::string name);
		void		setTitle(std::string title);

		std::string	introduce(void) const;
		void		polymorph(Victim const & vic) const;

	private:
		Sorcerer(void);
		std::string	_Name;
		std::string	_Title;
};

std::ostream	&operator<<(std::ostream & lhs, Sorcerer const & rhs);
#endif
