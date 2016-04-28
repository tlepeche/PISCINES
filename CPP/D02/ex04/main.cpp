/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/20 16:38:31 by edelangh          #+#    #+#             */
/*   Updated: 2015/06/17 21:38:18 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Fixed.hpp"

Fixed		operation(std::string op, std::string & str2)
{
	float	lhs;
	float	rhs;
	int		len1;
	int		len2;
	int		i;
	Fixed	res;

	i = 1;
	len1 = str2.find(op);
	len2 = str2.find(op);
	while (('0' <= str2[str2.find(op) - i] && str2[str2.find(op) - i] <= '9') || str2[str2.find(op) - i] == '.')
		i++;
	len1 -= i - 1;
	lhs = std::stof(str2.substr(len1, str2.find(op)));
	i = 1;
	while (('0' <= str2[str2.find(op) + i] && str2[str2.find(op) + i] <= '9') || str2[str2.find(op) + i] == '.')
		i++;
	len2 += i - 1;
	rhs = std::stof(str2.substr(str2.find(op) + 1, len2));
	std::stringstream stream;
	std::string replacing;
	if (op == "+")
		res = Fixed(rhs) + Fixed(lhs);
	else if (op == "-")
		res = Fixed(rhs) - Fixed(lhs);
	else if (op == "*")
		res = Fixed(rhs) * Fixed(lhs);
	else if (op == "/")
		res = Fixed(rhs) / Fixed(lhs);
	stream << res.toFloat();
	stream >> replacing;
	str2.replace(len1, len2 - len1, replacing);
	return res;
}

Fixed		check_operation(std::string & str2)
{
	Fixed res;

	while (str2.find("*")!= str2.npos || str2.find("/")!= str2.npos ||
			str2.find("+")!= str2.npos || str2.find("-")!= str2.npos)
	{
		if (str2.find("*")!= str2.npos)
			res = operation("*", str2);
		else if (str2.find("/")!= str2.npos)
			res = operation("/", str2);
		else if (str2.find("+")!= str2.npos)
			res = operation("+", str2);
		else if (str2.find("-")!= str2.npos)
			res = operation("-", str2);
	}
	return res;
}

Fixed		split_str(std::string & str)
{
	std::string str2;
	std::string str3;
	size_t len;
	Fixed	res;

	str2 = str.substr(str.find("(") + 1, str.find(")") - 1);
	len = str2.size();
	if (str2.find("(")!= str.npos)
		split_str(str2);
	else
		res = check_operation(str2);
	str.replace(str.find(str.substr(str.find("(") + 1, str.find(")") - 1)), len, str2);
	return res;
}

void		eval_expr(char *expr)
{
	std::string	str = expr;
	Fixed res;

	while (str.find(" ") != str.npos)
		str = str.erase(str.find(" "), 1);
	while (str.find("*")!= str.npos || str.find("/")!= str.npos ||
			str.find("+")!= str.npos || str.find("-")!= str.npos)
	{
		if (str.find("(")!= str.npos)
		{
			res = split_str(str);
			str.erase(str.find("("), 1);
			str.erase(str.find_last_of(")"), 1);
		}
		else
			res = check_operation(str);
	}
	std::cout << res << std::endl;
	return ;
}

int		main(int ac, char **av)
{
	if (ac == 2)
		eval_expr(av[1]);
	else
		std::cout << "Usage <expr>" << std::endl;
	return 0;
}
