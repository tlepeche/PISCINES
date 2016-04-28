/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:36:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 20:17:43 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"


OfficeBlock::OfficeBlock() : _i(NULL), _s(NULL), _e(NULL) {}

OfficeBlock::OfficeBlock(OfficeBlock & src)  {(void)src;}

OfficeBlock::~OfficeBlock() {}

OfficeBlock &	OfficeBlock::operator=(OfficeBlock const & rhs) {
	(void)rhs;
	return *this;
}

/// SETTERS ///
void		OfficeBlock::setIntern(Intern *I) {	this->_i = I; }	
void		OfficeBlock::setIntern(Intern &I) {	this->_i = &I;}	
void		OfficeBlock::setSigner(Bureaucrat *S) {	this->_s = S;}
void		OfficeBlock::setSigner(Bureaucrat &S) {	this->_s = &S;}
void		OfficeBlock::setExecutor(Bureaucrat *E) { this->_e = E;}
void		OfficeBlock::setExecutor(Bureaucrat &E) { this->_e = &E;}

/// GETTERS ///
Bureaucrat	*OfficeBlock::getSigner(void) const { return this->_s; }
Bureaucrat	*OfficeBlock::getExecutor(void) const { return this->_e; }

/// FUNCTIONS ///
void	OfficeBlock::doBureaucracy(std::string fName, std::string target) {
	Form	*A;
	if (this->_i != NULL)
	{
		if (this->_s != NULL)
		{
			if (this->_e != NULL)
			{
				A = this->_i->makeForm(fName, target);
				this->_s->signForm(*A);
				this->_e->executeForm(*A);
			}
			else
				throw OfficeBlock::NoExecutor();
		}
		else
			throw OfficeBlock::NoSigner();
	}
	else
		throw OfficeBlock::NoIntern();
}
