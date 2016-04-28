/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:12:20 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 20:38:27 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>

class Logger 
{
	private:
		void logToConsole(std::string str);
		void logToFile(std::string str);
		std::string makeLogEntry(std::string str);

		std::string _file;

	public:
		Logger(std::string file);
		~Logger(void);
		void log(std::string const & dest, std::string const & message);
};

#endif
