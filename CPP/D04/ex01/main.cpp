/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:04:12 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/20 11:51:12 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Character.hpp"

int main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;

	Enemy* b = new RadScorpion();
	Enemy* c = new SuperMutant();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->recoverAP();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->recoverAP();
	zaz->attack(c);
	zaz->equip(pf);
	std::cout << *zaz;
	zaz->attack(c);
	zaz->attack(c);
	zaz->recoverAP();
	zaz->attack(c);
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;

	return 0;
}
