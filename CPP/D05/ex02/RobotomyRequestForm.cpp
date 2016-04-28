/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:36:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 17:40:17 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("RRF", 72, 45), _target(target){
	if (Form::getSGrade() > 150 || Form::getEGrade() > 150)
		throw RobotomyRequestForm::GradeTooLowException();
	if (Form::getSGrade() <= 0 || Form::getEGrade() <= 0)
		throw RobotomyRequestForm::GradeTooHighException();
	else
	std::cout << "RobotomyRequestForm " << this->getName() << ", grade for signature:  " << this->getSGrade()
		<< ", grade for exec: " << this->getEGrade() << " created." << std::endl;
}

/// FUNCTIONS ///
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
		Form::execute(executor);
		std::cout << "* drilling noise *" << std::endl;
		if (std::rand() % 2 == 0)
			std::cout << this->_target << " has been robotomized successfully." << std::endl;
		else
			std::cout << "Robotomisation failed." << std::endl;
}
