/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:36:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 17:22:58 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("MissingNo") {}

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

/// GETTERS ///
int				Bureaucrat::getGrade(void) const { return this->_grade; }
std::string		Bureaucrat::getName(void) const { return this->_name; }

/// FUNCTIONS ///
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

void		Bureaucrat::signForm(Form & f) const {
	if (f.getSign() == true)
		std::cout << this->_name << " connot sign " << f.getName() << " because it's already signed." << std::endl;
	else
	{
		try
		{
			f.beSigned(*this);
			std::cout << this->_name << " signs " << f.getName() << "." << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << this->_name << " cannot sign " << f.getName() << " because " << e.what() << std::endl;
		}
	}
}

void		Bureaucrat::executeForm(Form const & form){
		try
		{
			form.execute(*this);
			std::cout << this->_name << " executes " << form.getName() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << this->_name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
		}
}

std::ostream & operator<<(std::ostream & lhs, Bureaucrat const & rhs) {
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return lhs;
}
