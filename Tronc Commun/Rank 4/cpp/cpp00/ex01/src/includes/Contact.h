/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:54:49 by bastienverd       #+#    #+#             */
/*   Updated: 2024/06/27 14:21:47 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <string>
#include <iomanip>

#define LENGTH_COLUMNS 10

#define BLACK "\033[30m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

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
