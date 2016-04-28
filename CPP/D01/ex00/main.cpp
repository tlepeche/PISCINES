/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 11:17:15 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 11:27:13 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

void ponyOnTheStack(void)
{
	Pony	AJ = Pony("AppleJack");
	AJ.Dostuff();
}

void	ponyOnTheHeap(void)
{
	Pony	*RD = new Pony("Rainbowdash");
	RD->Dostuff();
	ponyOnTheStack();
	delete RD;
}

int main(void)
{
	ponyOnTheStack();
	std::cout << std::endl;
	ponyOnTheHeap();
	std::cout << std::endl;
	ponyOnTheStack();
	std::cout << std::endl;
	return 0;
}
