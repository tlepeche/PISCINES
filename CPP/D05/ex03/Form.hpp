/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:29:27 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/23 19:31:35 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;
# include <sstream>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include <fstream>

class Form
{
	public:
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ return ("Grade too high!");}
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ return ("Grade too low!");}
		};
		class	NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ return ("Form not signed!");}
		};

		Form(std::string name, int Sgrade, int Egrade);
		Form();
		Form(Form & src);
		~Form();

		Form &	operator=(Form const & rhs);

		std::string	getName(void) const;
		int			getSGrade(void) const;
		int			getEGrade(void) const;
		bool		getSign(void) const;

		void				beSigned(Bureaucrat const & bob);
		virtual void		execute(Bureaucrat const & executor) const = 0;

	private:
		std::string const	_name;
		bool				_sign;
		int const			_signGrade;
		int	const			_execGrade;

};

std::ostream & 	operator<<(std::ostream & lhs, Form const & rhs);

#endif
