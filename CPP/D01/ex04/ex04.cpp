/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 14:48:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 14:52:46 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string bob = "HI THIS IS BRAIN";
	std::string *bob_pt = &bob;
	std::string &bob_ref = bob;

	std::cout << "pointer: " << *bob_pt << std::endl;
	std::cout << "reference: " << bob_ref << std::endl;
	return 0;
}
