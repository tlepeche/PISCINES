/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 14:16:20 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/24 15:47:34 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T, typename U, typename V>
void	iter(T **array, U const & len, V f(T*)) {
	U	i = 0;

	while (i < len)
	{
		f(&(*array)[i]);	
		i++;
	}
}

template <typename T>
void	inc(T *x) {
	*x = *x + 1;
	return ;
}

int main()
{
	char	*tab_c = new char[4];
	int		*tab_i = new int[4];
	float	*tab_f = new float[4];

	int	i = 0;
	std::cout << "     | char| int |float|" << std::endl;
	std::cout << "_____|_____|_____|_____|" << std::endl;
	while (i < 4)
	{
		tab_c[i] = static_cast<char>(i + 65);
		tab_i[i] = i;
		tab_f[i] = static_cast<float>(i) / 10;
		std::cout << "  " << i << "  |  "
			<< tab_c[i] << "  |  "
			<< tab_i[i];
		if (i == 0)
			std::cout << "  |  " << tab_f[i] << "  |" << std::endl;
		else
			std::cout  << "  | " << tab_f[i] << " |" << std::endl;
		i++;
	}
	iter(&tab_c, 4, &(inc<char>));
	iter(&tab_i, 4, &(inc<int>));
	iter(&tab_f, 4, &(inc<float>));

	std::cout << std::endl;
	std::cout << "     | char| int |float|" << std::endl;
	std::cout << "_____|_____|_____|_____|" << std::endl;
	i = 0;
	while (i < 4)
	{
		std::cout << "  " << i << "  |  "
			<< tab_c[i] << "  |  "
			<< tab_i[i];
		if (i == 0)
			std::cout << "  |  " << tab_f[i] << "  |" << std::endl;
		else
			std::cout  << "  | " << tab_f[i] << " |" << std::endl;
		i++;
	}
	return 0;
}
