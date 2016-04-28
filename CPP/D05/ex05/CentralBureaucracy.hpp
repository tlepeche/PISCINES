/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:29:27 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 20:12:28 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_HPP
#define CENTRALBUREAUCRACY_HPP
/*
# include <iostream>
# include <stdexcept>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"
# include "Intern.hpp"
*/
# include "OfficeBlock.hpp"

class CentralBureaucracy
{
	public:
		CentralBureaucracy();
		~CentralBureaucracy();


		void		feed(Bureaucrat *Bob);
		void		feed(Bureaucrat &Bob);

		void		doBureaucracy();
		void		queueUp(std::string target);

		class	Full : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ return ("Central Bureaucracy is full.");}
		};

	private:
		CentralBureaucracy &	operator=(CentralBureaucracy const & rhs);
		CentralBureaucracy(CentralBureaucracy & src);
		OfficeBlock		*_ob[20];
		std::string		*_queue;
		int				_qLen;
};

#endif
