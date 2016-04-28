/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 23:48:12 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/20 00:09:34 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character(std::string);
		Character(Character &);
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m); 
		virtual void unequip(int idx);
		virtual void use(int idx, Character& target);

	private:
		Character();
		std::string	_Name;
		AMateria	*_Got[4];
};

#endif
