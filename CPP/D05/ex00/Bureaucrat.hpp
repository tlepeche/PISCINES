/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:29:27 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 13:58:57 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <sstream>
#include <iostream>
# include <stdexcept>

class Bureaucrat
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

		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat &	operator=(Bureaucrat const & rhs);

		int			getGrade(void) const;
		std::string	getName(void) const;

		void		promote(void);
		void		retrograde(void);

	private:
		Bureaucrat();
		Bureaucrat(Bureaucrat & src);
		std::string	const	_name;
		int					_grade;

};

std::ostream & 	operator<<(std::ostream & lhs, Bureaucrat const & rhs);

#endif
