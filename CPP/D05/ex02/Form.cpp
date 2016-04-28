/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:36:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 17:22:12 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() : _name("MissingForm"), _signGrade(42), _execGrade(42) {}

Form::Form(std::string name, int Sgrade, int Egrade) :
	_name(name), _sign(false), _signGrade(Sgrade), _execGrade(Egrade) {
		if (this->_signGrade > 150 || this->_execGrade > 150)
			throw Form::GradeTooLowException();
		if (this->_signGrade <= 0 || this->_execGrade <= 0)
			throw Form::GradeTooHighException();
		else
			std::cout << "Form " << this->getName() << ", grade for signature:  " << this->getSGrade()
				<< ", grade for exec: " << this->getEGrade() << " created." << std::endl;
	}

Form::Form(Form & src) :
	_name(src.getName()), _sign(src.getSign()), _signGrade(src.getSGrade()), _execGrade(src.getEGrade()) {
	}

Form &	Form::operator=(Form const & rhs) {
	this->_sign = rhs.getSign();
	return *this;
}

Form::~Form() {
	std::cout << "Form " << this->getName() << ", grade for signature:  " << this->getSGrade()
		<< ", grade for exec: " << this->getEGrade() << " destroyed." << std::endl;
}

/// GETTERS ///
std::string		Form::getName(void) const { return this->_name; }
bool			Form::getSign(void) const { return this->_sign; }
int				Form::getSGrade(void) const { return this->_signGrade; }
int				Form::getEGrade(void) const { return this->_execGrade; }

/// FUNCTIONS ///
void			Form::beSigned(Bureaucrat const & bob) {
	if (bob.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_sign = true;
}

std::ostream & operator<<(std::ostream & lhs, Form const & rhs) {
	lhs << "Form " << rhs.getName() << ", grade required for signature: " << rhs.getSGrade()
		<< ", grade required for exec: " << rhs.getEGrade();
	lhs << ((rhs.getSign()) ? " signed."  : " unsigned.");
	return lhs;
}

void		Form::execute(Bureaucrat const & executor) const{
	if (this->_sign == false)
		throw Form::NotSignedException();
	else if (this->_execGrade < executor.getGrade())
		throw Form::GradeTooLowException();
}
