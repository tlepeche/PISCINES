/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 11:42:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/18 16:25:50 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap
{
	public:
		ClapTrap &	operator=(ClapTrap const & rhs);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getName(void) const;
		unsigned int	getHP(void) const;
		unsigned int	getHP_max(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getEnergy_max(void) const;
		unsigned int	getLevel(void) const;
		unsigned int	getRatkdmg(void) const;
		unsigned int	getMatkdmg(void) const;
		unsigned int	getArmor(void) const;

		void		setName(std::string name);
		void		setHP(unsigned int hp);
		void		setHP_max(unsigned int hpmax);
		void		setEnergy(unsigned int en);
		void		setEnergy_max(unsigned int enmax);
		void		setLevel(unsigned int lvl);
		void		setRatkdmg(unsigned int atk);
		void		setMatkdmg(unsigned int atk);
		void		setArmor(unsigned int armor);

	protected:
		ClapTrap(std::string name, unsigned int H, unsigned int Hm, unsigned int E, unsigned int Em, 
				unsigned int lvl, unsigned int R, unsigned int M, unsigned int A);
		ClapTrap(ClapTrap const & src);
		ClapTrap(void);
		~ClapTrap(void);

		std::string		_Name;
		unsigned int	_HP;
		unsigned int	_HP_max;
		unsigned int	_Energy;
		unsigned int	_Energy_max;
		unsigned int	_Level;
		unsigned int	_M_atkdmg;
		unsigned int	_R_atkdmg;
		unsigned int	_Armor;
};		

#endif
