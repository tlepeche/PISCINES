/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 12:25:32 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 13:51:24 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

class AWeapon
{
	public:
			AWeapon(std::string const & name, int apcost, int damage);
			AWeapon(AWeapon & src);
			virtual ~AWeapon(void);

			std::string getName() const;
			int getAPCost() const;
			int getDamage() const;
			virtual void attack() const = 0;

			AWeapon &	operator=(AWeapon const  & rhs);

	protected:
			AWeapon(void);

			std::string 		_Name;
			int					_AP;
			int					_Dmg;
};

#endif
