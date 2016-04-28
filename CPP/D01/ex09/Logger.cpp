/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 18:27:16 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 21:16:13 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Logger.hpp"

Logger::Logger(std::string file) : _file(file) {
}

Logger::~Logger(void) {
}

void	Logger::logToConsole(std::string str) {
	std::cout << this->makeLogEntry(str) << std::endl;
}

void	Logger::logToFile(std::string str) {
	this->_file << this->makeLogEntry(str) << std::endl;
}

std::string	Logger::makeLogEntry(std::string str) {
	time_t tps = time(0);
	struct tm *now = localtime (&tps);
	std::string new_str;
	std::stringstream time;
	time << std::put_time(now, "%x") << " " << std::put_time(now, "%X");
	std::string tmp;
	std::string tmp2;
	time >> tmp;
	time >> tmp2;
	new_str = "[" + tmp + " " + tmp2 + "] " + str;
	return new_str;
}

typedef void	(Logger::*f)(std::string);

void	Logger::log(std::string const & action_name, std::string const & str) {
	struct s_choice
	{
		std::string	action;
		f ptr;
	};

	s_choice	list[2];
	list[0].action = "console";
	list[0].ptr = &Logger::logToConsole;
	list[1].action = "file";
	list[1].ptr = &Logger::logToFile;

	int i = 0;
	while (i < 2)
	{
		if (action_name == list[i].action)
		{
			f selected = list[i].ptr;
			(this->*selected)(str);
		}
		i++;
	}
}
