/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:29:27 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 20:17:19 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"
# include "Intern.hpp"

class OfficeBlock
{
	public:
		OfficeBlock();
		~OfficeBlock();

		Bureaucrat	*getSigner(void) const;
		Bureaucrat	*getExecutor(void) const;

		void		setIntern(Intern *I);
		void		setIntern(Intern &I);
		void		setSigner(Bureaucrat *S);
		void		setSigner(Bureaucrat &S);
		void		setExecutor(Bureaucrat *E);
		void		setExecutor(Bureaucrat &E);

		void		doBureaucracy(std::string fName, std::string target);

		class	NoIntern : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ return ("Office Block doesn't have intern");}
		};

		class	NoSigner : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ return ("Office Block doesn't have signer");}
		};

		class	NoExecutor : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ return ("Office Block doesn't have executor");}
		};

	private:
		OfficeBlock &	operator=(OfficeBlock const & rhs);
		OfficeBlock(OfficeBlock & src);
		Intern		*_i;
		Bureaucrat	*_s;
		Bureaucrat	*_e;	

};

#endif
