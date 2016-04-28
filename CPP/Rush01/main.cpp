/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 10:25:02 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/28 17:25:24 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "GKrellM.class.hpp"
#include <unistd.h>

# include <chrono>

int			main(int ac, char **av)
{
	GKrellM		*monitor;
	monitor = new GKrellM(ac, av);
	while (42)
	{
		monitor->run();
		usleep(100000);
	}
	return (0);
}
