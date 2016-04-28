/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 14:54:13 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 16:07:31 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include "Brain.hpp"

class Human
{
	public:
		Human(void);
		~Human(void);
		std::string identify(void);
		Brain &getBrain(void);

	private:
		Brain	_Mybrain;
};

#endif
