/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 13:30:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/18 17:49:45 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int	main(void)
{
	FragTrap	clp("CL4P-TR4P");

	std::srand(time(0));
	clp.vaulthunter_dot_exe("nobody");
	clp.meleeAttack("TORGUE");
	clp.rangedAttack("Roland");
	clp.takeDamage(15);
	clp.vaulthunter_dot_exe("nobody1");
	clp.vaulthunter_dot_exe("nobody2");
	clp.vaulthunter_dot_exe("nobody3");
	clp.vaulthunter_dot_exe("nobody4");
	clp.beRepaired(2);

	std::cout << std::endl << std::endl;

	ScavTrap	sca("ButtStallion");

	sca.meleeAttack("Lilith");
	sca.rangedAttack("Mordekai");
	sca.takeDamage(15);
	sca.challengeNewcomer("Jack");
	sca.challengeNewcomer("Nisha");
	sca.challengeNewcomer("Athena");
	sca.beRepaired(2);

	std::cout << std::endl << std::endl;

	NinjaTrap	test("Kenshin");

	test.meleeAttack("Tina");
	test.rangedAttack("Moxxi");
	test.takeDamage(50);
	test.beRepaired(23);
	test.ninjaShoebox(test);
	test.ninjaShoebox(clp);
	test.ninjaShoebox(sca);

	return 0;
}
