/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 17:25:30 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 18:15:46 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	char	line[1024];

	if (ac == 4)
	{
		std::ifstream file(av[1]);
		if (file.fail())
		{
			std::cout << "File Error" << std::endl;
			return 0;
		}
		std::string search = av[2];
		std::string replacing = av[3];
		std::string file_name = av[1];
		file_name += ".replace";
		std::ofstream new_file(file_name);
		while (file.getline(line, 1024))
		{
			std::string new_line = line;
			size_t pos = new_line.find(search);
			if (pos <= new_line.size())
				new_line.replace(new_line.find(search), search.size(), replacing);
			new_file << new_line << std::endl;
		}
	}
	else
		std::cout << "Usage : <filename> <search string> <replacing string>" << std::endl;
	return 0;
}
