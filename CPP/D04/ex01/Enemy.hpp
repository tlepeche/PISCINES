/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:05:39 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/19 13:58:03 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy
{
	public:
		Enemy(int hp, std::string const & type);
		Enemy(Enemy & src);
		virtual ~Enemy();

		std::string getType() const;
		int getHP() const;
		virtual void takeDamage(int);

		Enemy & operator=(Enemy const & rhs);

	protected:
		Enemy();
		int			_HP;
		std::string	_Type;
};

#endif
