/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:36:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 14:03:16 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this->_grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	else
		std::cout << "Bureaucrat " << this->_name
		   << " grade " << this->_grade << " created." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat & src) : _name(src.getName()), _grade(src.getGrade()) {
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs) {
	this->_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << this->_name << " grade " << this->_grade << " killed." << std::endl;
}

int				Bureaucrat::getGrade(void) const { return this->_grade; }
std::string		Bureaucrat::getName(void) const { return this->_name; }

void			Bureaucrat::promote(void) {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		std::cout << this->_name << " get promoted." << std::endl;
		this->_grade--;
	}
}

void			Bureaucrat::retrograde(void) {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		std::cout << this->_name << " get retrograded." << std::endl;
		this->_grade++;
	}
}

std::ostream & operator<<(std::ostream & lhs, Bureaucrat const & rhs) {
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return lhs;
}
