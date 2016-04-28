/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:25:06 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 14:46:46 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <fstream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	public:
		Character(std::string const & name);
		Character(Character & src);
		~Character();
		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);

		std::string getName() const;
		int			getAP() const;
		AWeapon *	getWeapon() const;

		Character & operator=(Character const &);

	protected:
		Character();
		std::string	_Name;
		int			_AP;
		AWeapon		*_Weap;
};

std::ostream &	operator<<(std::ostream & lhs, Character const & rhs);

#endif
