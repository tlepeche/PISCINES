/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:32:32 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 21:06:30 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Logger.hpp"

int	main(void)
{
	Logger Log("TEST");
	Log.log("console", "hi everyone!");
	Log.log("file", "test test");
	return 0;
}
