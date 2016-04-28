/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:36:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 20:33:23 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("PPF", 25, 5), _target(target){
		if (Form::getSGrade() > 150 || Form::getEGrade() > 150)
			throw PresidentialPardonForm::GradeTooLowException();
		if (Form::getSGrade() <= 0 || Form::getEGrade() <= 0)
			throw PresidentialPardonForm::GradeTooHighException();
	}

/// FUNCTIONS ///
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
		Form::execute(executor);
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
