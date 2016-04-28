/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 14:42:37 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/15 18:22:30 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "phone.h"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::getFname(void) const { return _fname; }
std::string	Contact::getLname(void) const { return _lname; }
std::string	Contact::getNick(void) const { return _nick; }
std::string	Contact::getLog(void) const { return _log; }
std::string	Contact::getMail(void) const { return _mail; }
std::string	Contact::getEmail(void) const { return _email; }
std::string	Contact::getPhone(void) const { return _phone; }
std::string Contact::getBirth(void) const { return _birth; }
std::string	Contact::getMeal(void) const { return _meal; }
std::string	Contact::getPant(void) const { return _pant; }
std::string	Contact::getSecr(void) const { return _secr; }

void	Contact::_askFname(void)
{
	while (42)
	{
		std::cout << "First name: ";
		std::getline (std::cin, this->_buff);
		if (std::cin.fail())
			exit(0);
		else
		{
			if (this->_buff[0] != '\0')
			{
				this->_fname = this->_buff;
				break;
			}
			else
				std::cout << "Bad Value" << std::endl;
		}
	}
}

void	Contact::_askLname(void)
{
	while (42)
	{
		std::cout << "Last name: ";
		std::getline (std::cin, this->_buff);
		if (std::cin.fail())
			exit(0);
		else
		{
			if (this->_buff[0] != '\0')
			{
				this->_lname = this->_buff;
				break;
			}
			else
				std::cout << "Bad Value" << std::endl;
		}
	}
}

void	Contact::_askNick(void)
{
	while (42)
	{
		std::cout << "Nickname: ";
		std::getline (std::cin, this->_buff);
		if (std::cin.fail())
			exit(0);
		else
		{
			if (this->_buff[0] != '\0')
			{
				this->_nick = this->_buff;
				break;
			}
			else
				std::cout << "Bad Value" << std::endl;
		}
	}
}

void	Contact::_askLog(void)
{
	while (42)
	{
		std::cout << "Login: ";
		std::getline (std::cin, this->_buff);
		if (std::cin.fail())
			exit(0);
		else
		{

			if (this->_buff[0] != '\0')
			{
				this->_log = this->_buff;
				break;
			}
			else
				std::cout << "Bad Value" << std::endl;
		}
	}
}

void	Contact::_askMail(void)
{
	while (42)
	{
		std::cout << "Mail adress: ";
		std::getline (std::cin, this->_buff);
		if (std::cin.fail())
			exit(0);
		else
		{
			if (this->_buff[0] != '\0')
			{
				this->_mail = this->_buff;
				break;
			}
			else
				std::cout << "Bad Value" << std::endl;
		}
	}
}

void	Contact::_askEmail(void)
{
	while (42)
	{
		std::cout << "E-mail: ";
		std::getline (std::cin, this->_buff);
		if (std::cin.fail())
			exit(0);
		else
		{
			if (this->_buff[0] != '\0')
			{
				this->_email = this->_buff;
				break;
			}
			else
				std::cout << "Bad Value" << std::endl;
		}
	}
}

void	Contact::_askPhone(void)
{
	while(42)
	{
		std::cout << "Phone number: ";
		std::getline (std::cin, this->_buff);
		if (std::cin.fail())
			exit(0);
		if (this->_buff[0] != '\0')
		{
			this->_phone = this->_buff;
			break;
		}
		else
			std::cout << "Bad Value" << std::endl;
	}
}

void	Contact::_askBirth(void)
{
	while (42)
	{
		std::cout << "Birthday: ";
		std::getline (std::cin, this->_buff);
		if (std::cin.fail())
			exit(0);
		else
		{
			if (this->_buff[0] != '\0')
			{
				this->_birth = this->_buff;
				break;
			}
			else
				std::cout << "Bad Value" << std::endl;
		}
	}
}

void	Contact::_askMeal(void)
{
	while (42)
	{
		std::cout << "Favourite meal: ";
		std::getline (std::cin, this->_buff);
		if (std::cin.fail())
			exit(0);
		else
		{
			if (this->_buff[0] != '\0')
			{
				this->_meal = this->_buff;
				break;
			}
			else
				std::cout << "Bad Value" << std::endl;
		}
	}
}

void	Contact::_askPant(void)
{
	while (42)
	{
		std::cout << "Underwear color: ";
		std::getline (std::cin, this->_buff);
		if (std::cin.fail())
			exit(0);
		else
		{
			if (this->_buff[0] != '\0')
			{
				this->_pant = this->_buff;
				break;
			}
			else
				std::cout << "Bad Value" << std::endl;
		}
	}
}

void	Contact::_askSecr(void)
{
	while (42)
	{
		std::cout << "What's your darkest secret ? ";
		std::getline (std::cin, this->_buff);
		if (std::cin.fail())
			exit(0);
		else
		{
			if (this->_buff[0] != '\0')
			{
				this->_secr = this->_buff;
				break;
			}
			else
				std::cout << "I don't believe you !" << std::endl;
		}
	}
}


void	Contact::init(void)
{
	Contact::nbCont++;
	_askFname();
	_askLname();
	_askNick();
	_askLog();
	_askMail();
	_askPhone();
	_askBirth();
	_askMeal();
	_askPant();
	_askSecr();
}

int	Contact:: nbCont = 1;
