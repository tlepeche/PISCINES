/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 21:15:19 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/23 21:16:08 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Base
{
	public:
		virtual ~Base() {};
};
class A : public Base{};
class B : public Base{};
class C : public Base{};

void	identify_from_pointer(Base *p)
{
	std::cout << "Ptr *p is type ";
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A.";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B.";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C.";
	std::cout << std::endl;
}

void	identify_from_reference(Base &p)
{
	std::cout << "Reference &p is type ";
	try
	{
		p = dynamic_cast<A&>(p);
		std::cout << "A.";
	}
	catch (const std::bad_cast & e)
	{}

	try
	{
		p = dynamic_cast<B&>(p);
		std::cout << "B.";
	}
	catch (const std::bad_cast & e)
	{}

	try
	{
		p = dynamic_cast<C&>(p);
		std::cout << "C.";
	}
	catch (const std::bad_cast & e)
	{}

	std::cout << std::endl;
}

Base	*generate(void)
{
	Base	*gen;
	int	r = std::rand() % 3;

	std::cout << "Base type ";
	if (r == 0)
	{
		gen = new A;
		std::cout << "A";
	}
	else if (r == 1)
	{
		gen = new B;
		std::cout << "B";
	}
	else
	{
		gen = new C;
		std::cout << "C";
	}
	std::cout << " Generated." << std::endl;
	return (gen);
}

int		main(void)
{
	Base        *b;

	srand(time(0));

	int	i = 0;
	while (i < 10)
	{
		b = generate();
		identify_from_pointer(b);
		identify_from_reference(*b);
		if (i != 9)
			std::cout << std::endl;
		delete b;
		i++;
	}

	return (0);
}
