/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 17:38:57 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/23 18:45:58 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct	Data
{
	std::string s1;
	int			n;
	std::string s2;
};

void	*serialize (void)
{
	void	*p;
	char	*str = new char[(sizeof(char) * 8 * 2) + sizeof(int)];
	char	*s1 = str;
	int		*n = reinterpret_cast<int *>(str + 8);
	char	*s2 = str + 8 + sizeof(int);

	*n = std::rand();
	int	i = 0;
	while ( i < 8 )
	{
		int c = 0;

		while (isalnum(c) == 0)
			c = (std::rand() % (123 - 48) + 48);
		s1[i] = static_cast<char>(c);

		c = 0;
		while (isalnum(c) == 0)
			c = (std::rand() % (123 - 48) + 48);
		s2[i] = static_cast<char>(c);
		i++;
	}
	p = reinterpret_cast<void *>(str);
	return p;
}

Data	*unserialize(void *raw)
{
	Data *data = new Data;

	char	*s1 = reinterpret_cast<char *>(raw);
	int		*n = reinterpret_cast<int *>(s1 + 8);
	char	*s2 = reinterpret_cast<char *>(s1 + 8 + sizeof(int));

	data->s1.resize(8);
	data->s2.resize(8);
	int i = 0;
	while (i < 8)
	{
		data->s1[i] = s1[i];
		data->s2[i] = s2[i];
		i++;
	}
	data->n = *n;
	return data;
}

int	main(void)
{
	void	*raw;
	Data	*data;
	srand(time(0));

	raw = serialize();
	data = unserialize(raw);
	std::cout << "Serialized: " << reinterpret_cast<char *>(raw) << std::endl;
	std::cout << "s1:         " << data->s1 << std::endl;
	std::cout << "n:          " << data->n << std::endl;
	std::cout << "s2:         " << data->s2 << std::endl;

	delete data;
	return 0;
}
