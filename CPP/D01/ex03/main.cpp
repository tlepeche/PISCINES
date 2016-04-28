/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 14:30:33 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 14:47:37 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main(void)
{
	std::srand(time(NULL));
	ZombieHorde *bob = new ZombieHorde(2);
	bob->announce();
	ZombieHorde *bobby = new ZombieHorde(3);
	bobby->announce();
	delete bob;
	ZombieHorde *bobo = new ZombieHorde(6);
	bobo->announce();
	delete bobo;
	delete bobby;
	return 0;
}
