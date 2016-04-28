/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 18:34:31 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 19:58:11 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

int main(void)
{
	Human bob;
	bob.action( "melee", "you");
	bob.action ( "ranged", "bird");
	bob.action ("intimidate", "dragon");
	return 0;
}
