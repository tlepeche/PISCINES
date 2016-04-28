/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 14:04:14 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/15 18:16:45 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_CLASS_HPP
# define ADD_CLASS_HPP

#include "phone.h"

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void init(void);

		std::string	getFname(void) const;
		std::string	getLname(void) const;
		std::string	getNick(void) const;
		std::string	getLog(void) const;
		std::string	getMail(void) const;
		std::string	getEmail(void) const;
		std::string	getPhone(void) const;
		std::string	getBirth(void) const;
		std::string	getMeal(void) const;
		std::string	getPant(void) const;
		std::string	getSecr(void) const;

		static int	nbCont;

	private:
		std::string		_buff;
		std::string		_fname;
		std::string		_lname;
		std::string		_nick;
		std::string		_log;
		std::string		_mail;
		std::string		_email;
		std::string		_phone;
		std::string		_birth;
		std::string		_meal;
		std::string		_pant;
		std::string		_secr;
		
		void		_askFname(void);
		void		_askLname(void);
		void		_askNick(void);
		void		_askLog(void);
		void		_askMail(void);
		void		_askEmail(void);
		void		_askPhone(void);
		void		_askBirth(void);
		void		_askMeal(void);
		void		_askPant(void);
		void		_askSecr(void);

};

#endif
