/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:36:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 20:32:37 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"


CentralBureaucracy::CentralBureaucracy() : _queue(NULL), _qLen(0) {
	int	i = 0;
	Intern Slave;

	while (i < 20)
	{
		this->_ob[i] = new OfficeBlock();
		this->_ob[i]->setIntern(Slave);
		i++;
	}
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy & src)  {(void)src;}

CentralBureaucracy::~CentralBureaucracy() {}

CentralBureaucracy &	CentralBureaucracy::operator=(CentralBureaucracy const & rhs) {
	(void)rhs;
	return *this;
}

/// FUNCTIONS ///
void		CentralBureaucracy::feed(Bureaucrat *Bob) {
	int	i = 0;
	while (i < 20)
	{
		if (this->_ob[i]->getSigner() == NULL)
		{
			this->_ob[i]->setSigner(Bob);
			break;
		}
		if (this->_ob[i]->getExecutor() == NULL)
		{
			this->_ob[i]->setExecutor(Bob);
			break; 
		}
		i++;
	}
	if (i == 20)
		throw CentralBureaucracy::Full();
}

void		CentralBureaucracy::feed(Bureaucrat &Bob) {
	int	i = 0;
	while (i < 20)
	{
		if (this->_ob[i]->getSigner() == NULL)
		{
			this->_ob[i]->setSigner(Bob);
			break;
		}
		if (this->_ob[i]->getExecutor() == NULL)
		{
			this->_ob[i]->setExecutor(Bob);
			break; 
		}
		i++;
	}
	if (i == 20)
		throw CentralBureaucracy::Full();
}

void	CentralBureaucracy::queueUp(std::string target) {
	std::string	*nQueue = new std::string[this->_qLen + 1];
	int	i = 0;

	while (i < this->_qLen)
	{
		nQueue[i] = this->_queue[i];
		i++;
	}
	nQueue[i] = target;
	std::cout << target << " added to queue." << std::endl;
	this->_queue = nQueue;
	this->_qLen++;
}

void	CentralBureaucracy::doBureaucracy(void) {
	int			r;
	std::string	form;
	int ob = 0;
	int queue;

	try
	{
		while (ob < 20)
		{
			queue = 0;
			while (queue < this->_qLen)
			{
				r = std::rand() % 3;
				if (r == 0)
					form = "robotomy request";
				else if (r == 1)
					form = "shrubbery creation";
				else
					form = "presidential pardon";
				this->_ob[ob]->doBureaucracy(form, this->_queue[queue]);
				std::cout << std::endl;
				queue++;
			}			
			std::cout << std::endl;
			ob++;
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
