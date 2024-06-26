/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:54:49 by bastienverd       #+#    #+#             */
/*   Updated: 2024/06/26 16:12:57 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		std::string	GetFirstName(void) const;
		std::string	GetLastName(void) const;
		std::string	GetNickname(void) const;
		std::string	GetPhoneNumber(void) const;
		std::string	GetDarkestSecret(void) const;

		void	SetFirstName(const std::string firstName);
		void	SetLastName(const std::string lastName);
		void	SetNickname(const std::string nickname);
		void	SetPhoneNumber(const std::string phoneNumber);
		void	SetDarkestSecret(const std::string darkestSecret);
};
