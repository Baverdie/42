/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:47:32 by bastienverd       #+#    #+#             */
/*   Updated: 2024/06/26 16:18:08 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

/* ################ GETTERS ################ */

std::string	Contact::GetFirstName(void) const {
	return _firstName;
}

std::string	Contact::GetLastName(void) const {
	return _lastName;
}

std::string	Contact::GetNickname(void) const {
	return _nickname;
}

std::string	Contact::GetPhoneNumber(void) const {
	return _phoneNumber;
}

std::string	Contact::GetDarkestSecret(void) const {
	return _darkestSecret;
}

/* ################ SETTERS ################ */

void	Contact::SetFirstName(const std::string newFirstName) {
	_firstName = newFirstName;
}

void	Contact::SetLastName(const std::string newLastName) {
	_lastName = newLastName;
}

void	Contact::SetNickname(const std::string newNickname) {
	_nickname = newNickname;
}

void	Contact::SetPhoneNumber(const std::string newPhoneNumber) {
	_phoneNumber = newPhoneNumber;
}

void	Contact::SetDarkestSecret(const std::string newDarkestSecret) {
	_darkestSecret = newDarkestSecret;
}